#ifndef TASK_H
#define TASK_H

#define TASK_DESCRIPTION_LENGTH 100

typedef struct {
    int id;
    char description[TASK_DESCRIPTION_LENGTH];
} Task;

Task createTask();
int requestTaskIndex(int maxIndex);
int requestTaskId();
char* requestTaskDescription();
void showTask(Task *task, int index);

#endif
