#include <stdio.h>

#include "common/menu.h"
#include "common/util.h"
#include "task_linked_list.h"

void addTodoTask(TaskLinkedList *list);
void removeTodoTask(TaskLinkedList *list);
void listTodoTasks(TaskLinkedList *list);
void findTodoTaskByDescription(TaskLinkedList *list);

int main() {
    TaskLinkedList todoList = initTaskLinkedList();
    int option;

    do {
        option = getSelectedMenuOption();

        if (option != 0) {
            sysCommand("clear_terminal");

            switch (option) {
                case 1:
                    addTodoTask(&todoList);
                    break;
                case 2:
                    removeTodoTask(&todoList);
                    break;
                case 3:
                    listTodoTasks(&todoList);
                    break;
                case 4:
                    findTodoTaskByDescription(&todoList);
                    break;
            }

            printf("\nAcao finalizada!\n");
            sysCommand("pause_terminal");
        }
    } while (option != 0);

    freeTaskLinkedList(&todoList);
    printf("\nPrograma finalizado!\n");
    sysCommand("pause_terminal");

    return 0;
}

void addTodoTask(TaskLinkedList *list) {
    printf("%s\n\n", getMenuOptionText(1));

    Task task = createTask();
    addTask(list, &task);
}

void removeTodoTask(TaskLinkedList *list) {
    printf("%s\n\n", getMenuOptionText(2));

    int index = requestTaskId();
    int success = removeTask(list, index);

    if (!success) {
        printf("\n[Tarefa nao encontrada]\n");
    }
}

void listTodoTasks(TaskLinkedList *list) {
    printf("%s\n\n", getMenuOptionText(3));

    listTasks(list);
}

void findTodoTaskByDescription(TaskLinkedList *list) {
    printf("%s\n\n", getMenuOptionText(4));

    char* description = requestTaskDescription();
    Task *task = findTaskByDescription(list, description);

    printf("\n");

    if (task != NULL) {
        showTask(task, -1);
        return;
    }

    printf("[Nenhuma tarefa encontrada]\n");
}
