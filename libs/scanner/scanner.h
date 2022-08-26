#ifndef SCANNER_H
#define SCANNER_H

#include <QtCore/QObject>
#include <QtCore/QDebug>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

#include <time.h>

#include "scannerThread.h"

class Scanner : public QObject
{
    Q_OBJECT
public:
    Scanner();
    ~Scanner();

signals:
    void scan(QString date, QString uid, QString login);
    void log(char *event);

public slots:
    void managerFinished();
    void manageError(QNetworkReply::NetworkError code);
    void scanning();
    void setPort(const char *){};
    void sendUrlRequest(char *uid);
    void stopScan();

private:
    QNetworkAccessManager *manager;
    QNetworkRequest request;

    ScannerThread *scanThread;

    time_t strDate;
    struct tm *timeinfo;

    QString url = "https://extranet1.utbm.fr/gestprod/api/cms/carte/";

    // TODO delete uid
    QStringList uid = {"8072E54A3A4E04",
                       "8072E54A641004",
                       "8072E54A482504",
                       "8072E54A694B04",
                       "8072E54A495604",
                       "8071CF1A294B04",
                       "8072E53A5B2A04",
                       "8072E54A405A04",
                       "8072E5422C3804",
                       "8072E55A292104",
                       "8072E5425C3704",
                       "8072E55A181E04",
                       "8072E54A452504",
                       "8072E55A2F2104",
                       "8072E54A525B04",
                       "8072E542181C04",
                       "8072E5421E1B04",
                       "8072E53A552A04",
                       "8072E542415304",
                       "8072E55A731E04"};
    //    QStringList uid = {"8072E54A3A4E04"
    //                      };
};

#endif // SCANNER_H
