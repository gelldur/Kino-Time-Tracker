#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QFile>

static const QString databaseDriverString = "QSQLITE";

class DatabaseManager
{
private:
    static const QString m_DATABASE_NAME;
    static DatabaseManager* m_INSTANCE;
    QSqlDatabase db;
    DatabaseManager();
    DatabaseManager(const DatabaseManager&);//Don't implement
    DatabaseManager& operator=(const DatabaseManager&);//Don't implement

    void initializeDatabase();

public:
    ~DatabaseManager();

    static DatabaseManager* getInstance();

    bool open();
    bool close();

    bool deleteDatabase();
    QSqlError lastError();

    bool isDatabaseExist();

};
#endif // DATABASEMANAGER_H
