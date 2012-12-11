#ifndef TASK_H
#define TASK_H
#include <QDateTime>
#include <QString>

class Task
{
private:

    static const int NOT_INSERTED_TO_DATABASE;
    int m_id;
    QString m_name;
    QString m_description;
    QDateTime m_dateEnd;
    QDateTime m_dateStart;

    void init(QString name, QString description, long long start, long long end,int id);
    //This constructor is used only by TaskManager
    Task(int id, QString name, QString description, long long start, long long end);

    friend class TaskManager;
    void setId(int id);

public:

    Task(QString name, QString description, long long start, long long end);

    int getId();
    QString getName();
    QString getDescription();
    QDateTime getStartTime();
    QDateTime getEndTime();
    bool isInProgress();
};

#endif // TASK_H
