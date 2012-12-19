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

    bool add(Task *task);

    Task* get(int id);
    void update(Task* task);

    //Default DESC order
    vector<Task*>* getMostPopular(int limit,bool asc = false);

private:
    vector<Task*>* parseTask(QSqlQuery& sqlQuery);
};

#endif // TASKMANAGER_H
