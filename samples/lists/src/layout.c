#include "common/layout.h"

#include <stdio.h>

#include "common/sys_command.h"

void showMenu() {
    printf("\n(0) Sair");
    printf("\n(1) Inserir tarefa");
    printf("\n(2) Remover tarefa");
    printf("\n(3) Listar tarefas");
    printf("\n(4) Buscar tarefa pela descricao");
}

int getSelectedMenuOption() {
    int option;

    sys_command("clear_terminal");
    showMenu();

    do {
        printf("\n\nEscolha uma opcao: ");
        scanf("%d", &option);

        if (option < 0 || option > MENU_LENGTH) {
            printf("Opcao invalida!");
        }
    } while(option < 0 || option > MENU_LENGTH);

    return option;
}
