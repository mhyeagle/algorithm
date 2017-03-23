#include <iostream>
#include <string>
#include <cstdlib>

#include "min_heap.h"

using namespace std;

int main() {
    int arr[1000];
    int seed = time(NULL);
    srand(seed);

    for(int i = 0; i < 1000; ++i) {
        arr[i] = rand() % 100000;
        cout << arr[i] << endl;
    }

    int max_k[20];
    for(int i = 0; i < 20; ++i) {
        max_k[i] = 0;
    }

    MinHeap<int> heap;
    heap.reserve(20);
    for(int i = 0; i < 1000; ++i) {
        heap.push(arr[i]);
    }

    cout << "********" << endl;
    int min_num = 0;
	heap.pop_min(min_num);
    cout << min_num << endl;

    return 0;
}
