#ifndef TASK_H
#define TASK_H
#include <QDateTime>
#include <QString>


class Task
{
public:
    Task(QString name, QString description, long start, long end);

    QString getName();
    QString getDescription();
    QDateTime getStartTime();
    QDateTime getEndTime();

private:

    QString m_name;
    QString m_description;
    QDateTime m_dateEnd;
    QDateTime m_dateStart;
};

#endif // TASK_H
