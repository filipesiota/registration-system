#ifndef TASK_H
#define TASK_H

#define TASK_DESCRIPTION_LENGTH 100

typedef struct {
    int id;
    char description[TASK_DESCRIPTION_LENGTH];
} Task;

#endif
