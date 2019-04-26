#include <iostream>
#include <cmath>
#include <queue>
#define MAX_HEAP_SIZE 100

using namespace std;

template <class T>
class Heap{
private:
    T* arr = new T[MAX_HEAP_SIZE];
    int length;
    bool isMaxHeap;

public:
    Heap(){
        for(int i = 0; i<MAX_HEAP_SIZE; i++){
            arr[i] = 0;
        }
        isMaxHeap = true;
        length = 0;
    }

    Heap(T* data, int num, bool isMax){
        for(int i = 0; i<num; i++){
            arr[i] = data[i];
        }
        isMaxHeap = isMax;
        length = num;
        MakeHeap();
    }

    void MakeHeap(){
        for(int i = length/2; i>=0; i++){
            PercolateDown(i);
        }
    }

    virtual void C(){}

    bool Push(T value){
        if(length == MAX_HEAP_SIZE){
            return false;
        }
        
        arr[length++] = value;
        PercolateUp(length-1);
    }

    T Pop(){
        if(length == 0){
            return arr[0];
        }
        T res = arr[0];
        arr[0] = arr[--length];
        PercolateDown(0);

        return res;
    }

    T Top(){
        return arr[0];
    }

    int Size(){
        return length;
    }

private:
    void PercolateDown(int idx){
        int tmp = arr[idx];
        int leftChild = 2*idx + 1, rightChild = 2*idx + 2;
        int largerChild = ((leftChild < length) && (rightChild < length) && (arr[rightChild] > arr[leftChild]))? rightChild : leftChild;

        for(; largerChild < length && arr[largerChild] > tmp;){
            arr[idx] = arr[largerChild];
            // compute next iteration
            idx = largerChild;
            leftChild = 2*idx + 1;
            rightChild = 2*idx + 2;
            largerChild = ((leftChild < length) && (rightChild < length) && (arr[rightChild] > arr[leftChild]))? rightChild : leftChild;
        }
        arr[idx] = tmp;
        
    }

    void PercolateUp(int idx){
        int tmp = arr[idx];
        int parent = (idx - 1) / 2;
        for(; parent >= 0 && arr[parent] < tmp;){
            arr[idx] = arr[parent];
            // compute next iteration
            idx = parent;
            parent = floor((idx - 1.0) / 2.0);
        }
        arr[idx] = tmp;

    }


};

int main()
{
    Heap<int> heap;
    for(int i = 0; i<100; i++){
        heap.Push(i);
    }
    for(int i = 0; i<100; i++){
        cout << heap.Pop() << endl;
    }
}