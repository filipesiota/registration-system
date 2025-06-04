#include "client_queue.h"

#include <stdlib.h>
#include <stdio.h>

ClientQueue* initClientQueue() {
    ClientQueue *queue = malloc(sizeof(ClientQueue));
    if (!queue) return NULL;

    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = MAX_CLIENT_QUEUE_SIZE;
}

void freeClientQueue(ClientQueue *queue) {
    if (queue == NULL) return;
    free(queue);
}

void enqueueClient(ClientQueue *queue, int clientId) {
    if (isClientQueueFull(queue)) {
        printf("A fila esta cheia!\n");
        return;
    }

    if (isClientQueueEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->size++;
    queue->clients[queue->rear] = clientId;
}

int* dequeueClient(ClientQueue *queue) {
    if (isClientQueueEmpty(queue)) {
        printf("A fila esta vazia!\n");
        return NULL;
    }

    int *dequeuedClient = malloc(sizeof(int));
    if (!dequeuedClient) return NULL;
    *dequeuedClient = queue->clients[queue->front];

    queue->front = (queue->front - 1) % queue->capacity;
    queue->size--;
}

int isClientQueueEmpty(ClientQueue *queue) {
    if (queue->size == 0) {
        return 1;
    }

    return 0;
}

int isClientQueueFull(ClientQueue *queue) {
    if (queue->size == queue->capacity) {
        return 1;
    }

    return 0;
}

int getClientQueueSize(ClientQueue *queue) {
    return queue->size;
}
