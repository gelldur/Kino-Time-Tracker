#include "DatabaseManager.h"
#include <QMessageBox>
#include <QSqlQuery>

DatabaseManager* DatabaseManager::m_INSTANCE = NULL;
const QString DatabaseManager::m_DATABASE_NAME = QString("kino_time_tracker.db");

DatabaseManager::DatabaseManager()
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

    bool initDatabase = isDatabaseExist();
    //TODO Store database in home dir
    db.setDatabaseName(m_DATABASE_NAME);
    open();
    if(!initDatabase)
        initializeDatabase();
}

DatabaseManager::~DatabaseManager()
{

}

DatabaseManager *DatabaseManager::getInstance()
{
    if(m_INSTANCE == NULL)
    {
        m_INSTANCE = new DatabaseManager();
    }
    return m_INSTANCE;
}

bool DatabaseManager::open()
{
    if (!db.open())
    {
        /*
           *Gui message that informs that the database cannot open
           */
        QMessageBox::critical(0,"Database connection error","Database connection error");

        /*
           *@return false if database connection failed.
           */
        return false;
    }
    // Open databasee
    return db.isOpen();
}

bool DatabaseManager::close()
{

    db.close();

    if(!db.isOpen())
        return true;
    else
        return false;
}

QSqlError DatabaseManager::lastError()
{
    // If opening database has failed user can ask
    // error description by QSqlError::text()
    return db.lastError();
}

bool DatabaseManager::isDatabaseExist()
{
    return QFile::exists(m_DATABASE_NAME);
}

bool DatabaseManager::deleteDatabase()
{
    // Close database
    db.close();

    // Remove created database binary file
    return QFile::remove(m_DATABASE_NAME);
}


void DatabaseManager::initializeDatabase()
{
    qDebug("Initializing database");

    bool returnValue;
    QSqlQuery query;
    returnValue =
            query.exec("CREATE TABLE IF NOT EXISTS tasks "
                       "(_id INTEGER PRIMARY KEY AUTOINCREMENT,"
                       "title TEXT);");

    if(!returnValue)
    {
        qDebug("Query error:");
        qDebug(query.lastError().text().toStdString().c_str());
    }
}
