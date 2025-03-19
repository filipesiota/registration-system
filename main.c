#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define CODE_LENGTH 10
#define NAME_LENGTH 50
#define SUBJECTS_LENGTH 8
#define TOTAL_FIELDS 13
#define DATABASE_T "database.txt"
#define DATABASE_B "database.dat"

// Struct definitions
typedef struct {
	int day;
	int month;
	int year;
} Date;

typedef struct {
	char registration[CODE_LENGTH];
	char name[NAME_LENGTH];
	char course_code[CODE_LENGTH];
	Date born_date;
	Date join_school_date;
	char subject_codes[SUBJECTS_LENGTH][CODE_LENGTH];
} Student;

typedef struct {
	Student *data;
	int size;
} StudentArray;

// Helper functions declarations
void normalize_string(char *string);
void sys_command(char *string);
void print_student(Student *student);
void save_into_text_database(StudentArray *studentArray);
void load_from_text_database(StudentArray *studentArray);
void save_into_binary_database(StudentArray *studentArray);
void load_from_binary_database(StudentArray *studentArray);

// Action functions declarations
void register_student(StudentArray *studentArray);
void delete_student(StudentArray *studentArray);
void update_student_subjects(StudentArray *studentArray);
void show_students(StudentArray *studentArray);
void show_student(StudentArray *studentArray);

// Main function implementation
int main() {
	StudentArray studentArray;
	int i;
	int option;
	
	studentArray.data = NULL;
	studentArray.size = 0;
	
	setlocale(LC_ALL, "Portuguese");

	do {
		sys_command("clear_terminal");
		printf("# Menu de opcoes:\n");

		printf("\n(1) Cadastrar aluno");
		printf("\n(2) Excluir aluno");
		printf("\n(3) Alterar disciplinas");
		printf("\n(4) Listar todos os alunos");
		printf("\n(5) Exibir aluno");
		printf("\n(6) Criar backup (texto)");
		printf("\n(7) Restaurar dados do backup (texto)");
		printf("\n(8) Criar backup (binario)");
		printf("\n(9) Restaurar dados do backup (binario)");
		printf("\n(0) Finalizar programa");

		do {
			printf("\n\nEscolha uma das opcoes acima: ");
			scanf("%d", &option);
			sys_command("clear_stdin");

			if (option < 0 || option > 9) {
				printf("\nOpcao invalida!");
			}
		} while (option < 0 || option > 9);

		switch (option) {
			case 1:
				register_student(&studentArray);
				break;
			case 2:
				delete_student(&studentArray);
				break;
			case 3:
				update_student_subjects(&studentArray);
				break;
			case 4:
				show_students(&studentArray);
				break;
			case 5:
				show_student(&studentArray);
				break;
			case 6:
				save_into_text_database(&studentArray);
				break;
			case 7:
				load_from_text_database(&studentArray);
				break;
			case 8:
				save_into_binary_database(&studentArray);
				break;
			case 9:
				load_from_binary_database(&studentArray);
				break;
		}

		if (option != 0) {
			printf("\n# Acao finalizada!\n");
			sys_command("pause_terminal");
		}
	} while (option != 0);
		
	if (studentArray.size > 0) {
		free(studentArray.data);
	}

	sys_command("clear_terminal");
	printf("# Programa finalizado!\n");
	sys_command("pause_terminal");
	
	return 0;
}

// Helper functions implementations
void normalize_string(char *string) {
	size_t len = strlen(string);
	
	if (len > 0 && string[len - 1] == '\n') {
	    string[len - 1] = '\0';
	}
}

void sys_command(char *command) {
	#if defined(__linux__) || defined(__APPLE__)
		if (strcmp(command, "clear_terminal") == 0) {
			system("clear");
			return;
		}

		if (strcmp(command, "clear_stdin") == 0) {
			__fpurge(stdin);
			return;
		}

		if (strcmp(command, "pause_terminal") == 0) {
			printf("Pressione qualquer tecla para continuar...");
			int c = getchar();
			return;
		}
	#else
		if (strcmp(command, "clear_terminal") == 0) {
			system("cls");
			return;
		}

		if (strcmp(command, "clear_stdin") == 0) {
			fflush(stdin);
			return;
		}

		if (strcmp(command, "pause_terminal") == 0) {
			system("pause");
			return;
		}
	#endif
}

void print_student(Student *student) {
	int i;

	printf("\nMatricula: %s", student->registration);
	printf("\nNome: %s", student->name);
	printf("\nCodigo do curso: %s", student->course_code);
	printf("\nData de nascimento: %02d/%02d/%04d", student->born_date.day, student->born_date.month, student->born_date.year);
	printf("\nMes e ano de ingresso: %02d/%04d", student->join_school_date.month, student->join_school_date.year);
	printf("\nCodigo das disciplinas em que esta matriculado:");

	for (i = 0; i < SUBJECTS_LENGTH; i++) {
		if (strcmp(student->subject_codes[i], "0") == 0) {
			if (i == 0) {
				printf("\n\t[Nenhuma disciplina foi informada]");
			}

			break;
		}

		printf("\n\t- %s", student->subject_codes[i]);
	}

	printf("\n");
}

