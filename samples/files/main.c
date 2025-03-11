#include <stdio.h>
#include <stdlib.h>

#define DATABASE "database.txt"

int write_file();
int read_file();

int main() {
	write_file();
	read_file();
	
	system("pause");
	return 0;
}

int write_file() {
	FILE *database = fopen(DATABASE, "wt");
	
	if (database == NULL) {
		printf("Failed to open database file!\n");
		system("pause");
		exit(1);
	}
	
	fprintf(database, "Teste 01\nTeste 02");
	
	fclose(database);
}

int read_file() {
	FILE *database = fopen(DATABASE, "rt");
	char aux[100];
	
	if (database == NULL) {
		printf("Failed to open database file!\n");
		system("pause");
		exit(1);
	}
	
	while (!feof(database)) {
		fgets(aux, 100, database);
		printf("%s", aux);
	}
	
	printf("\n");
	
	fclose(database);
}
