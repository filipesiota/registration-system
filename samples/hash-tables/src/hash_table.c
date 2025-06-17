#include "hash_table.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*======================
# Funções Utilitárias
======================*/

// Função de hash simples: soma os valores ASCII dos caracteres da chave
int hash(HashTable* table, const char* str) {
  int hash = 0;
  while (*str) {
    hash += *str++;
  }
  return hash % table->capacity; // Garante que o índice esteja dentro da capacidade da tabela
}

// Calcula o fator de carga da tabela (quantidade de elementos / capacidade)
float calculateLoadFactor(HashTable* table) {
  return (float)table->size / (float)table->capacity;
}

// Recria a tabela com o dobro da capacidade e reinsere todos os elementos
void rehash(HashTable** tableRef) {
  HashTable* oldTable = *tableRef;
  HashTable* newTable = initHashTable(oldTable->capacity * 2);

  for (int i = 0; i < oldTable->capacity; i++) {
    HashTableNode* node = oldTable->array[i];

    while (node) {
      setValueForKey(&newTable, node->value, node->key);
      node = node->next;
    }
  }

  freeHashTable(oldTable);
  *tableRef = newTable;
}

/*======================
# Funções Principais
======================*/

// Inicializa uma nova tabela hash com a capacidade especificada
HashTable* initHashTable(int capacity) {
  HashTable *table = malloc(sizeof(HashTable));
  if (!table) return NULL;

  HashTableNode **array = malloc(sizeof(HashTableNode*) * capacity);
  if (!array) {
    free(table);
    return NULL;
  }

  table->size = 0;
  table->capacity = capacity;
  table->array = array;

  return table;
}

// Libera toda a memória alocada pela tabela e seus elementos
void freeHashTable(HashTable *table) {
  if (!table) return;

  for (int i = 0; i < table->capacity; i++) {
    HashTableNode *node = table->array[i];

    while (node) {
      HashTableNode *temp = node;
      node = node->next;

      free(temp->key);
      free(temp);
    }
  }

  free(table->array);
  free(table);
}

// Insere ou atualiza um valor associado a uma chave na tabela
void setValueForKey(HashTable** tableRef, int value, const char* key) {
  HashTable *table = *tableRef;
  int index = hash(table, key);
  HashTableNode* node = table->array[index];

  // Atualiza valor se a chave já existir
  while (node) {
    if (strcmp(node->key, key) == 0) {
      node->value = value;
      return;
    }

    node = node->next;
  }

  // Cria novo nó e insere no início da lista encadeada do índice
  HashTableNode* newNode = malloc(sizeof(HashTableNode));
  newNode->key = strdup(key);
  newNode->value = value;
  newNode->next = table->array[index];
  table->array[index] = newNode;
  table->size++;

  // Rehash se o fator de carga for excedido
  if (calculateLoadFactor(table) > HASH_TABLE_MAX_LOAD_FACTOR) {
    rehash(tableRef);
  }
}

// Retorna ponteiro para o valor associado a uma chave, ou NULL se não existir
int* getValueFromKey(HashTable* table, const char* key) {
  int index = hash(table, key);
  HashTableNode* node = table->array[index];

  while (node) {
    if (strcmp(node->key, key) == 0) {
      return &node->value;
    }

    node = node->next;
  }

  return NULL;
}

// Remove uma chave da tabela, se existir
void removeKey(HashTable* table, const char* key) {
  int index = hash(table, key);
  HashTableNode* node = table->array[index];
  HashTableNode* prev = NULL;

  while (node) {
    if (strcmp(node->key, key) == 0) {
      if (prev == NULL) {
        table->array[index] = node->next;
      } else {
        prev->next = node->next;
      }

      free(node->key);
      free(node);
      table->size--;
      return;
    }

    prev = node;
    node = node->next;
  }
}

// Exibe o estado atual da tabela hash no terminal
void printHashTable(HashTable* table) {
  printf("Capacidade: %d\n", table->capacity);
  printf("Utilizado: %d\n", table->size);
  printf("Fator de carga: %.2f\n\n", calculateLoadFactor(table));

  if (!table->size) {
    printf("[Nenhuma idade de aluno inserida]\n");
    return;
  }

  int i;

  for (i = 0; i < table->capacity; i++) {
    HashTableNode *node = table->array[i];

    while (node) {
      printf("[%d] %s = %d\n", i, node->key, node->value);
      node = node->next;
    }
  }
}