void save_into_text_database(StudentArray *studentArray) {
	FILE *database = fopen(DATABASE_T, "wt");
	int i;
	int j;
	
	sys_command("clear_terminal");
	printf("# Criar backup (texto)\n\n");
	
	if (database == NULL) {
		printf("[Ocorreu um erro ao tentar abrir o arquivo (texto) de banco de dados]\n");
		return;
	}
	
	fprintf(database, "%d\n", studentArray->size);
	
	for (i = 0; i < studentArray->size; i++) {
		Student student = studentArray->data[i];
		
		fprintf(database, "%s\n", student.registration);
		fprintf(database, "%s\n", student.name);
		fprintf(database, "%s\n", student.course_code);
		fprintf(database, "%d %d %d\n", student.born_date.day, student.born_date.month, student.born_date.year);
		fprintf(database, "%d %d\n", student.join_school_date.month, student.join_school_date.year);
		
		for (j = 0; j < SUBJECTS_LENGTH; j++) {
			fprintf(database, "%s\n", student.subject_codes[j]);
		}
	}
	
	fclose(database);
	printf("[Backup (texto) de banco de dados criado com sucesso]\n");
}

void load_from_text_database(StudentArray *studentArray) {
	FILE *database = fopen(DATABASE_T, "rt");
	int i;
	int j;
	
	sys_command("clear_terminal");
	printf("# Restaurar dados do backup (texto)\n\n");
	
	if (database == NULL) {
		printf("Ocorreu um erro ao tentar abrir o arquivo (texto) de banco de dados!\n");
		return;
	}
	
	if (studentArray->size > 0) {
		free(studentArray->data);
	}
	
	studentArray->data = NULL;
	studentArray->size = 0;
	
	if (feof(database)) {
		fclose(database);
		return;
	}
	
	fscanf(database, "%d\n", &studentArray->size);
	
	studentArray->data = malloc(studentArray->size * sizeof(Student));
	
	for (i = 0; i < studentArray->size; i++) {
		Student student;
		
		fgets(student.registration, CODE_LENGTH, database);
		normalize_string(student.registration);
		
		fgets(student.name, NAME_LENGTH, database);
		normalize_string(student.name);
		
		fgets(student.course_code, CODE_LENGTH, database);
		normalize_string(student.course_code);
		
		fscanf(database, "%d %d %d\n", &student.born_date.day, &student.born_date.month, &student.born_date.year);
		fscanf(database, "%d %d\n", &student.join_school_date.month, &student.join_school_date.year);
		
		for (j = 0; j < SUBJECTS_LENGTH; j++) {
			fgets(student.subject_codes[j], CODE_LENGTH, database);
			normalize_string(student.subject_codes[j]);
		}
		
		studentArray->data[i] = student;
	}
	
	fclose(database);
	printf("[Backup (texto) de banco de dados restaurado com sucesso]\n");
}

void save_into_binary_database(StudentArray *studentArray) {
	FILE *database = fopen(DATABASE_B, "wb");
	int i;
	int j;
	
	sys_command("clear_terminal");
	printf("# Criar backup (binario)\n\n");
	
	if (database == NULL) {
		printf("[Ocorreu um erro ao tentar abrir o arquivo (binario) de banco de dados]\n");
		return;
	}
	
	fwrite(&studentArray->size, sizeof(int), 1, database);
	
	for (i = 0; i < studentArray->size; i++) {
		Student student = studentArray->data[i];
		size_t str_size;
		
		str_size = strlen(student.registration);
		fwrite(&str_size, sizeof(size_t), 1, database);
		fwrite(student.registration, sizeof(char), str_size, database);
		
		str_size = strlen(student.name);
		fwrite(&str_size, sizeof(size_t), 1, database);
		fwrite(student.name, sizeof(char), str_size, database);
		
		str_size = strlen(student.course_code);
		fwrite(&str_size, sizeof(size_t), 1, database);
		fwrite(student.course_code, sizeof(char), str_size, database);
		
		fwrite(&student.born_date, sizeof(Date), 1, database);
		fwrite(&student.join_school_date, sizeof(Date), 1, database);
		
		for (j = 0; j < SUBJECTS_LENGTH; j++) {
			str_size = strlen(student.subject_codes[j]);
			fwrite(&str_size, sizeof(size_t), 1, database);		
			fwrite(student.subject_codes[j], sizeof(char), str_size, database);
		}
	}
	
	fclose(database);
	printf("[Backup (binario) de banco de dados criado com sucesso]\n");
}

