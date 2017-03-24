#ifndef MIN_HEAP_H

#include <iostream>
#include <vector>
#include <memory>

template<class T>
class MinHeap {
public:
    MinHeap() {
        heap__ = std::make_shared<std::vector<T> >();
    }
    ~MinHeap() {}

    int reserve(unsigned long size);
    int push(T& element);
    int pop_min(T& element);
    void output();
private:
    int heap_adjust_down(unsigned long size);
    int heap_adjust_up(unsigned long size);
    void swap(unsigned long sub1, unsigned long sub2);

private:
    std::shared_ptr<std::vector<T> > heap__;
    unsigned long size__;
};

template<class T>
void MinHeap<T>::swap(unsigned long sub1, unsigned long sub2) {
    T temp = (*heap__)[sub1];
    (*heap__)[sub1] = (*heap__)[sub2];
    (*heap__)[sub2] = temp;
}

template<class T>
void MinHeap<T>::output() {
    for(int i = 0; i < size__; ++i) {
        std::cout << (*heap__)[i] << std::endl;
    }
}

template<class T>
int MinHeap<T>::reserve(unsigned long size) {
    if (size > 0)
        heap__->reserve(size);
    size__ = size;

    return 0;
}

template<class T>
int MinHeap<T>::heap_adjust_down(unsigned long subscript) {
    if (subscript < 0 || subscript >= size__) {
        std::cout << "heap_adjust_down input error, value: " << subscript << " subscript__: " << size__ << std::endl;
        return -1;
    }

    for(unsigned long i = 0; i <= subscript; ) {
        if (2*i+1 > subscript) {
            return 0;
        }
        if (2*i+2 > subscript && 2*i+1 == subscript) {
            if ((*heap__)[i] > (*heap__)[2*i+1]) {
                swap(i, 2*i+1);
            }
            return 0;
        }
        if (2*i+2 <= subscript && 2*i+1 < subscript) {
            unsigned long sub;
            if ((*heap__)[2*i+1] < (*heap__)[2*i+2]) {
                sub = 2*i+1;
            } else {
                sub = 2*i+2;
            }
			if ((*heap__)[i] > (*heap__)[sub]) {
            	swap(i, sub);
            	i = sub;
			} else {
				return 0;
			}
        }
    }
}

template<class T>
int MinHeap<T>::heap_adjust_up(unsigned long size) {
    if (size < 0 || size > size__) {
        return -1;
    }

    unsigned long father = (size-1)/2;
    unsigned long i = size;
    while( i > 0 && father >= 0 ) {
        if ((*heap__)[i] < (*heap__)[father]) {
            swap(father, i);
            i = father;
            father = (i-1)/2;
        } else {
            return 0;
        }
    }

	return 0;
}

template<class T>
int MinHeap<T>::push(T& element) {
    int ret = 0;
    if (heap__->size() < size__) {
        heap__->push_back(element);
        ret = heap_adjust_up(heap__->size()-1);
        if (ret) {
            std::cout << "heap_adjust_up failed." << std::endl;
            return -1;
        }
    } else if (heap__->size() == size__) {
        if (element > (*heap__)[0]) {
            (*heap__)[0] = element;
            ret = heap_adjust_down(size__-1);
            if (ret) {
                std::cout << "heap_adjust_down failed." << std::endl;
                return -1;
            }
        }
    } else {
        std::cout << "heap size > size__" << std::endl;
    }

    return ret;
}

template<class T>
int MinHeap<T>::pop_min(T& element) {
    element = (*heap__)[0];
}

#endif //MIN_HEAP_H
