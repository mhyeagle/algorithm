#include "sort.h"

int BubbleSort(int* arr_point, int arr_size) {
	for(int i = arr_size-1; i > 0; --i) {
		int end = arr_size-1;
		for(int j = 0; j < i; ++j) {
			if(*(arr_point+end) < *(arr_point+end-1)) {
				int temp = *(arr_point+end);
				*(arr_point+end) = *(arr_point+end-1);
				*(arr_point+end-1) = temp;
			}
			--end;
		}
	}

	return 0;
}

int BubbleSortTest() {
	int array[10];
	srand(time(NULL));
	for(int i = 0; i < 10; ++i) {
		array[i] = rand() % 100;
	}

	OutputArray(array, 10, "bubble sort original");

	BubbleSort(array, 10);

	OutputArray(array, 10, "bubble sort sorted");

	return 0;
}
