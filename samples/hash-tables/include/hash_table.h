#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define HASH_TABLE_INITIAL_CAPACITY 5
#define HASH_TABLE_MAX_LOAD_FACTOR 0.5
#define HASH_TABLE_KEY_LENGTH 100

typedef struct HashTableNode HashTableNode;

struct HashTableNode {
    char *key;
    int value;
    HashTableNode *next;
};

typedef struct {
    int capacity;
    int size;
    HashTableNode **array;
} HashTable;

HashTable* initHashTable(int capacity);
void freeHashTable(HashTable* table);
void setValueForKey(HashTable** table, int value, const char* key);
int* getValueFromKey(HashTable* table, const char* key);
void removeKey(HashTable* table, const char* key);
void printHashTable(HashTable* table);

#endif
