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
        arr[i] = rand()%10000;
        cout << arr[i] << endl;
    }

    MinHeap<int> heap;
    heap.reserve(5);
    for(int i = 0; i < 1000; ++i) {
        heap.push(arr[i]);
    }

    cout << "********" << endl;
    heap.output();

    return 0;
}
