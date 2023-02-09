#include "database.hpp"

Database::Database(/* args */)
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");           // @ip serveur MySQL
    db.setDatabaseName("StudentAnalyzer"); // Nom de la base
    db.setUserName("root");                // Nom utilisateur
    db.setPassword("root");                // Mot de passe

    if (db.open())
    {
        emit log("Ok - ouverture de la base de donnée");

        // Exécution d'une requête
        QSqlQuery requete;
        if (requete.exec("SELECT * FROM Students WHERE 1"))
        {
            emit log("Ok - requete");

            // Boucle qui permet de parcourir les enregistrements renvoyés par la requête
            while (requete.next())
            {
                // On accède ici aux différents champs par leurs noms, il est également possible
                // d'y accéder par leur index : requete.value(0)
                qDebug() << requete.value("timestamp") << " " << requete.value("uid") << " " << requete.value("login");
            }
        }

        else
        {
            qDebug() << "Echec de la requête";
            // La méthode lastError permet d'afficher un message
            // plus explicite sur les causes de l'erreur
            qDebug() << requete.lastError();
        }
        db.close(); // Fermeture de la base de données
    }
    else
    {
        qDebug() << "Echec d'ouverture de la base de donnée";
        qDebug() << db.lastError();
    }
}

Database::~Database()
{
}

void Database::addStudent(QString date, QString uid, QString login)
{
}