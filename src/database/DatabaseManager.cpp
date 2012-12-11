#include "DatabaseManager.h"
#include <QMessageBox>
#include <QSqlQuery>

DatabaseManager* DatabaseManager::m_INSTANCE = NULL;
const char* DatabaseManager::DATABASE_FILE_NAME = "kino_time_tracker_database.db";

const char* DatabaseManager::TASK_TABLE_NAME = "tasks";
const char* DatabaseManager::TASK_NAME = "title";
const char* DatabaseManager::TASK_ID = "_id";
const char* DatabaseManager::TASK_DESCRIPTION = "description";
const char* DatabaseManager::TASK_START_TIME = "start_time";
const char* DatabaseManager::TASK_END_TIME = "end_time";

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
    db.setDatabaseName(DATABASE_FILE_NAME);

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
    if(!lastError().text().isEmpty())
        qDebug(lastError().text().toAscii().constData());

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
    return QFile::exists(DATABASE_FILE_NAME);
}

bool DatabaseManager::deleteDatabase()
{
    // Close database
    db.close();

    // Remove created database binary file
    return QFile::remove(DATABASE_FILE_NAME);
}

void DatabaseManager::initializeDatabase()
{
    qDebug("Initializing database");
    open();

    QSqlQuery query;

    QString execQuery("CREATE TABLE IF NOT EXISTS ");
    execQuery.append(TASK_TABLE_NAME);
    execQuery.append(" (").append(TASK_ID);
    execQuery.append(" INTEGER PRIMARY KEY AUTOINCREMENT,");
    execQuery.append(TASK_NAME).append(" TEXT,");
    execQuery.append(TASK_START_TIME).append(" INTEGER,");
    execQuery.append(TASK_END_TIME).append(" INTEGER,");
    execQuery.append(TASK_DESCRIPTION).append(" TEXT);");

    bool returnValue = query.exec(execQuery);

    if(!returnValue)
    {
        qDebug("Query error:");
        qDebug("%s",query.lastError().text().toAscii().constData());
    }
    close();
}

QSqlQuery DatabaseManager::exec(QString &query)
{
    return db.exec(query);
}
