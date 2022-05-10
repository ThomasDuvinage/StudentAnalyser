#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QWidget>
#include <QFileDialog>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QDebug>
#include <QTextStream>

#define SEPARATOR ";"

struct studentInfos
{
    QString last_name;
    QString first_name;
    QString student_id;
    QString no_person;
    QString email;
    QString login;
    QString formation;
    QString level;
    QString uid;
    bool presence;
    QString date_scan;
};

class FileManager : public QWidget
{
    Q_OBJECT
public:
    explicit FileManager(){};

private:
    QString path_import;
    QString path_export;

    QMap<QString, studentInfos> studentsList;

    void saveDataToFile();

public slots:
    void importFiles();
    void exportFiles();

    void updateStudentStatus(char *, QString uid, QString login);

signals:
    void errorFile(int error);
    void log(char *log);
    void addRow(const QStringList &list);
};

#endif // FILEMANAGER_H
