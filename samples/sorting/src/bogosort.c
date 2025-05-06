#include "bogosort.h"

#include <stdio.h>
#include <stdlib.h>

#include "sorting_utils.h"

int isSorted(IntegerArrayList *list) {
    int i;
    for (i = 1; i < list->size; i++) {
        if (list->arr[i - 1] > list->arr[i]) {
            return 0;
        }
    }

    return 1;
}

void shuffle(IntegerArrayList *list) {
    for (int i = 0; i < list->size; i++) {
        int r = rand() % list->size;
        int temp = list->arr[i];
        list->arr[i] = list->arr[r];
        list->arr[r] = temp;
    }
}

IntegerArrayListSorted* bogosort(IntegerArrayList *list) {
    if (list->arr == NULL) return NULL;

    clock_t startTime = clock();

    srand(time(NULL));

    while (!isSorted(list) && calculateDurationInMilliseconds(startTime, clock()) <= BOGOSORT_MAX_EXECUTION_MS) {
        shuffle(list);
    }

    clock_t endTime = clock();

    IntegerArrayListSorted *result = initIntegerArrayListSorted();
    result->executionTime = isSorted(list) ? calculateDurationInMilliseconds(startTime, endTime) : -1.0;
    result->sortedList = list;

    return result;
}
