#include "scanner.h"

Scanner::Scanner()
{
    manager = new QNetworkAccessManager();
    scanThread = new ScannerThread("/dev/cu.usbserial-14140");

    connect(scanThread, SIGNAL(getUID(char *)), this, SLOT(sendUrlRequest(char *))); // send url request when an UID is received
}

Scanner::~Scanner()
{
    delete manager;
}

void Scanner::stopScan()
{
    if (scanThread->isRunning())
    {
        emit log("INFO | Stop scan");
        scanThread->terminate();
    }
}

void Scanner::scanning()
{
    if (scanThread != NULL)
    {
        if (!scanThread->isRunning())
        {
            emit log("INFO | Start scan");
            scanThread->start();
        }
        else
            emit log("INFO | Scan is already running");
    }

    else
        printf("ERROR | scanThread not instantiated\n");
}

void Scanner::sendUrlRequest(char *uid)
{
    request.setUrl(QUrl(url + uid)); // url + user_uid
    QNetworkReply *reply = manager->get(request);
    connect(reply, SIGNAL(finished()), this, SLOT(managerFinished()));
    connect(reply, SIGNAL(errorOccurred(QNetworkReply::NetworkError)), this, SLOT(manageError(QNetworkReply::NetworkError)));
}

void Scanner::managerFinished()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    if (reply->error())
    {
        emit log((char *)reply->errorString().toStdString().c_str());
        return;
    }

    QString answer = reply->readAll();

    QJsonDocument jsonResponse = QJsonDocument::fromJson(answer.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();
    QJsonObject jsonObjectPorteur = jsonObject["porteur"].toObject();

    QString login = jsonObjectPorteur["login"].toString();
    QString uid = jsonObject["csn"].toString();

    char buffer[30];

    time(&strDate);
    timeinfo = localtime(&strDate);

    strftime(buffer, 30, "%d/%m/%y,%T", timeinfo);

    std::string date(buffer);

    QString qdate = QString::fromStdString(date);

    emit scan(qdate, uid, login);
    // 
    emit log(answer.toLocal8Bit().data());

    reply->deleteLater();
}

void Scanner::manageError(QNetworkReply::NetworkError code)
{
    switch (code)
    {
    case (QNetworkReply::ConnectionRefusedError):
        emit log("NO NETWORK CONNECTION ConnectionRefusedError!! ");
        break;
    case (QNetworkReply::HostNotFoundError):
        // handle the html output is no internet connection is found
        emit log("NO NETWORK CONNECTION HostNotFoundError!! ");
        break;
    case (QNetworkReply::SslHandshakeFailedError):
        // handle the html output is no internet connection is found
        emit log("CONNECTION SslHandshakeFailedError!! ");
        break;
    case (QNetworkReply::UnknownContentError):
        emit log("CONNECTION UnknownContentError!! ");
        break;
    default:
        emit log("CONNECTION not defined default error UnknownContentError!! ");
    }
}
