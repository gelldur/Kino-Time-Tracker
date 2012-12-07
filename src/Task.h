#ifndef TASK_H
#define TASK_H
#include <QDateTime>
#include <QString>

class Task
{
public:
    Task(int id, QString name, QString description, long start, long end);

    int getId();
    QString getName();
    QString getDescription();
    QDateTime getStartTime();
    QDateTime getEndTime();
    bool isInProgress();

private:

    int m_id;
    QString m_name;
    QString m_description;
    QDateTime m_dateEnd;
    QDateTime m_dateStart;
};

#endif // TASK_H
