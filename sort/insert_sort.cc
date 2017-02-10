#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;

//simple insert sort
int InsertSort(int* arr_point1, int* arr_point2, int arr_size) {
    int arr_temp[arr_size];
    for(int i = 0; i < arr_size; ++i) {
        if (i == 0) {
            arr_temp[i] = *(arr_point1+i);
        } else {
            for(int j = i-1; j >= 0; --j) {
                if (arr_temp[j] > *(arr_point1+i)) {
                    arr_temp[j+1] = arr_temp[j];
                    if (j == 0) {
                        arr_temp[j] = *(arr_point1+i);
                    }
                } else {
                    arr_temp[j+1] = *(arr_point1+i);
                    break;
                }
            }
        }
    }

    for(int i = 0; i < arr_size; ++i) {
        *(arr_point2+i) = arr_temp[i];
    }

    return 0;
}

//output array
void OutputArray(int* arr_point, int arr_size) {
    cout << "*********************" << endl;
    for(int i = 0; i < arr_size; ++i) {
        cout << *(arr_point+i) << "\t";
    }
    cout << endl;
}

//test
int main() {
    srand(time(NULL));

    int array_original[15];
    int array_sorted[15];

    for(int i = 0; i < 15; ++i) {
        array_original[i] = rand() % 100;
    }

    OutputArray(array_original, 15);

    InsertSort(array_original, array_sorted, 15);

    OutputArray(array_sorted, 15);

    return 0;
}


