#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAIN_ARRAY_LENGTH 30

typedef struct {
	int found_index;
	int comparisons;
	double execution_time;
} SearchAnalytics;

double calculateExecutionTimeInMilliseconds(clock_t start, clock_t end);
SearchAnalytics linear_search(int *array, int length, int target);
SearchAnalytics linear_search_with_sentinel(int *array, int length, int target);
SearchAnalytics linear_search_sorted(int *array, int length, int target);
SearchAnalytics binary_search(int *array, int length, int target);
SearchAnalytics interpolation_search(int *array, int length, int target);
SearchAnalytics approximate_search(int *array, int length, int target);

int main() {
	// Vetor ordenado
	int search_array[MAIN_ARRAY_LENGTH] = {
		2,  5,  8, 11, 14,
	   17, 20, 23, 26, 29,
	   32, 35, 38, 41, 44,
	   47, 50, 53, 56, 59,
	   62, 65, 68, 71, 74,
	   77, 80, 83, 86, 89
   	};
   	
   	// Vetor nao ordenado
   	/*
	int search_array[MAIN_ARRAY_LENGTH] = {
	    29,  2, 62, 17, 83,
	    41, 14, 38, 59, 23,
	     5, 89, 32, 50, 77,
	    26, 44,  8, 80, 56,
	    65, 35, 71, 20, 47,
	    74, 68, 11, 86, 53
	};
	*/

	int *array = malloc(MAIN_ARRAY_LENGTH * sizeof(int));
	int target;
	int i;
	clock_t executionTimeStart;
	clock_t executionTimeEnd;
	
	SearchAnalytics linear_search_analytics;
	SearchAnalytics linear_search_with_sentinel_analytics;
	SearchAnalytics linear_search_sorted_analytics;
	SearchAnalytics binary_search_analytics;
	SearchAnalytics interpolation_search_analytics;
	SearchAnalytics approximate_search_analytics;

	for (i = 0; i < MAIN_ARRAY_LENGTH; i++) {
		array[i] = search_array[i];
	}

	printf("Informe um numero para procurar no vetor: ");
	scanf("%d", &target);
	
	// Busca Linear
	executionTimeStart = clock();
	
	linear_search_analytics = linear_search(array, MAIN_ARRAY_LENGTH, target);
	
	executionTimeEnd = clock();
	
	linear_search_analytics.execution_time = calculateExecutionTimeInMilliseconds(executionTimeStart, executionTimeEnd);
	
	// Busca Linear com Sentinela
	executionTimeStart = clock();
	
	linear_search_with_sentinel_analytics = linear_search_with_sentinel(array, MAIN_ARRAY_LENGTH, target);
	
	executionTimeEnd = clock();
	
	linear_search_with_sentinel_analytics.execution_time = calculateExecutionTimeInMilliseconds(executionTimeStart, executionTimeEnd);
	
	// Busca Linear Ordenada
	executionTimeStart = clock();
	
	linear_search_sorted_analytics = linear_search_sorted(array, MAIN_ARRAY_LENGTH, target);
	
	executionTimeEnd = clock();
	
	linear_search_sorted_analytics.execution_time = calculateExecutionTimeInMilliseconds(executionTimeStart, executionTimeEnd);
	
	// Busca Binaria
	executionTimeStart = clock();
	
	binary_search_analytics = binary_search(array, MAIN_ARRAY_LENGTH, target);
	
	executionTimeEnd = clock();
	
	binary_search_analytics.execution_time = calculateExecutionTimeInMilliseconds(executionTimeStart, executionTimeEnd);
	
	// Busca por Interpolacao
	executionTimeStart = clock();
	
	interpolation_search_analytics = interpolation_search(array, MAIN_ARRAY_LENGTH, target);
	
	executionTimeEnd = clock();
	
	interpolation_search_analytics.execution_time = calculateExecutionTimeInMilliseconds(executionTimeStart, executionTimeEnd);
	
	// Busca por Aproximação
	executionTimeStart = clock();
	
	approximate_search_analytics = approximate_search(array, MAIN_ARRAY_LENGTH, target);
	
	executionTimeEnd = clock();
	
	approximate_search_analytics.execution_time = calculateExecutionTimeInMilliseconds(executionTimeStart, executionTimeEnd);

	// Resultados
	printf("\n# ==========================================\n");
	printf("# Resumo Comparativo dos Algortimos de Busca\n");
	printf("# ==========================================\n");
	
	// Busca Linear
	printf("\nAlgoritmo: Busca Linear\n");
	if (linear_search_analytics.found_index == -1) {
	    printf("Indice encontrado: [Nao encontrado]\n");
	} else {
	    printf("Indice encontrado: %d\n", linear_search_analytics.found_index);
	}
	printf("Comparacoes: %d\n", linear_search_analytics.comparisons);
	printf("Tempo de execucao (ms): %.6f\n", linear_search_analytics.execution_time);
	
	// Busca Linear com Sentinela
	printf("\nAlgoritmo: Busca Linear com Sentinela\n");
	if (linear_search_with_sentinel_analytics.found_index == -1) {
	    printf("Indice encontrado: [Nao encontrado]\n");
	} else {
	    printf("Indice encontrado: %d\n", linear_search_with_sentinel_analytics.found_index);
	}
	printf("Comparacoes: %d\n", linear_search_with_sentinel_analytics.comparisons);
	printf("Tempo de execucao (ms): %.6f\n", linear_search_with_sentinel_analytics.execution_time);
	
	// Busca Linear Ordenada
	printf("\nAlgoritmo: Busca Linear Ordenada\n");
	if (linear_search_sorted_analytics.found_index == -1) {
	    printf("Indice encontrado: [Nao encontrado]\n");
	} else {
	    printf("Indice encontrado: %d\n", linear_search_sorted_analytics.found_index);
	}
	printf("Comparacoes: %d\n", linear_search_sorted_analytics.comparisons);
	printf("Tempo de execucao (ms): %.6f\n", linear_search_sorted_analytics.execution_time);
	
	// Busca Binaria
	printf("\nAlgoritmo: Busca Binaria\n");
	if (binary_search_analytics.found_index == -1) {
	    printf("Indice encontrado: [Nao encontrado]\n");
	} else {
	    printf("Indice encontrado: %d\n", binary_search_analytics.found_index);
	}
	printf("Comparacoes: %d\n", binary_search_analytics.comparisons);
	printf("Tempo de execucao (ms): %.6f\n", binary_search_analytics.execution_time);
	
	//  Busca por Interpolacao
	printf("\nAlgoritmo: Busca por Interpolacao\n");
	if (interpolation_search_analytics.found_index == -1) {
	    printf("Indice encontrado: [Nao encontrado]\n");
	} else {
	    printf("Indice encontrado: %d\n", interpolation_search_analytics.found_index);
	}
	printf("Comparacoes: %d\n", interpolation_search_analytics.comparisons);
	printf("Tempo de execucao (ms): %.6f\n", interpolation_search_analytics.execution_time);
	
	// Busca por Aproximacao
	printf("\nAlgoritmo: Busca por Aproximacao\n");
	if (approximate_search_analytics.found_index == -1) {
	    printf("Indice encontrado: [Nao encontrado]\n");
	} else {
	    if (array[approximate_search_analytics.found_index] != target) {
	    	printf("Indice encontrado: [Nao encontrado]\n");
	        printf("Valor aproximado: %d\n", array[approximate_search_analytics.found_index]);
	    } else {
	    	printf("Indice encontrado: %d\n", approximate_search_analytics.found_index);
		}
	}
	printf("Comparacoes: %d\n", approximate_search_analytics.comparisons);
	printf("Tempo de execucao (ms): %.6f\n", approximate_search_analytics.execution_time);
	
	return 0;
}

