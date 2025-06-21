#include <stdio.h>
#include <stdlib.h>

#include "common/util.h"
#include "common/menu.h"
#include "hash_table.h"

int main() {
    int option;

    do {
        option = getSelectedMenuOption();

        if (option != 0) {
            sysCommand("clear_terminal");
            printf("%s\n\n", getMenuOptionText(option));

            switch (option) {
                default:
            }

            printf("\nAcao finalizada!\n");
            sysCommand("pause_terminal");
        }
    } while (option != 0);

    // free

    printf("\nPrograma finalizado!\n");
    sysCommand("pause_terminal");

    return 0;
}
