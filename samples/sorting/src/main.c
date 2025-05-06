#include <stdio.h>
#include <stdlib.h>

#include "integer_array_list.h"
#include "insertion_sort.h"
#include "bogosort.h"
#include "sorting_utils.h"

#define AUTOGENERATE_LIST 1
#define AUTOGENERATION_SIZE 10
#define AUTOGENERATION_RANGE 50
#define HIDE_RESULTS 1

int main() {
    int range;
    IntegerArrayList *list = initIntegerArrayList();

    if (AUTOGENERATE_LIST) {
        printf("Gerando %d numeros aleatorios entre 0 e %d...\n\n", AUTOGENERATION_SIZE, AUTOGENERATION_RANGE);

        int test[AUTOGENERATION_SIZE];
        srand(time(NULL));
    
        for (int i = 0; i < AUTOGENERATION_SIZE; i++) {
            test[i] = rand() % AUTOGENERATION_RANGE;
        }
    
        for (int i = 0; i < AUTOGENERATION_SIZE; i++) {
            addIntegerArrayList(list, test[i]);
        }
    } else {
        printf("Informe o tamanho do vetor: ");
        scanf("%d", &range);

        int i;
        for (i = 0; i < range; i++) {
            int n;
            printf("Valor %d: ", i + 1);
            scanf("%d", &n);

            addIntegerArrayList(list, n);
        }
    }

    IntegerArrayList *listCopyForInsertionSort = copyIntegerArrayList(list);
    IntegerArrayListSorted *insertionSortResult = insertionSort(listCopyForInsertionSort);

    printf("\n[Insertion Sort] Tempo de execucao: %.10lf ms\n", insertionSortResult->executionTime);
    printf("[Insertion Sort] Loops: %d\n", insertionSortResult->loops);

    if (!HIDE_RESULTS) {
        printf("[Insertion Sort] Resultado: ");
        printIntegerArrayList(insertionSortResult->sortedList);
    }

    IntegerArrayList *listCopyForBogosort = copyIntegerArrayList(list);
    IntegerArrayListSorted *bogosortResult = bogosort(listCopyForBogosort);

    if (bogosortResult->executionTime > -1.0) {
        printf("\n[Bogosort] Tempo de execucao: %.10lf ms\n", bogosortResult->executionTime);
    } else {
        printf("\n[Bogosort] Tempo de execucao: Nao foi concluido (demorou mais que %d ms)\n", BOGOSORT_MAX_EXECUTION_MS);
    }

    printf("[Bogosort] Loops: %d\n", bogosortResult->loops);

    if (!HIDE_RESULTS) {
        printf("[Bogosort] Resultado: ");
        printIntegerArrayList(bogosortResult->sortedList);
    }

    freeIntegerArrayListSorted(bogosortResult); // Free the memory allocated for the result and the sorted list (listCopyForBogosort)
    freeIntegerArrayListSorted(insertionSortResult); // Free the memory allocated for the result and the sorted list (listCopyForInsertionSort)
    freeIntegerArrayList(list);

    sysCommand("pause_terminal");
    return 0;
}
