#include "common/menu.h"

#include <stdio.h>

#include "common/util.h"

char* getMenuOptionText(int option) {
    switch (option) {
        case 0:
            return "(0) Sair";
        case 1:
            return "(1) Inserir tarefa";
        case 2:
            return "(2) Remover tarefa";
        case 3:
            return "(3) Listar tarefas";
        case 4:
            return "(4) Buscar tarefa pela descricao";
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
