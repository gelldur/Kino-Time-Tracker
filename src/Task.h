#ifndef TASK_H
#define TASK_H
#include <QDateTime>
#include <QString>


class Task
{
public:

    QString m_name;
    QString m_description;
    long m_startTime;
    long m_endTime;

    Task(QString name, QString description, long start, long end);

    QString m_getName();
    QString m_getDescription();
    QDateTime m_getStartTime();
    QDateTime m_getEndTime();
};

#endif // TASK_H
