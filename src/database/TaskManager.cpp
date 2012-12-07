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
    query.append(DatabaseManager::TASK_ID);
    query.append(",").append(DatabaseManager::TASK_NAME);
    query.append(",").append(DatabaseManager::TASK_START_TIME);
    query.append(",").append(DatabaseManager::TASK_END_TIME);
    query.append(",").append(DatabaseManager::TASK_DESCRIPTION);
    query.append(" FROM ").append(DatabaseManager::TASK_TABLE_NAME);
    query.append(" WHERE ").append(DatabaseManager::TASK_ID).append("=").append(QString::number(id));

    qDebug("%s",query.toAscii().constData());

    QSqlQuery getQuery = dataBase->exec(query);

    vector<Task*>* tasks = parseTask(getQuery);
    if(tasks->size() < 1)
    {
        delete tasks;
        return NULL;
    }

    Task* task = tasks->at(0);
    delete tasks;

    dataBase->close();
    return task;
}

vector<Task*>* TaskManager::parseTask(QSqlQuery &sqlQuery)
{
    vector<Task*>* tasks = new vector<Task*>();

    while(sqlQuery.next())
    {
        int id = sqlQuery.value(0).toInt();
        QString name = sqlQuery.value(1).toString();
        long long startTime = sqlQuery.value(2).toLongLong();
        long long endTime = sqlQuery.value(3).toLongLong();
        QString description = sqlQuery.value(4).toString();

        tasks->push_back(new Task(id, name, description, startTime, endTime));
    }
    return tasks;
}


