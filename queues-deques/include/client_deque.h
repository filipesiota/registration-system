#ifndef CLIENT_DEQUE_H
#define CLIENT_DEQUE_H

typedef struct ClientNode ClientNode;

struct ClientNode {
    int clientId;
    ClientNode *next;
    ClientNode *prev;
};

typedef struct {
    ClientNode *front;
    ClientNode *rear;
    int size;
} ClientDeque;

ClientDeque* initClientDeque();
void freeClientDeque(ClientDeque *deque);
void addClientToFront(ClientDeque *deque, int clientId);
void addClientToRear(ClientDeque *deque, int clientId);
int* removeClientFromFront(ClientDeque *deque);
int* removeClientFromRear(ClientDeque *deque);
int isClientDequeEmpty(ClientDeque *deque);
void printClientDeque(ClientDeque *deque);

#endif
