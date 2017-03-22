#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;






int main() {
    int arr[10000];
    int seed = time();
    srand(seed);

    for(int i = 0; i < 10000; ++i) {
        arr[i] = rand() % 100000;
    }

    int max_k[20];
    for(int i = 0; i < 20; ++i) {
        max_k[i] = 0;
    }

    

    return 0;
}
