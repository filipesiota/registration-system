#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define CODE_LENGTH 10
#define NAME_LENGTH 50
#define SUBJECTS_LENGTH 8

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

// Helper functions
void normalizeString(char *string);

// Action functions
void register_student(StudentArray *studentArray);
void delete_student(StudentArray *studentArray);
void update_student_subjects(StudentArray *studentArray);
void show_students(StudentArray *studentArray);
void show_student(StudentArray *studentArray);

int main() {
	StudentArray studentArray;
	int i;
	
	studentArray.data = NULL;
	studentArray.size = 0;
	
	setlocale(LC_ALL, "Portuguese");
	
	register_student(&studentArray);
	
	int curSize = studentArray.size;
	
	delete_student(&studentArray);
	
	int newSize = studentArray.size;
	
	system("cls");
	printf("UPDATED ARRAY SIZE: %d", curSize);
	printf("\nUPDATED ARRAY SIZE: %d", newSize);
	
	if (studentArray.size > 0) {
		free(studentArray.data);
	}
	
	printf("\n\n# Programa finalizado!\n");
	system("pause");
	
	return 0;
}

void normalizeString(char *string) {
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
	
	printf("N�mero de matr�cula: ");
	fflush(stdin);
	fgets(student.registration, CODE_LENGTH, stdin);
	normalizeString(student.registration);
	
	printf("Nome: ");
	fflush(stdin);
	fgets(student.name, NAME_LENGTH, stdin);
	normalizeString(student.name);
	
	printf("C�digo do curso: ");
	fflush(stdin);
	fgets(student.course_code, CODE_LENGTH, stdin);
	normalizeString(student.course_code);
	
	do {
		printf("Data de nascimento (DD/MM/AAAA): ");
		scannedLength = scanf("%d/%d/%d", &student.born_date.day, &student.born_date.month, &student.born_date.year);
	
		if (scannedLength != 3) {
	        printf("\nData inv�lida!\n\n");
	    }
	} while (scannedLength != 3);
	
	do {
		printf("M�s e ano de ingresso (MM/AAAA): ");
		scannedLength = scanf("%d/%d", &student.born_date.month, &student.born_date.year);
	
		if (scannedLength != 2) {
	        printf("\nData inv�lida!\n\n");
	    }
	} while (scannedLength != 2);
	
	for (i = 0; i < SUBJECTS_LENGTH; i++) {
		if (askForSubject == 1) {
			printf("Informe o c�digo de uma disciplina que o aluno esteja cursando ou 0 para finalizar o cadastro: ");
			fflush(stdin);
			fgets(student.subject_codes[i], CODE_LENGTH, stdin);
			normalizeString(student.subject_codes[i]);
			
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

void delete_student(StudentArray *studentArray) {
	int newSize = studentArray->size - 1;
	Student *temp = (Student *)malloc(newSize * sizeof(Student));
	char registration[CODE_LENGTH];
	int tempCounter;
	int i;
	
	system("cls");
	printf("# Excluir aluno\n\n");
	
	do {
		printf("Informe o n�mero da matr�cula do aluno que deseja excluir: ");
		fflush(stdin);
		fgets(registration, CODE_LENGTH, stdin);
		normalizeString(registration);
		
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
			printf("\nMatr�cula n�o encontrada!\n\n");
		}
	} while (tempCounter > newSize);
	
	studentArray->data = temp;
	studentArray->size--;
	free(temp);
	
	printf("\n# Exclus�o finalizada!\n");
	system("pause");
}

void update_student_subjects(StudentArray *studentArray) {
	
}

void show_students(StudentArray *studentArray) {
	
}

void show_student(StudentArray *studentArray) {
	
}

