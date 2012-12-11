#include "Task.h"

const int Task::NOT_INSERTED_TO_DATABASE = 0;

void Task::init(QString name, QString description, long long start, long long end,int id = NOT_INSERTED_TO_DATABASE )
{
    m_id = id;
    m_name = name;
    m_description = description;
    m_dateStart = QDateTime::fromMSecsSinceEpoch(start);
    m_dateEnd = QDateTime::fromMSecsSinceEpoch(end);
}

Task::Task(int id, QString name, QString description, long long start, long long end)
{
    init(name,description,start,end,id);
}

void Task::setId(int id)
{
    m_id = id;
}

Task::Task(QString name, QString description, long long start, long long end)
{
    //We should add this object to database to get ID
    init(name,description,start,end);
}

int Task::getId()
{
    return m_id;
}

QString Task::getName()
{
    return m_name;
}

QString Task::getDescription()
{
    return m_description;
}

QDateTime Task::getStartTime()
{
    return m_dateStart;
}

QDateTime Task::getEndTime()
{
    return m_dateEnd;
}
