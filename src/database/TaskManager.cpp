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
    query.append(DatabaseManager::TASK_ID);
    query.append(",").append(DatabaseManager::TASK_NAME);
    query.append(",").append(DatabaseManager::TASK_START_TIME);
    query.append(",").append(DatabaseManager::TASK_END_TIME);
    query.append(",").append(DatabaseManager::TASK_DESCRIPTION);
    query.append(" FROM ").append(DatabaseManager::TASK_TABLE_NAME);
    query.append(" WHERE ").append(append(QString::number(id));

}


