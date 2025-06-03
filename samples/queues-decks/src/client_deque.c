#include "client_deque.h"

ClientDeque* initClientDeque() {
    
}

void freeClientDeque(ClientDeque *deque);
void addClientToFront(ClientDeque *deque, int clientId);
void addClientToRear(ClientDeque *deque, int clientId);
void removeClientFromFront(ClientDeque *deque);
void removeClientFromRear(ClientDeque *deque);
int isClientDequeEmpty(ClientDeque *deque);
int isClientDequeFull(ClientDeque *deque);
int getClientDequeSize(ClientDeque *deque);
