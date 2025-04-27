#include "common/layout.h"
#include "task_array_list.h"

int main() {
    TaskArrayList todoList = initTaskArrayList();
    int option;

    do {
        option = getSelectedMenuOption();
    } while (option != 0);

    return 0;
}
