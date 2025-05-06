#include "insertion_sort.h"

#include <stdlib.h>

#include "sorting_utils.h"

IntegerArrayListSorted* insertionSort(IntegerArrayList *list) {
    if (list->arr == NULL) return NULL;

    clock_t startTime = clock();
    int loops = 0;

    int i;
    for (i = 1; i < list->size; i++) {
        int value = list->arr[i];
        int j = i - 1;

        while (j >= 0 && list->arr[j] > value) {
            list->arr[j + 1] = list->arr[j];
            j--;
            loops++;
        }
        list->arr[j + 1] = value;
    }

    clock_t endTime = clock();

    IntegerArrayListSorted *result = initIntegerArrayListSorted();
    result->executionTime = calculateDurationInMilliseconds(startTime, endTime);
    result->loops = loops;
    result->sortedList = list;

    return result;
}
