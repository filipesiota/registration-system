#ifndef INTEGER_ARRAY_LIST_H
#define INTEGER_ARRAY_LIST_H

typedef struct {
    int size;
    int* arr;
} IntegerArrayList;

typedef struct {
    double executionTime;
    int loops;
    IntegerArrayList *sortedList;
} IntegerArrayListSorted;

IntegerArrayList* initIntegerArrayList();
void freeIntegerArrayList(IntegerArrayList *list);
IntegerArrayListSorted* initIntegerArrayListSorted();
void freeIntegerArrayListSorted(IntegerArrayListSorted *sortedList);
void addIntegerArrayList(IntegerArrayList *list, int value);
void removeIntegerArrayList(IntegerArrayList *list, int index);
void printIntegerArrayList(IntegerArrayList *list);
IntegerArrayList* copyIntegerArrayList(IntegerArrayList *original);

#endif
