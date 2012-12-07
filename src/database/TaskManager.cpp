#include "TaskManager.h"
#include "DatabaseManager.h"

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
    query.append(DatabaseManager::TASK_DATABASE_NAME);
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


