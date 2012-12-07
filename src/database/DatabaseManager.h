#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QFile>
#include <QVariant>

static const QString databaseDriverString = "QSQLITE";

class DatabaseManager
{
private:
    static DatabaseManager* m_INSTANCE;
    QSqlDatabase db;
    DatabaseManager();
    DatabaseManager(const DatabaseManager&);//Don't implement
    DatabaseManager& operator=(const DatabaseManager&);//Don't implement

    void initializeDatabase();

public:
    ~DatabaseManager();

    static const char* DATABASE_FILE_NAME;

    static const char* TASK_DATABASE_NAME;
    static const char* TASK_ID;
    static const char* TASK_NAME;
    static const char* TASK_DESCRIPTION;
    static const char* TASK_START_TIME;
    static const char* TASK_END_TIME;

    static DatabaseManager* getInstance();

    bool open();
    bool close();

    bool deleteDatabase();
    QSqlError lastError();

    bool isDatabaseExist();
    QSqlQuery exec(QString &query);


};
#endif // DATABASEMANAGER_H
