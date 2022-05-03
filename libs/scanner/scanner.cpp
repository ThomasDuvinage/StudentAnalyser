#include "scanner.h"

Scanner::Scanner()
{
    manager = new QNetworkAccessManager();
}

void Scanner::scanning(){

    for ( const auto& item : uid  )
    {
        qDebug() << url + item;
        request.setUrl(QUrl(url + item)); // url + user_uid
        QNetworkReply *reply = manager->get(request);
        connect(reply, SIGNAL(finished()), this, SLOT(managerFinished()));
        connect(reply, SIGNAL(errorOccurred(QNetworkReply::NetworkError)), this, SLOT(manageError(QNetworkReply::NetworkError)));
    }

}

void Scanner::managerFinished(){
    qDebug() << "managerFunction";
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if (reply->error()) {
        qDebug() << reply->errorString();
        return;
    }

    QString answer = reply->readAll();

    qDebug() << answer;

    emit scan(answer.toLocal8Bit().data());
    emit log(answer.toLocal8Bit().data());

    reply->deleteLater();
}

void Scanner::manageError(QNetworkReply::NetworkError code){
    qDebug() << "Erreur " << code;
}



