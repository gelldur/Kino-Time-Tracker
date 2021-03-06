#include "TaskManager.h"
#include "DatabaseManager.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlResult>

TaskManager::TaskManager()
{
}

bool TaskManager::add(Task *task)
{
    DatabaseManager *dataBase = DatabaseManager::getInstance();
    if(dataBase->open()==false)
    {
        return false;
    }

    QString query("INSERT INTO ");
    query.append(DatabaseManager::TASK_TABLE_NAME);
    query.append(" (");
    query.append(DatabaseManager::TASK_TITLE);
    query.append(",").append(DatabaseManager::TASK_START_TIME);
    query.append(",").append(DatabaseManager::TASK_END_TIME);
    query.append(",").append(DatabaseManager::TASK_DESCRIPTION);
    query.append(") VALUES ('");
    query.append(task->getTitle());
    query.append("','").append(QString::number(task->getStartTime().toMSecsSinceEpoch()));
    query.append("','").append(QString::number(task->getEndTime().toMSecsSinceEpoch()));
    query.append("','").append(task->getDescription());
    query.append("');");

    qDebug() << query;
    QSqlQuery outpuQuery = dataBase->exec(query);

    bool returnValue;
    int returnedId = Task::NOT_INSERTED_TO_DATABASE;
    qDebug("po insercie dostalem id: %d",outpuQuery.lastInsertId().toInt(&returnValue));
    qDebug()<< "Udalo sie: " << returnValue;

    task->setId(returnedId);

    dataBase->close();
    return returnValue;
}

Task *TaskManager::get(int id)
{
    DatabaseManager *dataBase = DatabaseManager::getInstance();
    if(dataBase->open()==false)
    {
        return NULL;
    }

    QString query("SELECT ");
    query.append(DatabaseManager::TASK_ID);
    query.append(",").append(DatabaseManager::TASK_TITLE);
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

vector<Task*>* TaskManager::getMostPopular(int limit, bool asc)
{
    if(limit < 1)
        return NULL;

    DatabaseManager *dataBase = DatabaseManager::getInstance();
    if(dataBase->open()==false)
    {
        return NULL;
    }
    //Example of comand
    //SELECT * FROM tasks GROUP BY title ORDER BY COUNT(title) DESC
    QString query("SELECT ");
    query.append(DatabaseManager::TASK_ID);
    query.append(",").append(DatabaseManager::TASK_TITLE);
    query.append(",").append(DatabaseManager::TASK_START_TIME);
    query.append(",").append(DatabaseManager::TASK_END_TIME);
    query.append(",").append(DatabaseManager::TASK_DESCRIPTION);
    query.append(" FROM ").append(DatabaseManager::TASK_TABLE_NAME);
    query.append(" GROUP BY ").append(DatabaseManager::TASK_TITLE);
    query.append(" ORDER BY COUNT(").append(DatabaseManager::TASK_TITLE);
    if(asc)
    {
        query.append(") ASC LIMIT ");
    }
    else
    {
        query.append(") DESC LIMIT ");
    }
    query.append(QString::number(limit));//Convert int to char

    qDebug("%s",query.toAscii().constData());

    QSqlQuery getQuery = dataBase->exec(query);

    vector<Task*>* tasks = parseTask(getQuery);
    if(tasks->size() < 1)
    {
        delete tasks;
        return NULL;
    }


    dataBase->close();
    return tasks;
}

void TaskManager::update(Task *task)
{
    DatabaseManager *dataBase = DatabaseManager::getInstance();
    if(dataBase->open()==false)
    {
        return;
    }

    //Example of comand
    //UPDATE tasks SET title="nowa_nazwa" WHERE _id=1
    QString query("UPDATE ");
    query.append(DatabaseManager::TASK_TABLE_NAME);
    query.append(" SET ").append(DatabaseManager::TASK_TITLE);
    query.append("=\"").append(task->getTitle());
    query.append("\",").append(DatabaseManager::TASK_START_TIME);
    query.append("=").append(QString::number(task->getStartTime().toMSecsSinceEpoch()));
    query.append(",").append(DatabaseManager::TASK_END_TIME);
    query.append("=").append(QString::number(task->getEndTime().toMSecsSinceEpoch()));
    query.append(",").append(DatabaseManager::TASK_DESCRIPTION);
    query.append("=\"").append(task->getDescription());
    query.append("\" WHERE ").append(DatabaseManager::TASK_ID);
    query.append("=").append(QString::number(task->getId()));

    qDebug("%s",query.toAscii().constData());

    dataBase->exec(query);
    dataBase->close();
}
