#ifndef TASKMANAGER_H
#define TASKMANAGER_H
#include "Task.h"

class TaskManager
{
public:
    TaskManager();

    bool addTask(Task *task);
};

#endif // TASKMANAGER_H
