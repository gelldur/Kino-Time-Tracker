#include "Task.h"


Task::Task(int id, QString name, QString description, long long start, long long end)
{
    m_id = id;
    m_name = name;
    m_description = description;
    m_dateStart = QDateTime::fromMSecsSinceEpoch(start);
    m_dateEnd = QDateTime::fromMSecsSinceEpoch(end);
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
