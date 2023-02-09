#ifndef DATABASE_H
#define DATABASE_H

#include <QtCore/QObject>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

class Database : public QObject
{
    Q_OBJECT
private:
    QSqlDatabase db;

public:
    Database(/* args */);
    ~Database();

signals:
    void log(char *);
public slots:
    void addStudent(QString date, QString uid, QString login);
};

#endif