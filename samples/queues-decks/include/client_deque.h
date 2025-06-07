#ifndef CLIENT_DEQUE_H
#define CLIENT_DEQUE_H

#define MAX_CLIENT_DEQUE_SIZE 5

typedef struct {
    int clients[MAX_CLIENT_DEQUE_SIZE];
    int front;
    int rear;
    int size;
    int capacity;
} ClientDeque;

ClientDeque* initClientDeque();
void freeClientDeque(ClientDeque *deque);
void addClientToFront(ClientDeque *deque, int clientId);
void addClientToRear(ClientDeque *deque, int clientId);
int* removeClientFromFront(ClientDeque *deque);
int* removeClientFromRear(ClientDeque *deque);
int isClientDequeEmpty(ClientDeque *deque);
int isClientDequeFull(ClientDeque *deque);
int getClientDequeSize(ClientDeque *deque);

#endif
