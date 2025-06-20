#include <stdio.h>
#include <stdlib.h>

#include "common/menu.h"
#include "common/util.h"
#include "client_queue.h"
#include "client_deque.h"

int getClientId();

void addConventionalClient(ClientQueue *line);
void serveConventionalClient(ClientQueue *line);

void addPrioritaryClientToFront(ClientDeque *line);
void addPrioritaryClientToRear(ClientDeque *line);
void servePrioritaryClientFromFront(ClientDeque *line);
void removePrioritaryClientFromRear(ClientDeque *line);

void printLines(ClientQueue *conventionalLine, ClientDeque *prioritaryLine);

int main() {
    ClientQueue *conventionalLine = initClientQueue();
    ClientDeque *prioritaryLine = initClientDeque();
    int option;

    do {
        option = getSelectedMenuOption();

        if (option != 0) {
            sysCommand("clear_terminal");
            printf("%s\n\n", getMenuOptionText(option));

            switch (option) {
                case 1:
                    addConventionalClient(conventionalLine);
                    break;
                case 2:
                    serveConventionalClient(conventionalLine);
                    break;
                case 3:
                    addPrioritaryClientToFront(prioritaryLine);
                    break;
                case 4:
                    addPrioritaryClientToRear(prioritaryLine);
                    break;
                case 5:
                    servePrioritaryClientFromFront(prioritaryLine);
                    break;
                case 6:
                    removePrioritaryClientFromRear(prioritaryLine);
                    break;
                case 7:
                    printLines(conventionalLine, prioritaryLine);
                    break;
            }

            printf("\nAcao finalizada!\n");
            sysCommand("pause_terminal");
        }
    } while (option != 0);

    freeClientQueue(conventionalLine);
    freeClientDeque(prioritaryLine);

    printf("\nPrograma finalizado!\n");
    sysCommand("pause_terminal");

    return 0;
}

int getClientId() {
    int clientId;

    printf("Informe o ID do cliente: ");
    scanf("%d", &clientId);

    return clientId;
}

void addConventionalClient(ClientQueue *line) {
    int clientId = getClientId();

    enqueueClient(line, clientId);
}

void serveConventionalClient(ClientQueue *line) {
    int *clientId = dequeueClient(line);

    if (!clientId) {
        printf("[A fila de clientes convencionais esta vazia]\n");
        return;
    }

    printf("Atendendo cliente convencional com ID: %d\n", *clientId);
}

void addPrioritaryClientToFront(ClientDeque *line) {
    int clientId = getClientId();

    addClientToFront(line, clientId);
}

void addPrioritaryClientToRear(ClientDeque *line) {
    int clientId = getClientId();

    addClientToRear(line, clientId);
}

void servePrioritaryClientFromFront(ClientDeque *line) {
    int *clientId = removeClientFromFront(line);

    if (!clientId) {
        printf("[A fila de clientes prioritarios esta vazia]\n");
        return;
    }

    printf("Atendendo cliente prioritario com ID: %d\n", *clientId);
}

void removePrioritaryClientFromRear(ClientDeque *line) {
    int *clientId = removeClientFromRear(line);

    if (!clientId) {
        printf("[A fila de clientes prioritarios esta vazia]\n");
        return;
    }

    printf("Desistencia de cliente prioritario com ID: %d\n", *clientId);
}

void printLines(ClientQueue *conventionalLine, ClientDeque *prioritaryLine) {
    printf("Fila convencional (%d): ", conventionalLine->size);
    printClientQueue(conventionalLine);

    printf("Fila prioritaria (%d): ", prioritaryLine->size);
    printClientDeque(prioritaryLine);    
}
