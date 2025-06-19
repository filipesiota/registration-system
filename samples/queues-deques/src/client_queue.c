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

    return queue;
}

void freeClientQueue(ClientQueue *queue) {
    if (!queue) return;
    free(queue);
}

void enqueueClient(ClientQueue *queue, int clientId) {
    if (isClientQueueFull(queue)) {
        printf("A fila esta cheia!\n");
        return;
    }

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->size++;
    queue->clients[queue->rear] = clientId;

    if (isClientQueueEmpty(queue)) {
        queue->front = queue->rear;
    }
}

int* dequeueClient(ClientQueue *queue) {
    if (isClientQueueEmpty(queue)) {
        printf("A fila esta vazia!\n");
        return NULL;
    }

    int *dequeuedClient = malloc(sizeof(int));
    if (!dequeuedClient) return NULL;
    *dequeuedClient = queue->clients[queue->front];

    queue->front = (queue->front + 1) % queue->capacity;
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

void printClientQueue(ClientQueue *queue) {
    if (isClientQueueEmpty(queue)) {
        printf("[Vazia]\n");
        return;
    }

    int currentIndex = queue->front;

    do {
        printf("%d", queue->clients[currentIndex]);

        if (currentIndex != queue->rear) {
            printf(" -> ");
        }

        currentIndex = (currentIndex + 1) % queue->capacity;
    } while (currentIndex != (queue->rear + 1) % queue->capacity);

    printf("\n");
}
