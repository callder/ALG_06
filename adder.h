#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

template <typename T>
class MaxHeap {
private:
    T* heap;
    int capacity;
    int last;

    int getParent(int i) { return (i - 1) / 2; }
    int getLeftChild(int i) { return 2 * i + 1; }
    int getRightChild(int i) { return 2 * i + 2; }

    void heapUp(int i) {
        if (i > 0 && heap[i] > heap[getParent(i)]) {
            swap(heap[i], heap[getParent(i)]);
            i = getParent(i);
            heapUp(i);
        }
    }

    void heapDown(int i) {
        if (heap[i] < heap[getLeftChild(i)] || heap[i] < heap[getRightChild(i)]) {
            if (heap[getRightChild(i)] < heap[getLeftChild(i)]) {
                swap(heap[i], heap[getLeftChild(i)]);
                i = getLeftChild(i);
                heapDown(i);
            } else {
                swap(heap[i], heap[getRightChild(i)]);
                i = getRightChild(i);
                heapDown(i);
            }
        }
    }

public:
    MaxHeap(int capacity) {
        heap = new T[capacity];
        this->capacity = capacity;
        last = 0;
    }

    ~MaxHeap() { delete[] heap; }

    void add(T element) {
        if (last == capacity) {
            cout << "Heap is full" << endl;
            return;
        }
        heap[last] = element;
        heapUp(last);
        last++;
    }

    T del() {
        if (last == 0) {
            cout << "Heap is empty" << endl;
            return T();
        }
        T root = heap[0];
        heap[0] = heap[last - 1];
        last--;
        heapDown(0);
        return root;
    }

    void show() {
        for (int i = 0; i < last; ++i) {
            cout << heap[i] << "\t";
        }
        cout << endl;
    }

    void clear() {
        delete[] heap;
        heap = nullptr;
        heap = new int[capacity];
        last = 0;
    }

    void info(){
        cout<<"Capacity: " << capacity << endl;
        cout<<"Amount: " << last << endl;
    }
};