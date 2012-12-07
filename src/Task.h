#ifndef TASK_H
#define TASK_H
#include <QDateTime>
#include <QString>


class Task
{
public:
    Task(QString name, QString description, long start, long end);


private:

    QString m_name;
    QString m_description;
    long m_startTime;
    long m_endTime;

    QString getName();
    QString getDescription();
    QDateTime getStartTime();
    QDateTime getEndTime();
};

#endif // TASK_H
