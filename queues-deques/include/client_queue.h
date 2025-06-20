#ifndef CLIENT_QUEUE_H
#define CLIENT_QUEUE_H

#define MAX_CLIENT_QUEUE_SIZE 5

typedef struct {
    int clients[MAX_CLIENT_QUEUE_SIZE];
    int front;
    int rear;
    int size;
    int capacity;
} ClientQueue;

ClientQueue* initClientQueue();
void freeClientQueue(ClientQueue *queue);
void enqueueClient(ClientQueue *queue, int clientId);
int* dequeueClient(ClientQueue *queue);
int isClientQueueEmpty(ClientQueue *queue);
int isClientQueueFull(ClientQueue *queue);
void printClientQueue(ClientQueue *queue);

#endif
