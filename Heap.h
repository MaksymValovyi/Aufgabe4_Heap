#include <iostream>
#include <algorithm>

using namespace std;

class Heap {
private:
    int* heapArray;
    int maxSize;
    int currentSize;

public:
    Heap(int size) {
        maxSize = size;
        currentSize = 0;
        heapArray = new int[maxSize];
    }

    ~Heap() {
        delete[] heapArray;
    }

    int getSize() const {
        return currentSize;
    }

    void push(int value) {
        if (currentSize == maxSize) {
            std::cout << "Heap is full. Cannot push more elements." << std::endl;
            return;
        }

        heapArray[currentSize] = value;
        int currentIndex = currentSize;
        int parentIndex = (currentIndex - 1) / 2;

        while (currentIndex > 0 && heapArray[currentIndex] > heapArray[parentIndex]) {
            std::swap(heapArray[currentIndex], heapArray[parentIndex]);
            currentIndex = parentIndex;
            parentIndex = (currentIndex - 1) / 2;
        }

        currentSize++;
    }

    int pop() {
        if (currentSize == 0) {
            std::cout << "Heap is empty. Cannot pop element." << std::endl;
            return -1;
        }

        int root = heapArray[0];
        heapArray[0] = heapArray[currentSize - 1];
        currentSize--;

        int currentIndex = 0;
        int leftChildIndex = 2 * currentIndex + 1;
        int rightChildIndex = 2 * currentIndex + 2;

        while (leftChildIndex < currentSize) {
            int maxIndex = leftChildIndex;

            if (rightChildIndex < currentSize && heapArray[rightChildIndex] > heapArray[leftChildIndex]) {
                maxIndex = rightChildIndex;
            }

            if (heapArray[currentIndex] < heapArray[maxIndex]) {
                std::swap(heapArray[currentIndex], heapArray[maxIndex]);
                currentIndex = maxIndex;
                leftChildIndex = 2 * currentIndex + 1;
                rightChildIndex = 2 * currentIndex + 2;
            } else {
                break;
            }
        }

        return root;
    }
    
    void printHeap() const {
        int level = 0;
        int levelSize = 1;
        int printed = 0;
        for (int i = 0; i < currentSize; ++i) {
            if(printed == 0){
                cout << "Level " << level << ": ";
            }
            cout << heapArray[i] << " ";
            printed++;
            if(printed == levelSize){
                cout << endl;
                level++;
                levelSize *= 2;
                printed = 0;
            }
        }
        if(printed != 0){
            cout << endl;
        }
    }

    void heapifyDown(int index) {
        while (index < maxSize) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild < currentSize && heapArray[leftChild] > heapArray[largest]) {
                largest = leftChild;
            }

            if (rightChild < currentSize && heapArray[rightChild] > heapArray[largest]) {
                largest = rightChild;
            }

            if (largest != index) {
                swap(heapArray[index], heapArray[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

    void buildHeap(int *values, int n) {
        delete[] heapArray;
        maxSize = n * 2;
        currentSize = n;
        heapArray = new int[maxSize];
        for (int i = 0; i < n; ++i) {
            heapArray[i] = values[i];
        }
        for (int i = currentSize / 2 - 1; i >= 0; --i) {
            heapifyDown(i);
        }
    }

};