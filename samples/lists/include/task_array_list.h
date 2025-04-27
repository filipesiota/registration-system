#ifndef TASK_ARRAY_LIST_H
#define TASK_ARRAY_LIST_H

#include "common/task.h"

typedef struct {
    int size;
    Task *tasks;
} TaskArrayList;

TaskArrayList initTaskArrayList();
void freeTaskArrayList(TaskArrayList *list);
void addTask(TaskArrayList *list, Task task);
void removeTask(TaskArrayList *list, int index);
void listTasks(TaskArrayList *list);
int findTaskIndexByDescription(TaskArrayList *list, char description[TASK_DESCRIPTION_LENGTH]);

#endif
