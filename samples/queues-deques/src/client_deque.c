#include "client_deque.h"

#include <stdio.h>
#include <stdlib.h>

ClientDeque* initClientDeque() {
  ClientDeque *deque = malloc(sizeof(ClientDeque));
  if (!deque) return NULL;

  deque->front = NULL;
  deque->rear = NULL;
  deque->size = 0;

  return deque;
}

void freeClientDeque(ClientDeque *deque) {
  if (!deque) return;

  ClientNode *node;

  while (deque->front) {
    node = deque->front;
    deque->front = deque->front->next;
    free(node);
  }

  free(deque);
}

void addClientToFront(ClientDeque *deque, int clientId) {
  ClientNode *newNode = malloc(sizeof(ClientNode));
  if (!newNode) return;

  newNode->clientId = clientId;
  newNode->prev = NULL;
  newNode->next = deque->front;

  if (deque->front) {
    deque->front->prev = newNode;
  }

  deque->front = newNode;

  if (deque->rear == NULL) {
    deque->rear = newNode;
  }

  deque->size++;
}

void addClientToRear(ClientDeque *deque, int clientId) {
  ClientNode *newNode = malloc(sizeof(ClientNode));
  if (!newNode) return;

  newNode->clientId = clientId;
  newNode->next = NULL;
  newNode->prev = deque->rear;

  if (deque->rear) {
    deque->rear->next = newNode;
  }

  deque->rear = newNode;

  if (deque->front == NULL) {
    deque->front = newNode;
  }

  deque->size++;
}

int* removeClientFromFront(ClientDeque *deque) {
  if (isClientDequeEmpty(deque)) {
    printf("O deque esta vazio!\n");
    return NULL;
  }

  int* removedClient = malloc(sizeof(int));
  if (!removedClient) return NULL;
  *removedClient = deque->front->clientId;

  ClientNode *node = deque->front;
  deque->front = deque->front->next;

  if (deque->front) {
    deque->front->prev = NULL;
  } else {
    deque->rear = NULL;
  }

  free(node);
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
  *removedClient = deque->rear->clientId;

  ClientNode *node = deque->rear;
  deque->rear = deque->rear->prev;

  if (deque->rear) {
    deque->rear->next = NULL;
  } else {
    deque->front = NULL;
  }

  free(node);
  deque->size--;

  return removedClient;
}

int isClientDequeEmpty(ClientDeque *deque) {
  return !deque || deque->front == NULL;
}

void printClientDeque(ClientDeque *deque) {
  if (isClientDequeEmpty(deque)) {
    printf("[Vazia]\n");
    return;
  }

  ClientNode *node = deque->front;

  while (node) {
    if (node->prev) {
      printf(" -> %d", node->clientId);
    } else {
      printf("%d", node->clientId);
    }
  }

  printf("\n");
}
