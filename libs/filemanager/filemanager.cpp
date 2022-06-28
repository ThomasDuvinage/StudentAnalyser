#include "filemanager.h"

void FileManager::importFiles()
{
    this->path_import = QFileDialog::getOpenFileName(this, tr("Import listing"), "/home/thomasduvinage/Documents", tr("Listing Files (*.csv)"));

    QFile file(this->path_import);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << file.errorString();
        emit errorFile(0); // impossible to open file
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList infos = line.split(';');

        if (infos.first() != "Nom" && infos.first() != "NOM")
        {
            if (infos.length() == 9)
            {
                studentInfos student;
                student.last_name = infos.at(0);
                student.first_name = infos.at(1);
                student.student_id = infos.at(2);
                student.no_person = infos.at(3);
                student.email = infos.at(4);
                student.login = infos.at(5);
                student.formation = infos.at(6);
                student.level = infos.at(7);
                student.presence = false;

                QString student_login(infos.at(5));

                studentsList.insert(student_login, student);
            }
            else
            {
                qDebug() << "Not enough columns in the file | Detected : " << infos.length();
                emit log("Not enough columns in the file");
                emit errorFile(1); // there are not enough columns in the file
            }
        }
    }

    emit log("FILE IMPORTED WITH SUCESS !");
}

QStringList FileManager::studentToQStringList(const studentInfos &student)
{
    QStringList student_infos_list;
    student_infos_list << student.last_name
                       << student.first_name
                       << student.login
                       << student.formation
                       << student.level;

    return student_infos_list;
}

void FileManager::exportFiles()
{
    this->path_export = QFileDialog::getExistingDirectory(this, tr("Export directory"), "/home/thomasduvinage/Documents", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    saveDataToFile();
}

void FileManager::saveDataToFile()
{
    QString filename_present = "/presents.csv";
    QString filename_abs = "/absents.csv";

    if (!this->path_export.isEmpty())
    {
        QFile file_present(this->path_export + filename_present);
        QFile file_abs(this->path_export + filename_abs);

        QTextStream fout_presents(&file_present);
        QTextStream fout_absents(&file_abs);

        if (file_present.open(QIODevice::WriteOnly | QIODevice::Text) && file_abs.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            for (auto e : studentsList.keys())
            {
                fout_presents.flush();
                studentInfos s = studentsList.value(e);
                if (studentsList.value(e).presence)
                {
                    fout_presents << s.date_scan << SEPARATOR
                                  << s.last_name << SEPARATOR
                                  << s.first_name << SEPARATOR
                                  << s.student_id << SEPARATOR
                                  << s.email << SEPARATOR
                                  << s.login << SEPARATOR
                                  << s.formation << SEPARATOR
                                  << s.level << '\n';
                }
                else
                {
                    fout_absents << s.date_scan << SEPARATOR
                                 << s.last_name << SEPARATOR
                                 << s.first_name << SEPARATOR
                                 << s.student_id << SEPARATOR
                                 << s.email << SEPARATOR
                                 << s.login << SEPARATOR
                                 << s.formation << SEPARATOR
                                 << s.level << '\n';
                }
            }
            file_present.close();
            emit log("File saved with sucess... !");
        }
        else
            emit log("ERROR | Could not open files for export");
    }
    else
        emit log("ERROR | Path export not set");
}

void FileManager::updateStudentStatus(char *date, QString uid, QString login)
{
    QMap<QString, studentInfos>::iterator i = studentsList.find(login);
    while (i != studentsList.end() && i.key() == login)
    {
        i.value().uid = uid;
        i.value().presence = true;
        i.value().date_scan = date;
        ++i;

        emit addRow(studentToQStringList(i.value())); // add student to visualize array
    }
}

void FileManager::clearListing()
{
    studentsList.clear();
    emit clearRows();
}