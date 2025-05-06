#include <stdio.h>
#include <stdlib.h>

#include "integer_array_list.h"
#include "insertion_sort.h"
#include "bogosort.h"
#include "sorting_utils.h"

#define TEST_RANGE 100
#define TEST_RAND_RANGE 100

int main() {
    int range;
    IntegerArrayList *list = initIntegerArrayList();

    int test[TEST_RANGE];
    srand(time(NULL));

    for (int i = 0; i < TEST_RANGE; i++) {
        test[i] = rand() % TEST_RAND_RANGE;
    }

    for (int i = 0; i < TEST_RANGE; i++) {
        addIntegerArrayList(list, test[i]);
    }

    // printf("Informe o tamanho do vetor: ");
    // scanf("%d", &range);

    // int i;
    // for (i = 0; i < range; i++) {
    //     int n;
    //     printf("Valor %d: ", i + 1);
    //     scanf("%d", &n);

    //     addIntegerArrayList(list, n);
    // }

    IntegerArrayList *listCopyForInsertionSort = copyIntegerArrayList(list);
    IntegerArrayList *listCopyForBogosort = copyIntegerArrayList(list);

    IntegerArrayListSorted *insertionSortResult = insertionSort(listCopyForInsertionSort);
    IntegerArrayListSorted *bogosortResult = bogosort(listCopyForBogosort);

    printf("\n[Insertion Sort] Resultado: ");
    printIntegerArrayList(insertionSortResult->sortedList);
    printf("[Bogosort] Resultado: ");
    printIntegerArrayList(bogosortResult->sortedList);

    printf("\nOverview:\n\n");
    printf("[Insertion Sort] Tempo de execucao: %.10lf ms\n", insertionSortResult->executionTime);

    if (bogosortResult->executionTime > -1.0) {
        printf("[Bogosort] Tempo de execucao: %.10lf ms\n\n", bogosortResult->executionTime);
    } else {
        printf("[Bogosort] Tempo de execucao: Nao foi concluido (demorou mais que %d ms)\n\n", BOGOSORT_MAX_EXECUTION_MS);
    }

    sysCommand("pause_terminal");
    return 0;
}
