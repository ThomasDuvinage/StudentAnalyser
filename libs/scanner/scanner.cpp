#include "scanner.h"

Scanner::Scanner()
{
    manager = new QNetworkAccessManager();
}

Scanner::~Scanner()
{
    delete manager;
}

void Scanner::scanning()
{
    for (const auto &item : uid)
    {
        // qDebug() << url + item;
        request.setUrl(QUrl(url + item)); // url + user_uid
        QNetworkReply *reply = manager->get(request);
        connect(reply, SIGNAL(finished()), this, SLOT(managerFinished()));
        connect(reply, SIGNAL(errorOccurred(QNetworkReply::NetworkError)), this, SLOT(manageError(QNetworkReply::NetworkError)));
    }
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

    strftime(buffer, 30, "%d/%m/%y;%T", timeinfo);

    emit scan(buffer, uid, login);
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
