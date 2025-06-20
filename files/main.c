#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATABASE_T "database.txt"
#define DATABASE_B "database.dat"

int write_file_t();
int read_file_t();
int write_file_b();
int read_file_b();

int main() {
    write_file_b();
    read_file_b();

    system("pause");
    return 0;
}

int write_file_t() {
    FILE *database = fopen(DATABASE_T, "wt");

    if (database == NULL) {
        printf("Failed to open database text file!\n");
        system("pause");
        exit(1);
    }

    fprintf(database, "Teste 01\nTeste 02");

    fclose(database);
    return 0;
}

int read_file_t() {
    FILE *database = fopen(DATABASE_T, "rt");
    char aux[100];

    if (database == NULL) {
        printf("Failed to open database text file!\n");
        system("pause");
        exit(1);
    }

    // Corrected feof usage
    while (fgets(aux, sizeof(aux), database) != NULL) {
        printf("%s", aux);
    }

    printf("\n");

    fclose(database);
    return 0;
}

int write_file_b() {
    FILE *database = fopen(DATABASE_B, "wb");

    if (database == NULL) {
        printf("Failed to open database binary file!\n");
        system("pause");
        exit(1);
    }

    char text[] = "Teste 01\nTeste 02"; // Only use needed size

    fwrite(text, sizeof(char), strlen(text), database); // Correct fwrite size

    fclose(database);
    return 0;
}

int read_file_b() {
    FILE *database = fopen(DATABASE_B, "rb");
    char aux[100];
    size_t bytesRead;

    if (database == NULL) {
        printf("Failed to open database binary file!\n");
        system("pause");
        exit(1);
    }

    while ((bytesRead = fread(aux, sizeof(char), sizeof(aux) - 1, database)) > 0) {
        aux[bytesRead] = '\0'; // Null-terminate manually
        printf("%s", aux);
    }

    printf("\n");

    fclose(database);
    return 0;
}

