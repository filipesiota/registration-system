#include "common/menu.h"

#include <stdio.h>

#include "common/util.h"

char* getMenuOptionText(int option) {
    switch (option) {
        case 0:
            return "(0) Sair";
        case 1:
            return "(1) Inserir cliente convencional";
        case 2:
            return "(2) Atender cliente convencional";
        case 3:
            return "(3) Inserir cliente prioritário (início)";
        case 4:
            return "(4) Inserir cliente prioritário (fim)";
        case 5:
            return "(5) Atender cliente prioritário (início)";
        case 6:
            return "(6) Desistência de cliente prioritário (fim)";
        case 7:
            return "(7) Exibir filas";
    }
}

void showMenu() {
    int i;

    for (i = 0; i <= MENU_LENGTH; i++) {
        printf("%s\n", getMenuOptionText(i));
    }
}

int getSelectedMenuOption() {
    int option;

    sysCommand("clear_terminal");
    showMenu();

    do {
        printf("\nEscolha uma opcao: ");
        sysCommand("clear_stdin");
        scanf("%d", &option);

        if (option < 0 || option > MENU_LENGTH) {
            printf("\nOpcao invalida!\n");
        }
    } while(option < 0 || option > MENU_LENGTH);

    return option;
}