void load_from_binary_database(StudentArray *studentArray) {
	FILE *database = fopen(DATABASE_B, "rb");
	int i;
	int j;
	
	sys_command("clear_terminal");
	printf("# Restaurar dados do backup (binario)\n\n");
	
	if (database == NULL) {
		printf("Ocorreu um erro ao tentar abrir o arquivo (binario) de banco de dados!\n");
		return;
	}
	
	if (studentArray->size > 0) {
		free(studentArray->data);
	}
	
	studentArray->data = NULL;
	studentArray->size = 0;
	
	if (feof(database)) {
		fclose(database);
		return;
	}
	
	fread(&studentArray->size, sizeof(int), 1, database);
	
	studentArray->data = malloc(studentArray->size * sizeof(Student));
	
	for (i = 0; i < studentArray->size; i++) {
		Student student;
		size_t str_size;
		
		fread(&str_size, sizeof(size_t), 1, database);
		fread(student.registration, sizeof(char), str_size, database);
		student.registration[str_size] = '\0';
		
		fread(&str_size, sizeof(size_t), 1, database);
		fread(student.name, sizeof(char), str_size, database);
		student.name[str_size] = '\0';
		
		fread(&str_size, sizeof(size_t), 1, database);
		fread(student.course_code, sizeof(char), str_size, database);
		student.course_code[str_size] = '\0';
		
		fread(&student.born_date, sizeof(Date), 1, database);
		fread(&student.join_school_date, sizeof(Date), 1, database);
		
		for (j = 0; j < SUBJECTS_LENGTH; j++) {			
			fread(&str_size, sizeof(size_t), 1, database);
			fread(student.subject_codes[j], sizeof(char), str_size, database);
			student.subject_codes[j][str_size] = '\0';
		}
		
		studentArray->data[i] = student;
	}
	
	fclose(database);
	printf("[Backup (binario) de banco de dados restaurado com sucesso]\n");
}

// Action functions implementations
void register_student(StudentArray *studentArray) {
	Student student;
	int scannedLength;
	int askForSubject;
	int i;
	
	sys_command("clear_terminal");
	printf("# Cadastrar aluno\n\n");

	do {
		printf("Numero de matricula (nao pode ser o valor 0): ");
		sys_command("clear_stdin");
		fgets(student.registration, CODE_LENGTH, stdin);
		normalize_string(student.registration);

		if (strcmp(student.registration, "0") == 0) {
			printf("\nMatricula invalida!\n\n");
		} else {
			for (i = 0; i < studentArray->size; i++) {
				if (strcmp(studentArray->data[i].registration, student.registration) == 0) {
					printf("\nA matricula informada ja existe em nossa base de dados!\n");
					return;
				}
			}
		}
	} while (strcmp(student.registration, "0") == 0);	
	
	printf("Nome: ");
	sys_command("clear_stdin");
	fgets(student.name, NAME_LENGTH, stdin);
	normalize_string(student.name);
	
	printf("Codigo do curso: ");
	sys_command("clear_stdin");
	fgets(student.course_code, CODE_LENGTH, stdin);
	normalize_string(student.course_code);
	
	do {
		printf("Data de nascimento (DD/MM/AAAA): ");
		sys_command("clear_stdin");
		scannedLength = scanf("%d/%d/%d", &student.born_date.day, &student.born_date.month, &student.born_date.year);
	
		if (scannedLength != 3) {
	        printf("\nData invalida!\n\n");
	    }
	} while (scannedLength != 3);
	
	do {
		printf("Mes e ano de ingresso (MM/AAAA): ");
		sys_command("clear_stdin");
		scannedLength = scanf("%d/%d", &student.join_school_date.month, &student.join_school_date.year);
	
		if (scannedLength != 2) {
	        printf("\nData invalida!\n\n");
	    }
	} while (scannedLength != 2);

	askForSubject = 1;
	
	for (i = 0; i < SUBJECTS_LENGTH; i++) {
		if (askForSubject == 1) {
			printf("Informe o codigo de uma disciplina que o aluno esteja cursando (serao aceitas no maximo %d) ou 0 para finalizar o cadastro: ", SUBJECTS_LENGTH);
			sys_command("clear_stdin");
			fgets(student.subject_codes[i], CODE_LENGTH, stdin);
			normalize_string(student.subject_codes[i]);
			
			if (strcmp(student.subject_codes[i], "0") == 0) {
				askForSubject = 0;
			}
		} else {
			strcpy(student.subject_codes[i], "0");
		}
	}

	if (studentArray->data == NULL) {
		studentArray->data = malloc(sizeof(Student));
	} else {
		Student *temp = realloc(studentArray->data, (studentArray->size + 1) * sizeof(Student));

		if (temp == NULL) {
			printf("\nOcorreu um erro ao tentar realocar a memoria para cadastrar um novo aluno e os dados serao perdidos. Por favor, tente novamente!\n");
		} else {
			studentArray->data = temp;
		}
	}
	
	studentArray->data[studentArray->size] = student;
	studentArray->size++;
}

