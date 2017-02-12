#include "sort.h"

//insert sort 
int InsertSortShell(int* arr_point, int first, int end, int pace_length) {
	int* element_insert_p = NULL;
	int element_insert = 0;
	for(int i = first; i <= end; i += pace_length) {
		element_insert_p = arr_point + i;
		element_insert = *element_insert_p;
		if (i == first) {
			continue;
		} else {
			for(int j = (i-first)/pace_length; j > 0; --j) {
				int* element_exchange_p = arr_point + first + (j-1)*pace_length;
				if (*element_exchange_p > element_insert) {
					*(element_exchange_p + pace_length) = *element_exchange_p;
					if (j == 1) {
						*element_exchange_p = element_insert;
					}
				} else {
					*(element_exchange_p + pace_length) = element_insert;
					break;
				}
			}
		}
	}

	return 0;
}

//shell sort
int ShellSort(int* arr_point, int arr_size) {
	for(int i = arr_size/2; i > 0; --i) {
		for(int j = 0; j < i; ++j) {
			InsertSortShell(arr_point, j, arr_size-1, i);
		}
	}

	return 0;
}

//insert sort in shell sort
int InsertSortShellTest() {
	int array[10];
	srand(time(NULL));
	for(int i = 0; i < 10; ++i) {
		array[i] = rand()%100;
	}

	OutputArray(array, 10, "InsertSortShellTest original");

	//InsertSortShell(array, 0, 9, 1);
	InsertSortShell(array, 1, 9, 2);
	
	OutputArray(array, 10, "InsertSortShellTest sorted");
}

//shell sort test
int ShellSortTest() {
	int array[10];
	srand(time(NULL));
	for(int i = 0; i < 10; ++i) {
		array[i] = rand()%100;
	}

	OutputArray(array, 10, "shell sort original");
	ShellSort(array, 10);
	OutputArray(array, 10, "shell sort sorted");

	return 0;
}

