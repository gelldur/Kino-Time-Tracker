#include "TaskManager.h"
#include "DatabaseManager.h"
#include <QSqlQuery>

TaskManager::TaskManager()
{
}

bool TaskManager::addTask(Task *task)
{
    DatabaseManager *dataBase = DatabaseManager::getInstance();
    if(dataBase->open()==false)
    {
        return false;
    }

    QString query("INSERT INTO ");
    query.append(DatabaseManager::TASK_TABLE_NAME);
    query.append("(");
    query.append(DatabaseManager::TASK_NAME);
    query.append(",").append(DatabaseManager::TASK_START_TIME);
    query.append(",").append(DatabaseManager::TASK_END_TIME);
    query.append(",").append(DatabaseManager::TASK_DESCRIPTION);
    query.append(") VALUES (");
    query.append(task->getName());
    query.append(",").append(QString::number(task->getStartTime().toMSecsSinceEpoch()));
    query.append(",").append(QString::number(task->getEndTime().toMSecsSinceEpoch()));
    query.append(",").append(task->getDescription());
    query.append(")");
    dataBase->exec(query);
    return true;
}

Task *TaskManager::getTask(int id)
{
    DatabaseManager *dataBase = DatabaseManager::getInstance();
    if(dataBase->open()==false)
    {
        return NULL;
    }

    QString query("SELECT ");
    query.append(DatabaseManager::TASK_NAME);
    query.append(",").append(DatabaseManager::TASK_START_TIME);
    query.append(",").append(DatabaseManager::TASK_END_TIME);
    query.append(",").append(DatabaseManager::TASK_DESCRIPTION);
    query.append(" FROM ").append(DatabaseManager::TASK_TABLE_NAME);
    query.append(" WHERE ").append(DatabaseManager::TASK_ID).append("=").append(QString::number(id));

    qDebug("%s",query.toAscii().constData());

    QSqlQuery zb25 = dataBase->exec(query);
    if(zb25.next() == false) return NULL;

    QString name = zb25.value(0).toString();
    long long startTime = zb25.value(1).toLongLong();
    long long endTime = zb25.value(2).toLongLong();
    QString description = zb25.value(3).toString();
    Task* task = new Task(id, name, description, startTime, endTime);

    dataBase->close();
    return task;
}


