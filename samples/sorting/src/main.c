#include <stdio.h>

#include "integer_array_list.h"
#include "insertion_sort.h"
#include "bogosort.h"
#include "sorting_utils.h"

int main() {
    int range;
    IntegerArrayList *list = initIntegerArrayList();

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &range);

    int i;
    for (i = 0; i < range; i++) {
        int n;
        printf("Valor %d: ", i + 1);
        scanf("%d", &n);

        addIntegerArrayList(list, n);
    }

    IntegerArrayList *listCopyForInsertionSort = copyIntegerArrayList(list);
    IntegerArrayList *listCopyForBogosort = copyIntegerArrayList(list);

    IntegerArrayListSorted *insertionSortResult = insertionSort(listCopyForInsertionSort);
    IntegerArrayListSorted *bogosortResult = bogosort(listCopyForBogosort);

    printf("\n# Insertion Sort:");
    printf("\nResultado: ");
    printIntegerArrayList(insertionSortResult->sortedList);
    printf("Tempo de execucao: %.10lf ms\n", insertionSortResult->executionTime);

    printf("\n# Bogosort:");
    printf("\nResultado: ");
    printIntegerArrayList(bogosortResult->sortedList);

    if (bogosortResult->executionTime > -1.0) {
        printf("Tempo de execucao: %.10lf ms\n\n", bogosortResult->executionTime);
    } else {
        printf("Tempo de execucao: Nao foi concluido (demorou mais que %d ms)\n\n", BOGOSORT_MAX_EXECUTION_MS);
    }

    sysCommand("pause_terminal");
    return 0;
}
