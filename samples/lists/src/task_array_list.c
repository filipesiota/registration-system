#include "task_array_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TaskArrayList initTaskArrayList() {
    TaskArrayList list;

    list.size = 0;
    list.tasks = NULL;

    return list;
}

void freeTaskArrayList(TaskArrayList *list) {
    if (list->tasks != NULL) {
        free(list->tasks);
        list->tasks = NULL;
    }
    
    list->size = 0;
}

void addTask(TaskArrayList *list, Task task) {
    Task *temp = realloc(list->tasks, (list->size + 1) * sizeof(Task));

    if (temp == NULL) {
        printf("[task_array_list] addTask: Nao foi possivel realocar a memoria");
        return;
    }

    list->tasks = temp;
    list->tasks[list->size] = task;
    list->size++;
}

void removeTask(TaskArrayList *list, int index) {
    if (index < 0 || index >= list->size) {
        return;
    }

    int i;

    for (i = 0; i < list->size - 1; i++) {
        if (i >= index) {
            list->tasks[i] = list->tasks[i + 1];
        }
    }

    Task *temp = realloc(list->tasks, (list->size - 1) * sizeof(Task));

    if (temp == NULL) {
        printf("[task_array_list] removeTask: Nao foi possivel realocar a memoria");
        return;
    }

    list->tasks = temp;
    list->size--;
}

void listTasks(TaskArrayList *list) {
    if (list->size == 0) {
        printf("[Nenhuma tarefa cadastrada]\n");
        return;
    }

    int i;

    printf("# =============================== #\n");

    for (i = 0; i < list->size; i++) {
        showTask(list->tasks[i], i);
        printf("# =============================== #\n");
    }
}

int findTaskIndexByDescription(TaskArrayList *list, char description[TASK_DESCRIPTION_LENGTH]) {
    if (list->size == 0) {
        return -1;
    }

    int i;

    for (i = 0; i < list->size; i++) {
        if (strcmp(list->tasks[i].description, description) == 0) {
            return i;
        }
    }

    return -1;
}
