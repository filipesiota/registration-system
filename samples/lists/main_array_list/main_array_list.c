#include <stdio.h>

#include "common/menu.h"
#include "common/util.h"
#include "task_array_list.h"

void addTodoTask(TaskArrayList *list);
void removeTodoTask(TaskArrayList *list);
void listTodoTasks(TaskArrayList *list);
void findTodoTaskByDescription(TaskArrayList *list);

int main() {
    TaskArrayList todoList = initTaskArrayList();
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

    freeTaskArrayList(&todoList);
    printf("\nPrograma finalizado!\n");
    sysCommand("pause_terminal");

    return 0;
}

void addTodoTask(TaskArrayList *list) {
    printf("%s\n\n", getMenuOptionText(1));

    Task task = createTask();
    addTask(list, &task);
}

void removeTodoTask(TaskArrayList *list) {
    printf("%s\n\n", getMenuOptionText(2));

    int index = requestTaskIndex(list->size - 1);
    removeTask(list, index);
}

void listTodoTasks(TaskArrayList *list) {
    printf("%s\n\n", getMenuOptionText(3));

    listTasks(list);
}

void findTodoTaskByDescription(TaskArrayList *list) {
    printf("%s\n\n", getMenuOptionText(4));

    char* description = requestTaskDescription();
    int index = findTaskIndexByDescription(list, description);

    printf("\n");

    if (index != -1) {
        showTask(&list->tasks[index], index);
        return;
    }

    printf("[Nenhuma tarefa encontrada]\n");
}
