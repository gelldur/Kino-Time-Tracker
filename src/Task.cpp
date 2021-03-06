#include "Task.h"

const int Task::NOT_INSERTED_TO_DATABASE = 0;

void Task::init(QString title, QString description, long long start, long long end,int id = NOT_INSERTED_TO_DATABASE )
{
    m_id = id;
    m_title = title;
    m_description = description;
    m_dateStart = QDateTime::fromMSecsSinceEpoch(start);
    m_dateEnd = QDateTime::fromMSecsSinceEpoch(end);
}

Task::Task(int id, QString title, QString description, long long start, long long end)
{
    init(title,description,start,end,id);
}

void Task::setId(int id)
{
    m_id = id;
}

Task::Task(QString title, QString description, long long start, long long end)
{
    //We should add this object to database to get ID
    init(title,description,start,end);
}

int Task::getId()
{
    return m_id;
}

QString Task::getTitle()
{
    return m_title;
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

void Task::setTitle(const char* title)
{
    m_title = QString(title);
}

void Task::setTitle(const QString &title)
{
    m_title = title;
}

void Task::setDescription(const char *description)
{
    m_description = QString(description);
}

void Task::setDescription(const QString &description)
{
    m_description = description;
}

void Task::setStartTime(const QDateTime &start)
{
    m_dateStart = start;
}

void Task::setEndTime(const QDateTime &end)
{
    m_dateEnd = end;
}
