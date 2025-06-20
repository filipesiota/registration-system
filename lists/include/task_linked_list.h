#ifndef TASK_LINKED_LIST_H
#define TASK_LINKED_LIST_H

#include "common/task.h"

typedef struct TaskNode TaskNode;

struct TaskNode {
    Task task;
    TaskNode *next;
};

typedef struct {
    TaskNode *start;
} TaskLinkedList;

TaskLinkedList initTaskLinkedList();
void freeTaskLinkedList(TaskLinkedList *list);
void addTask(TaskLinkedList *list, Task *task);
int removeTask(TaskLinkedList *list, int id);
void listTasks(TaskLinkedList *list);
Task* findTaskByDescription(TaskLinkedList *list, const char *description);

#endif
