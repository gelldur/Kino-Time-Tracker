#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QFile>

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

    static const QString m_DATABASE_NAME;
    static const QString TASK_DATABASE_NAME;
    static const QString TASK_ID;
    static const QString TASK_TITLE;

    static DatabaseManager* getInstance();

    bool open();
    bool close();

    bool deleteDatabase();
    QSqlError lastError();

    bool isDatabaseExist();
    QSqlQuery exec(QString &query);


};
#endif // DATABASEMANAGER_H
