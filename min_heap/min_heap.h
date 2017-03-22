#ifndef MIN_HEAP_H

#include <vector>
#include <memory>

template<class T>
class MinHeap {
public:
    MinHeap() {
        heap_size__ = make_shared<std::vector<T> >();
    }
    ~MinHeap() {}

    int reserve(unsigned long& size);
    int push(T& element);
    int pop_min(T& element);
private:
    int heap_adjust_down(unsigned long& size);
    int heap_adjust_up(unsigned long& size);

private:
    std::shared_ptr<std::vector<T> > heap_size__;
    unsigned long size__;
};

template<class T>
int MinHeap<T>::reserve(unsigned long& size) {
    int ret = 0;
    if (size > 0)
        ret = heap_size__->reserve(size);
    size__ = size;
    
    return ret;
}

template<class T>
int MinHeap<T>::heap_adjust_down(unsigned long& size) {

}

template<class T>
int MinHeap<T>::heap_adjust_up(unsigned long& size) {

}

template<class T>
int MinHeap<T>::push(T& element) {
    
}

template<class T>
int pop_min(T& element) {
    
}

#endif //MIN_HEAP_H
