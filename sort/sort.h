#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;

//insert sort
int InsertSort(int* arr_point1, int* arr_point2, int arr_size);
int InsertSortTest();

//shell sort
int InsertSortShellTest();
int ShellSort(int* arr_point, int arr_size);
int ShellSortTest();

//selection sort
int SelectionSort(int* arr_point, int arr_size);
int SelectionSortTest();

//heap sort
int HeapSort(int* arr_point, int arr_size);
int HeapSortTest();





//output array
void OutputArray(int* arr_point, int arr_size, string message);
#endif //SORT_H

