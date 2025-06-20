#include "integer_array_list.h"

#include <stdio.h>
#include <stdlib.h>

IntegerArrayList* initIntegerArrayList() {
    IntegerArrayList *list = malloc(sizeof(IntegerArrayList));

    list->size = 0;
    list->arr = NULL;

    return list;
}

void freeIntegerArrayList(IntegerArrayList *list) {
    if (list == NULL) return;

    if (list->arr != NULL) {
        free(list->arr);
        list->arr = NULL;
    }

    free(list);
    list = NULL;
}

IntegerArrayListSorted* initIntegerArrayListSorted() {
    IntegerArrayListSorted *sortedList = malloc(sizeof(IntegerArrayListSorted));

    sortedList->executionTime = 0;
    sortedList->loops = 0;
    sortedList->sortedList = NULL;

    return sortedList;
}

void freeIntegerArrayListSorted(IntegerArrayListSorted *sortedList) {
    if (sortedList == NULL) return;

    if (sortedList->sortedList != NULL) {
        free(sortedList->sortedList);
        sortedList->sortedList = NULL;
    }

    free(sortedList);
    sortedList = NULL;
}

void addIntegerArrayList(IntegerArrayList *list, int value) {
    int *temp = realloc(list->arr, sizeof(int) * (list->size + 1));
    if (temp == NULL) return;

    list->arr = temp;
    list->arr[list->size] = value;
    list->size++;
}

void removeIntegerArrayList(IntegerArrayList *list, int index) {
    if (list->arr == NULL) return;

    if (list->size == 1) {
        free(list->arr);
        list->arr = NULL;
    } else {
        list->arr = realloc(list->arr, sizeof(int) * (list->size - 1));
    }

    list->size--;
}

void printIntegerArrayList(IntegerArrayList *list) {
    if (list->arr == NULL) {
        printf("[Vazio]\n");
        return;
    }

    printf("[ %d", list->arr[0]);

    int i;
    for (i = 1; i < list->size; i++) {
        printf(", %d", list->arr[i]);
    }

    printf(" ]\n");
}

void printIntegerArrayListWithHighlight(IntegerArrayList *list, int highlightIndex) {
    if (list->arr == NULL) {
        printf("[Vazio]\n");
        return;
    }

    if (highlightIndex == 0) {
        printf("[ (%d)", list->arr[0]);
    } else {
        printf("[ %d", list->arr[0]);
    }

    int i;
    for (i = 1; i < list->size; i++) {
        if (i == highlightIndex) {
            printf(", (%d)", list->arr[i]);
        } else {
            printf(", %d", list->arr[i]);
        }
    }

    printf(" ]\n");
}

IntegerArrayList* copyIntegerArrayList(IntegerArrayList *original) {
    IntegerArrayList *copy = initIntegerArrayList();

    for (int i = 0; i < original->size; i++) {
        addIntegerArrayList(copy, original->arr[i]);
    }

    return copy;
}
