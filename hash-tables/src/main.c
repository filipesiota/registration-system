#include <stdio.h>
#include <stdlib.h>

#include "common/util.h"
#include "common/menu.h"
#include "hash_table.h"

void addStudentAge(HashTable **table);
void removeStudentAge(HashTable *table);
void listStudentsAge(HashTable *table);
void getStudentAge(HashTable *table);

int main() {
    HashTable *table = initHashTable(HASH_TABLE_INITIAL_CAPACITY);
    int option;

    do {
        option = getSelectedMenuOption();

        if (option != 0) {
            sysCommand("clear_terminal");
            printf("%s\n\n", getMenuOptionText(option));

            switch (option) {
                case 1:
                    addStudentAge(&table);
                    break;
                case 2:
                    removeStudentAge(table);
                    break;
                case 3:
                    listStudentsAge(table);
                    break;
                case 4:
                    getStudentAge(table);
                    break;
            }

            printf("\nAcao finalizada!\n");
            sysCommand("pause_terminal");
        }
    } while (option != 0);

    freeHashTable(table);
    printf("\nPrograma finalizado!\n");
    sysCommand("pause_terminal");

    return 0;
}

void addStudentAge(HashTable **table) {
    char studentName[HASH_TABLE_KEY_LENGTH];
    int age;

    printf("Informe o nome do aluno: ");
    sysCommand("clear_stdin");
    fgets(studentName, HASH_TABLE_KEY_LENGTH, stdin);
    normalizeString(studentName);

    printf("Informe a idade do aluno: ");
    scanf("%d", &age);

    setValueForKey(table, age, studentName);
}

void removeStudentAge(HashTable *table) {
    char studentName[HASH_TABLE_KEY_LENGTH];

    printf("Informe o nome do aluno: ");
    sysCommand("clear_stdin");
    fgets(studentName, HASH_TABLE_KEY_LENGTH, stdin);
    normalizeString(studentName);

    removeKey(table, studentName);
}

void listStudentsAge(HashTable *table) {
    printHashTable(table);
}

void getStudentAge(HashTable *table) {
    char studentName[HASH_TABLE_KEY_LENGTH];
    int *age;

    printf("Informe o nome do aluno: ");
    sysCommand("clear_stdin");
    fgets(studentName, HASH_TABLE_KEY_LENGTH, stdin);
    normalizeString(studentName);

    age = getValueFromKey(table, studentName);
    if (age == NULL) {
        printf("\n[Nenhum aluno encontrado]\n");
        return;
    }

    printf("\n%s = %d\n", studentName, *age);
}
