#include "sort.h"

//selection sort
int SelectionSort(int* arr_point, int arr_size) {
	for(int i = 0; i < arr_size; ++i) {
		int* small_point = arr_point + i;
		for(int j = i+1; j < arr_size; ++j) {
			if (*(arr_point+j) < *small_point) {
				small_point = arr_point + j;
			}
		}
		int temp = *(arr_point + i);
		*(arr_point + i) = *small_point;
		*small_point = temp;
	}

	return 0;
}

//selection sort test
int SelectionSortTest() {
	srand(time(NULL));
	int array[10];
	for(int i = 0; i < 10; ++i) {
		array[i] = rand() % 100;
	}

	OutputArray(array, 10, "selection sort original");

	SelectionSort(array, 10);

	OutputArray(array, 10, "selection sort sorted");

	return 0;
}

