#include "client_deque.h"

#include <stdio.h>
#include <stdlib.h>

ClientDeque* initClientDeque() {
  ClientDeque *deque = malloc(sizeof(ClientDeque));
  if (!deque) return NULL;

  deque->front = 1;
  deque->rear = -1;
  deque->size = 0;
  deque->capacity = MAX_CLIENT_DEQUE_SIZE;

  return deque;
}

void freeClientDeque(ClientDeque *deque) {
  if (!deque) return;
  free(deque);
}

void addClientToFront(ClientDeque *deque, int clientId) {
  if (isClientDequeFull(deque)) {
    printf("O deque esta cheio!\n");
    return;
  }

  deque->front = (deque->front - 1) % deque->capacity;
  deque->size++;
  deque->clients[deque->front] = clientId;

  if (isClientDequeEmpty(deque)) {
    deque->rear = deque->front;
  }
}

void addClientToRear(ClientDeque *deque, int clientId) {
  if (isClientDequeFull(deque)) {
    printf("O deque esta cheio!\n");
    return;
  }

  deque->rear = (deque->rear + 1) % deque->capacity;
  deque->size++;
  deque->clients[deque->rear] = clientId;

  if (isClientDequeEmpty(deque)) {
    deque->front = deque->rear;
  }
}

int* removeClientFromFront(ClientDeque *deque) {
  if (isClientDequeEmpty(deque)) {
    printf("O deque esta vazio!\n");
    return NULL;
  }

  int* removedClient = malloc(sizeof(int));
  if (!removedClient) return NULL;
  *removedClient = deque->clients[deque->front];

  deque->front = (deque->front + 1) % deque->capacity;
  deque->size--;

  return removedClient;
}

int* removeClientFromRear(ClientDeque *deque) {
  if (isClientDequeEmpty(deque)) {
    printf("O deque esta vazio!\n");
    return NULL;
  }

  int* removedClient = malloc(sizeof(int));
  if (!removedClient) return NULL;
  *removedClient = deque->clients[deque->rear];

  deque->rear = (deque->rear - 1) % deque->capacity;
  deque->size--;

  return removedClient;
}

int isClientDequeEmpty(ClientDeque *deque) {
  if (deque->size == 0) {
    return 1;
  }

  return 0;
}

int isClientDequeFull(ClientDeque *deque) {
  if (deque->size == deque->capacity) {
    return 1;
  }

  return 0;
}

int getClientDequeSize(ClientDeque *deque) {
  return deque->size;
}