double calculateExecutionTimeInMilliseconds(clock_t start, clock_t end) {
	return (end - start) * 1000.0 / CLOCKS_PER_SEC;
}

SearchAnalytics linear_search(int *array, int length, int target) {
	SearchAnalytics analytics;
	int i;
	
	analytics.found_index = -1;
	analytics.comparisons = 1; // comparacao inicial para verificar se o vetor esta vazio
	
	if (length == 0) {
		return analytics;
	}
	
	// busca posicao por posicao ate achar o valor-alvo
	for (i = 0; i < length; i++) {
		analytics.comparisons += 2; // comparacao do loop + comparacao com o valor-alvo
		
		if (array[i] == target) {
			analytics.found_index = i;
			return analytics;
		}
	}
	
	analytics.comparisons++; // comparacao de termino do loop
	
	return analytics;
}

SearchAnalytics linear_search_with_sentinel(int *array, int length, int target) {
	SearchAnalytics analytics;
	int i = 0;
	
	analytics.found_index = -1;
	analytics.comparisons = 1; // comparacao inicial para verificar se o vetor esta vazio
	
	if (length == 0) {
		return analytics;
	}
	
	// aloca um novo vetor com mais uma posicao para guardar o sentinela e copia o conteudo do vetor original para ele
	int *copy = malloc((length + 1) * sizeof(int));
    memcpy(copy, array, length * sizeof(int));
    copy[length] = target;
	
	// fica verificando ate achar o valor-alvo da ultima posicao do vetor (sentinela), se achar antes e porque consta no vetor
	while (copy[i] != target) {
		analytics.comparisons++; // comparacao de condicao do loop while
		i++;
	}
	
	analytics.comparisons += 2; // comparacao de termino do loop while + comparacao se o valor-alvo foi encontrado
	
	// consta no vetor de o indice encontrado for maior que o indice do sentinela
	if (i < length) {
		analytics.found_index = i;
		return analytics;
	}
	
	free(copy);
	return analytics;
}

