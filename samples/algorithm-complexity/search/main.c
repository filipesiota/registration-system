#include <stdio.h>
#include <stdlib.h>

#define MAIN_ARRAY_LENGTH 30

int linear_search(int *array, int length, int target);
int linear_search_with_sentinel(int *array, int length, int target);
int linear_search_sorted(int *array, int length, int target);
int binary_search(int *array, int length, int target);
int interpolation_search(int *array, int length, int target);
int approximate_search(int *array, int length, int target);

int main() {
	int search_array[MAIN_ARRAY_LENGTH] = {
		2,  5,  8, 11, 14,
	   17, 20, 23, 26, 29,
	   32, 35, 38, 41, 44,
	   47, 50, 53, 56, 59,
	   62, 65, 68, 71, 74,
	   77, 80, 83, 86, 89
   };

	int *array = malloc(MAIN_ARRAY_LENGTH * sizeof(int));
	int target;
	int i;

	for (i = 0; i < MAIN_ARRAY_LENGTH; i++) {
		array[i] = search_array[i];
	}

	printf("Informe um numero para procurar no vetor: ");
	scanf("%d", &target);
	
	printf("Linear Search: %d\n", linear_search(array, MAIN_ARRAY_LENGTH, target));
	printf("Linear Search With Sentinel: %d\n", linear_search_with_sentinel(array, MAIN_ARRAY_LENGTH, target));
	printf("Linear Search in Sorted List: %d\n", linear_search_sorted(array, MAIN_ARRAY_LENGTH, target));
	printf("Binary Search: %d\n", binary_search(array, MAIN_ARRAY_LENGTH, target));
	printf("Interpolation Search: %d\n", interpolation_search(array, MAIN_ARRAY_LENGTH, target));
	printf("Approximate Search: %d\n", approximate_search(array, MAIN_ARRAY_LENGTH, target));
	
	return 0;
}

int linear_search(int *array, int length, int target) {
	int i;
	
	for (i = 0; i < length; i++) {
		if (array[i] == target) {
			return i;
		}
	}
	
	return -1;
}

int linear_search_with_sentinel(int *array, int length, int target) {
	int i = 0;

	array = realloc(array, (length + 1) * sizeof(int));
	array[length] = target;
	
	while (array[i] != target) {
		i++;
	}
	
	if (i < length) {
		return i;
	}
	
	return -1;
}

int linear_search_sorted(int *array, int length, int target) {
	int i = 0;

	array = realloc(array, (length + 1) * sizeof(int));
	array[length] = target + 1;
	
	while (array[i] < target) {
		i++;
	}
	
	if (array[i] == target) {
		return i;
	}
	
	return -1;
}

int binary_search(int *array, int length, int target) {
	int head = 0;
	int tail = length - 1;
	
	while (head <= tail) {
		int middle = (head + tail) / 2;
		
		if (array[middle] == target) {
			return middle;
		}
		
		if (array[middle] > target) {
			tail = middle - 1;
		} else {
			head = middle + 1;
		}
	}
	
	return -1;
}

int interpolation_search(int *array, int length, int target) {
	// int head = 0;
	// int tail = length - 1;

	// while (head <= tail && target >= array[head] && target <= array[tail]) {
	// 	int middle;

	// 	if (array[head] == array[tail]) {
	// 		middle = head;
	// 	} else {
	// 		middle = 
	// 	}
	// }

	return -1;
}

int approximate_search(int *array, int length, int target) {
	return -1;
}

