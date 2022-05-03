#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QWidget>
#include <QFileDialog>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QDebug>
#include <QTextStream>

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
};

class FileManager : public QWidget
{
    Q_OBJECT
public:
    explicit FileManager();

private:
    QString path_import;
    QString path_export;

public slots:
    void importFiles();
    void exportFiles();

    void saveDataToFile(QString data);

signals:
    void errorFile(int error);
};

#endif // FILEMANAGER_H
