#include "task_linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TaskLinkedList initTaskLinkedList() {
    TaskLinkedList list;

    list.start = NULL;

    return list;
}

void freeTaskLinkedList(TaskLinkedList *list) {
    TaskNode *currentNode = list->start;
    TaskNode *nextNode;
    
    while (currentNode != NULL) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    list->start = NULL;
}

void addTask(TaskLinkedList *list, Task *task) {
    TaskNode *newNode = malloc(sizeof(TaskNode));

    if (newNode == NULL) {
        printf("[task_linked_list] addTask: Nao foi possivel alocar memoria.\n");
        return;
    }

    newNode->task = *task;
    newNode->next = list->start;
    list->start = newNode;
}

int removeTask(TaskLinkedList *list, int id) {
    if (list->start == NULL) {
        return 0;
    }

    TaskNode *currentNode = list->start;
    TaskNode *nextNode;

    if (currentNode->task.id == id) {
        list->start = currentNode->next;
        free(currentNode);
        return 1;
    }

    while (currentNode->next != NULL) {
        if (currentNode->next->task.id == id) {
            nextNode = currentNode->next->next;
            free(currentNode->next);
            currentNode->next = nextNode;
            return 1;
        }

        currentNode = currentNode->next;
    }

    return 0;
}

void listTasks(TaskLinkedList *list) {
    if (list->start == NULL) {
        printf("[Nenhuma tarefa cadastrada]\n");
        return;
    }

    TaskNode *currentNode = list->start;

    printf("# =============================== #\n");

    while (currentNode != NULL) {
        showTask(&currentNode->task, -1);
        printf("# =============================== #\n");

        currentNode = currentNode->next;
    }
}

Task* findTaskByDescription(TaskLinkedList *list, const char *description) {
    if (list->start == NULL) {
        return NULL;
    }

    TaskNode *currentNode = list->start;

    while (currentNode != NULL) {
        if (strcmp(currentNode->task.description, description) == 0) {
            return &currentNode->task;
        }

        currentNode = currentNode->next;
    }

    return NULL;
}
