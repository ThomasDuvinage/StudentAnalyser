#include "filemanager.h"

FileManager::FileManager()
{

}

void FileManager::importFiles(){
    this->path_import = QFileDialog::getOpenFileName(this, tr("Import listing"), "/home/thomasduvinage/Documents", tr("Listing Files (*.csv)"));

    QFile file(this->path_import);
        if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << file.errorString();
            emit errorFile(0); // impossible to open file
        }

        QMap<QString, studentInfos> studentsList;

        QTextStream in(&file);
        while (!in.atEnd()){
            QString line = in.readLine();
            QStringList infos = line.split(';');

            if(infos.first() != "Nom" && infos.first() != "NOM"){
                if(infos.length() == 8){
                        studentInfos student;
                        student.first_name = infos.at(0);
                        student.last_name = infos.at(1);
                        student.student_id = infos.at(2);
                        student.no_person = infos.at(3);
                        student.email = infos.at(4);
                        student.login = infos.at(5);
                        student.formation = infos.at(6);
                        student.level = infos.at(7);

                        QString student_login(infos.at(5));

                        qDebug() << student_login;

                        studentsList.insert(student_login, student);
                }
                else{
                    qDebug() << "there are not enough columns in the file";
                    emit errorFile(1); // there are not enough columns in the file
                }
            }

        }
}

void FileManager::exportFiles(){
    this->path_export = QFileDialog::getExistingDirectory(this, tr("Export directory"),"/home/thomasduvinage/Documents", QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);
}


void FileManager::saveDataToFile(QString data){
    QString filename = "/TEST_EXPORT.csv";

    if(!this->path_export.isEmpty()){
        QFile file(this->path_export + filename);

        if(file.exists()){
            if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
                return;
        }
        else{
            if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
                return;

       }
        QTextStream out(&file);
        out << data << '\n';
        qDebug() << "save data : " << data;

        file.close();
    }
}
