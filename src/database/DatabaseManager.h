#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QFile>

static const QString databaseDriverString = "QSQLITE";

class DatabaseManager
{
private:
    static const QString DATABASE_NAME;
    static DatabaseManager* INSTANCE;
    QSqlDatabase db;
    DatabaseManager();

public:
    ~DatabaseManager();

    bool open();
    bool deleteDatabase();
    QSqlError lastError();

    bool isDatabaseExist();

};
#endif // DATABASEMANAGER_H
