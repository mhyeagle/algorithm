#include "sort.h"

void Swap(int* arr_point, int position1, int position2) {
	int temp = *(arr_point+position1);
	*(arr_point+position1) = *(arr_point+position2);
	*(arr_point+position2) = temp;
}

int Partition(int* arr_point, int low_subscript, int high_subscript) {
	if (high_subscript <= low_subscript) {
		return 0;
	}

	int low = low_subscript;
	int high = high_subscript;
	int pivot = low;
	++low;
	if (low == high) {
		if (*(arr_point+low) < *(arr_point+pivot)) {
			Swap(arr_point, low, pivot);
			pivot = low;
		}
	}
	while(low < high) {
		while(*(arr_point+low) < *(arr_point+pivot)) {
			if (low < high) {
				++low;
			} else {
				break;
			}
		}
		if (low == high) {
			if (*(arr_point+low) < *(arr_point+pivot)) {
				Swap(arr_point, low, pivot);
				pivot = low;
			} else {
				Swap(arr_point, low-1, pivot);
				pivot = low-1;
			}
			break;
		}

		while(*(arr_point+pivot) <= *(arr_point+high)) {
			if (low < high) {
				--high;
			} else {
				break;
			}
		}
		if (low == high) {
			Swap(arr_point, low-1, pivot);
			pivot = low-1;
			break;
		}
		
		Swap(arr_point, low, high);
	}

	if (low_subscript < pivot-1) {
		Partition(arr_point, low_subscript, pivot-1);
	}
	if (high_subscript > pivot+1) {
		Partition(arr_point, pivot+1, high_subscript);
	}
}

int QuickSort(int* arr_point, int arr_size) {
	Partition(arr_point, 0, arr_size-1);

	return 0;
}

int QuickSortTest() {
	srand(time(NULL));
	
	int array[10];
	for(int i = 0; i < 10; ++i) {
		array[i] = rand()%100;
	}
	

	//int array[10] = {2,47,53,27,59,20,59,36,84,59};

	OutputArray(array, 10, "quick sort original");
	QuickSort(array, 10);
	OutputArray(array, 10, "quick sort sorted");

	return 0;
}
