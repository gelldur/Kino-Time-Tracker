#include "DatabaseManager.h"
#include <QMessageBox>

const QString DatabaseManager::DATABASE_NAME = QString("kino_time_tracker.db");

DatabaseManager::DatabaseManager()
{

}

DatabaseManager::~DatabaseManager()
{

}

bool DatabaseManager::open()
{
    //Check driver
    if (!QSqlDatabase::isDriverAvailable (databaseDriverString))
    {
        qDebug("I don't have driver to open sqlite!");
        QMessageBox::critical(0,"Database Error","Database error");

        exit(1);
    }

    // Find QSLite driver
    db = QSqlDatabase::addDatabase(databaseDriverString);
    if(!db.isValid())
    {
        qDebug("Can't open database connection");
    }

    //TODO Store database in home dir
    db.setDatabaseName(DATABASE_NAME);

    // Open databasee
    return db.open();
}

QSqlError DatabaseManager::lastError()
{
    // If opening database has failed user can ask
    // error description by QSqlError::text()
    return db.lastError();
}

bool DatabaseManager::isDatabaseExist()
{
    return QFile::exists(DATABASE_NAME);
}

bool DatabaseManager::deleteDatabase()
{
    // Close database
    db.close();

    // Remove created database binary file
    return QFile::remove(DATABASE_NAME);
}
