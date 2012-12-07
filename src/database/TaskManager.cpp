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
    query.append(") VALUES (");
    query.append(task->getName());
    query.append(")");

   // "INSERT INTO names (id, test_field) VALUES (1, 'тест1')"
    dataBase->exec(query);
    return true;
}