void delete_student(StudentArray *studentArray) {
	int newSize = studentArray->size - 1;
	Student *temp = (Student *)malloc(newSize * sizeof(Student));
	char registration[CODE_LENGTH];
	int tempCounter;
	int i;
	
	sys_command("clear_terminal");
	printf("# Excluir aluno\n\n");

	if (studentArray->size == 0) {
		printf("[Nenhum aluno cadastrado]\n");
		return;
	}

	do {
		printf("Informe o numero da matricula do aluno que deseja excluir ou 0 para voltar: ");
		sys_command("clear_stdin");
		fgets(registration, CODE_LENGTH, stdin);
		normalize_string(registration);

		if (strcmp(registration, "0") == 0) {
			return;
		}
		
		tempCounter = 0;
		
		for (i = 0; i < studentArray->size; i++) {
			if (strcmp(studentArray->data[i].registration, registration) == 0) {
				continue;
			}
			
			if (tempCounter < newSize) {
				temp[tempCounter] = studentArray->data[i];
			}
			
			tempCounter++;
		}
		
		if (tempCounter > newSize) {
			printf("\nMatricula nao encontrada!\n\n");
		}
	} while (tempCounter > newSize);
	
	studentArray->data = temp;
	studentArray->size--;
}

void update_student_subjects(StudentArray *studentArray) {
	char registration[CODE_LENGTH];
	int foundStudent;
	int i;
	int askForSubject;
	Student *student;

	sys_command("clear_terminal");
	printf("# Alterar disciplinas\n\n");

	if (studentArray->size == 0) {
		printf("[Nenhum aluno cadastrado]\n");
		return;
	}

	do {
		printf("Informe o numero da matricula do aluno que deseja efetuar a acao ou 0 para voltar: ");
		sys_command("clear_stdin");
		fgets(registration, CODE_LENGTH, stdin);
		normalize_string(registration);

		if (strcmp(registration, "0") == 0) {
			return;
		}
		
		foundStudent = 0;
		
		for (i = 0; i < studentArray->size; i++) {
			if (strcmp(studentArray->data[i].registration, registration) == 0) {
				foundStudent = 1;
				student = &studentArray->data[i];
				break;
			}
		}

		if (foundStudent == 0) {
			printf("\nMatricula nao encontrada!\n\n");
		}
	} while (foundStudent == 0);

	askForSubject = 1;

	for (i = 0; i < SUBJECTS_LENGTH; i++) {
		if (askForSubject == 1) {
			printf("Informe o codigo de uma disciplina que o aluno esteja cursando (serao aceitas no maximo %d) ou 0 para finalizar a alteracao: ", SUBJECTS_LENGTH);
			sys_command("clear_stdin");
			fgets(student->subject_codes[i], CODE_LENGTH, stdin);
			normalize_string(student->subject_codes[i]);
			
			if (strcmp(student->subject_codes[i], "0") == 0) {
				askForSubject = 0;
			}
		} else {
			strcpy(student->subject_codes[i], "0");
		}
	}
}

void show_students(StudentArray *studentArray) {
	int i;

	sys_command("clear_terminal");
	printf("# Listar todos os alunos\n\n");

	if (studentArray->size == 0) {
		printf("[Nenhum aluno cadastrado]\n");
		return;
	}

	printf("========================================");
	
	for (i = 0; i < studentArray->size; i++) {
		print_student(&studentArray->data[i]);
		printf("========================================");
	}

	printf("\n");
}

void show_student(StudentArray *studentArray) {
	char registration[CODE_LENGTH];
	int foundStudent;
	int i;

	sys_command("clear_terminal");
	printf("# Exibir aluno\n\n");

	if (studentArray->size == 0) {
		printf("[Nenhum aluno cadastrado]\n");
		return;
	}

	do {
		printf("Informe o numero da matricula do aluno que deseja efetuar a acao ou 0 para voltar: ");
		sys_command("clear_stdin");
		fgets(registration, CODE_LENGTH, stdin);
		normalize_string(registration);

		if (strcmp(registration, "0") == 0) {
			return;
		}
		
		foundStudent = 0;
		
		for (i = 0; i < studentArray->size; i++) {
			if (strcmp(studentArray->data[i].registration, registration) == 0) {
				foundStudent = 1;

				printf("\n========================================");
				print_student(&studentArray->data[i]);
				printf("========================================\n");
				break;
			}
		}

		if (foundStudent == 0) {
			printf("\nMatricula nao encontrada!\n\n");
		}
	} while (foundStudent == 0);
}
