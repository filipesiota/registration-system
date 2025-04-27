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

#endif
