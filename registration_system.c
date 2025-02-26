#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define CODE_LENGTH 10
#define NAME_LENGTH 50
#define SUBJECTS_LENGTH 8

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

void clearString(char *string);

void register_student(StudentArray *studentArray);
void delete_student(StudentArray *studentArray, char *registration);
void update_student_subjects(StudentArray *studentArray, char *registration);
void show_students(StudentArray *studentArray);
void show_student(StudentArray *studentArray, char *registration);

int main() {
	StudentArray studentArray;
	int i;
	
	studentArray.data = NULL;
	studentArray.size = 0;
	
	setlocale(LC_ALL, "Portuguese");
	
	register_student(&studentArray);
	
	for (i = 0; i < studentArray.size; i++) {
		printf("\nNome do aluno cadastrado: %s", studentArray.data[i].name);
	}
	
	free(studentArray.data);
	return 0;
}

void clearString(char *string) {
	size_t len = strlen(string);
	
	if (len > 0 && string[len - 1] == '\n') {
	    string[len - 1] = '\0';
	}
}

void register_student(StudentArray *studentArray) {
	Student student;
	int scannedLength;
	int askForSubject = 1;
	int i;
	
	system("cls");
	printf("# Cadastrar aluno\n\n");
	
	printf("Número de matrícula: ");
	fflush(stdin);
	fgets(student.registration, CODE_LENGTH, stdin);
	clearString(student.registration);
	
	printf("Nome: ");
	fflush(stdin);
	fgets(student.name, NAME_LENGTH, stdin);
	clearString(student.name);
	
	printf("Código do curso: ");
	fflush(stdin);
	fgets(student.course_code, CODE_LENGTH, stdin);
	clearString(student.course_code);
	
	do {
		printf("Data de nascimento (DD/MM/AAAA): ");
		scannedLength = scanf("%d/%d/%d", &student.born_date.day, &student.born_date.month, &student.born_date.year);
	
		if (scannedLength != 3) {
	        printf("\nData inválida!\n\n");
	    }
	} while (scannedLength != 3);
	
	do {
		printf("Mês e ano de ingresso (MM/AAAA): ");
		scannedLength = scanf("%d/%d", &student.born_date.month, &student.born_date.year);
	
		if (scannedLength != 2) {
	        printf("\nData inválida!\n\n");
	    }
	} while (scannedLength != 2);
	
	for (i = 0; i < SUBJECTS_LENGTH; i++) {
		if (askForSubject == 1) {
			printf("Informe o código de uma disciplina que o aluno esteja cursando ou 0 para finalizar o cadastro: ");
			fflush(stdin);
			fgets(student.subject_codes[i], CODE_LENGTH, stdin);
			clearString(student.subject_codes[i]);
			
			if (strcmp(student.subject_codes[i], "0") == 0) {
				askForSubject = 0;
			}
		} else {
			strcpy(student.subject_codes[i], "0");
		}
	}
	
	if (studentArray->data == NULL) {
		studentArray->data = (Student *)malloc(sizeof(Student));
	} else {
		Student *temp = (Student *)realloc(studentArray->data, studentArray->size * sizeof(Student));
		studentArray->data = temp;
		free(temp);
	}
	
	studentArray->data[studentArray->size] = student;
	studentArray->size++;
	
	printf("\n# Cadastro finalizado!\n");
	system("pause");
}

void delete_student(StudentArray *studentArray, char *registration) {
	
}

void update_student_subjects(StudentArray *studentArray, char *registration) {
	
}

void show_students(StudentArray *studentArray) {
	
}

void show_student(StudentArray *studentArray, char *registration) {
	
}

