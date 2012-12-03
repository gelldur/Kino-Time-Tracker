#include "DatabaseManager.h"

#include <QDir>

DatabaseManager::DatabaseManager(QObject *parent) : QObject(parent)
{

}

DatabaseManager::~DatabaseManager()
{

}

bool DatabaseManager::openDB()
{
    // Find QSLite driver
    db = QSqlDatabase::addDatabase("QSQLITE");

    //TODO Store database in home dir
    db.setDatabaseName("my.db.sqlite");

    // Open databasee
    return db.open();
}

QSqlError DatabaseManager::lastError()
{
    // If opening database has failed user can ask
    // error description by QSqlError::text()
    return db.lastError();
}

bool DatabaseManager::deleteDB()
{
    // Close database
    db.close();

    // Remove created database binary file
    return QFile::remove("my.db.sqlite");
}
