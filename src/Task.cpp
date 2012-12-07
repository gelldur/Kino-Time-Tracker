#include "Task.h"


Task::Task(QString name, QString description, long start, long end)
{
    m_name = name;
    m_description = description;
    m_dateStart = QDateTime::fromMSecsSinceEpoch(start);
    m_dateEnd = QDateTime::fromMSecsSinceEpoch(end);
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
