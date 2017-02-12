#include "sort.h"

int HeapAdjust(int* arr_point, int heap_size, int subscript) {
	int temp = 0;
	while(subscript <= (heap_size-1)/2) {
		int smallest_subscript = subscript;
		if (2*subscript+1 <= heap_size - 1) {
			if (*(arr_point + smallest_subscript) > *(arr_point + 2*subscript + 1)) {
				smallest_subscript = 2*subscript + 1;
			}
		}
		if (2*subscript + 2 <= heap_size - 1) {
			if (*(arr_point + smallest_subscript) > *(arr_point + 2*subscript + 2)) {
				smallest_subscript = 2*subscript + 2;
			}
		}
		if (smallest_subscript != subscript) {
			temp = *(arr_point + subscript);
			*(arr_point + subscript) = *(arr_point + smallest_subscript);
			*(arr_point + smallest_subscript) = temp;
			
			subscript = smallest_subscript;
		} else {
			break;
		}
	}

	return 0;
}

int HeapBuild(int* arr_point, int heap_size) {
	for(int i = (heap_size - (heap_size+1)/2); i >= 0; --i) {
		HeapAdjust(arr_point, heap_size, i);
	}

	return 0;
}

int HeapSort(int* arr_point, int arr_size) {
	int ret = 0;
	int array[arr_size];
	for(int i = 0; i < arr_size; ++i) {
		array[i] = 0;
	}

	ret = HeapBuild(arr_point, arr_size);
	if (ret) {
		cout << "build heap failed." << endl;
		return -1;
	}

	int heap_size = arr_size;
	for(int i = 0; i < arr_size; ++i) {
		array[i] = *(arr_point);
		--heap_size;
		*arr_point = *(arr_point + heap_size - 1);
		ret = HeapAdjust(arr_point, heap_size, 0);
		if (ret) {
			cout << "HeapAdjust failed." << endl;
			return -1;
		}
	}

	for(int j = 0; j < arr_size; ++j) {
		*(arr_point + j) = array[j];
	}

	return 0;
}

int HeapSortTest() {
	int array[10];
	srand(time(NULL));
	for(int i = 0; i < 10; ++i) {
		array[i] = rand() % 100;
	}

	OutputArray(array, 10, "heap sort original");

	HeapSort(array, 10);

	OutputArray(array, 10, "heap sort original");

	return 0;
}
