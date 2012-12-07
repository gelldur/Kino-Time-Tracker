#include "Task.h"


Task::Task(QString name, QString description, long start, long end)
{
    m_name=name;
    m_description=description;
    m_startTime=start;
    m_endTime=end;
}


QString Task::getName()
{
    return(m_name);
}
QString Task::getDescription()
{
    return(m_description);
}


QDateTime Task::getStartTime()
{
    QDateTime dateStart = QDateTime::fromMSecsSinceEpoch(m_startTime);
    return(dateStart);
}


QDateTime Task::getEndTime()
{
    QDateTime dateEnd = QDateTime::fromMSecsSinceEpoch(m_endTime);
    return(dateEnd);
}
