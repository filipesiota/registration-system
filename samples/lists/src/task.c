#include "common/task.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "common/util.h"

Task createTask() {
    Task task;

    task.id = (int)time(NULL);

    do {
        printf("Informe uma descricao para a tarefa: ");
        sysCommand("clear_stdin");
        fgets(task.description, TASK_DESCRIPTION_LENGTH, stdin);
        normalizeString(task.description);

        if (strlen(task.description) == 0) {
            printf("\nO campo de descricao e obrigatorio!\n\n");
        }
    } while (strlen(task.description) == 0);

    return task;
}

int requestTaskIndex(int maxIndex) {
    int index;

    do {
        printf("Informe o indice da tarefa: ");
        sysCommand("clear_stdin");
        scanf("%d", &index);

        if (index < 0 || index > maxIndex) {
            printf("\nO indice informado nao existe!\n\n");
        }
    } while (index < 0 || index > maxIndex);

    return index;
}

char* requestTaskDescription() {
    char* description = malloc(TASK_DESCRIPTION_LENGTH);

    if (description == NULL) {
        printf("[task] requestTaskDescription: Nao foi possivel realocar a memoria");
        return NULL;
    }

    do {
        printf("Procure pela descricao da tarefa: ");
        sysCommand("clear_stdin");
        fgets(description, TASK_DESCRIPTION_LENGTH, stdin);
        normalizeString(description);

        if (strlen(description) == 0) {
            printf("\nA descricao e obrigatoria!\n\n");
        }
    } while (strlen(description) == 0);

    return description;
}

void showTask(Task task, int index) {
    printf("Indice: %d\n", index);
    printf("ID: %d\n", task.id);
    printf("Descricao: %s\n", task.description);
}
