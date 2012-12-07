#ifndef TASKMANAGER_H
#define TASKMANAGER_H
#include <QSqlQuery>
#include <vector>
#include "Task.h"

using std::vector;

class TaskManager
{
public:
    TaskManager();

    bool addTask(Task *task);

    Task* getTask(int id);

private:
    vector<Task*>* parseTask(QSqlQuery& sqlQuery);
};

#endif // TASKMANAGER_H