SearchAnalytics linear_search_sorted(int *array, int length, int target) {
	SearchAnalytics analytics;
	int i = 0;
	
	analytics.found_index = -1;
	analytics.comparisons = 1; // comparacao inicial para verificar se o vetor esta vazio
	
	if (length == 0) {
		return analytics;
	}
	
	// aloca um novo vetor com mais uma posicao para guardar um valor maior que o valor-alvo e copia o conteudo do vetor original para ele
	int *copy = malloc((length + 1) * sizeof(int));
    memcpy(copy, array, length * sizeof(int));
    copy[length] = target + 1;
	
	// fica verificando ate achar um valor que seja maior que o valor-alvo, sendo que na ultima posicao sempre tera um valor maior que o valor-alvo
	while (copy[i] < target) {
		analytics.comparisons++; // comparacao de condicao do loop while
		i++;
	}
	
	analytics.comparisons += 2; // comparacao de termino do loop while + comparacao se o valor-alvo foi encontrado
	
	// se o indice encontrado corresponder ao valor-alvo, achamos
	if (copy[i] == target) {
		analytics.found_index = i;
		return analytics;
	}
	
	free(copy);
	return analytics;
}

SearchAnalytics binary_search(int *array, int length, int target) {
	SearchAnalytics analytics;
	int head = 0;
	int tail = length - 1;
	
	analytics.found_index = -1;
	analytics.comparisons = 1; // comparacao inicial para verificar se o vetor esta vazio
	
	if (length == 0) {
		return analytics;
	}
	
	// enquanto o inicio posicionado do vetor for menor ou igual ao final posicionado do vetor
	while (head <= tail) {
		analytics.comparisons++; // comparacao do loop while
		
		// calcula o indice da metade do vetor
		int middle = (head + tail) / 2;
		
		analytics.comparisons++; // comparacao para verificar se o valor do meio e o valor-alvo
		
		// se achou, perfeito
		if (array[middle] == target) {
			analytics.found_index = middle;
			return analytics;
		}
		
		analytics.comparisons++; // comparacao para verificar se o valor do meio e maior que o valor-alvo
		
		// se nao, verifica se tem que reposicionar o final ou o inicio do vetor, verificando se o valor do meio e maior ou menor que o valor-alvo
		if (array[middle] > target) {
			tail = middle - 1; // se o valor do meio for maior que o valor-alvo, reposiciona o final
		} else {
			head = middle + 1; // se o valor do meio for menor que o valor-alvo, reposiciona o inicio
		}
	}
	
	analytics.comparisons++; // comparacao de termino do loop while
	
	return analytics;
}

SearchAnalytics interpolation_search(int *array, int length, int target) {
	SearchAnalytics analytics;
	int head = 0;
	int tail = length - 1;
	
	analytics.found_index = -1;
	analytics.comparisons = 1; // comparacao inicial para verificar se o vetor esta vazio
	
	if (length == 0) {
		return analytics;
	}

	// como na busca binaria, mas ele verifica se o valor-alvo esta entre o inicio e o final posicionado do vetor (pois ele pode ter errado sem querer)
	while (head <= tail && target >= array[head] && target <= array[tail]) {
		analytics.comparisons += 3; // comparacoes do loop while (2 menor ou igual + 1 maior ou igual)
		
		int middle;

		analytics.comparisons++; // comparacao para evitar divisao por zero

		if (array[head] == array[tail]) {
			middle = head;
		} else {
			middle = ((target - array[head]) * (tail - head)) / (array[tail] - array[head]);
		}
		
		analytics.comparisons++; // comparacao para verificar se o valor do meio e o valor-alvo
		
		if (array[middle] == target) {
			analytics.found_index = middle;
			return analytics;
		}
		
		analytics.comparisons++; // comparacao para verificar se o valor do meio e maior que o valor-alvo
		
		if (array[middle] > target) {
			tail = middle - 1;
		} else {
			head = middle + 1;
		}
	}
	
	analytics.comparisons += 3; // comparacao de termino do loop while

	return analytics;
}

SearchAnalytics approximate_search(int *array, int length, int target) {
	SearchAnalytics analytics;
	int head = 0;
	int tail = length - 1;
	int best = 0;
	
	analytics.found_index = best;
	analytics.comparisons = 1; // comparacao inicial para verificar se o vetor esta vazio
	
	if (length == 0) {
		return analytics;
	}
	
	while (head <= tail) {
		analytics.comparisons++; // comparacao de termino do loop while
		
		int middle = (head + tail) / 2;
		
		analytics.comparisons++; // comparacao para verificar se o valor do meio e o valor-alvo
		
		if (array[middle] == target) {
			analytics.found_index = middle;
			return analytics;
		}
		
		analytics.comparisons++; // comparacao para verificar se a diferenca do valor do meio para o valor-alvo e menor que a diferenca do melhor valor para o valor-alvo
		
		if (abs(array[middle] - target) < abs(array[best] - target)) {
			best = middle;
		}
		
		analytics.comparisons++; // comparacao para verificar se o valor do meio e maior que o valor-alvo
		
		if (array[middle] > target) {
			tail = middle - 1;
		} else {
			head = middle + 1;
		}
	}
	
	analytics.comparisons++; // comparacao de termino do loop while
	
	analytics.found_index = best;
	return analytics;
}

