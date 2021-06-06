#include "minHeap.h"

MinHeap::MinHeap(int* arr, int n)
{

}

int MinHeap::Parent(int index)
{
    return (index - 1) / 2;
}

int MinHeap::Left(int index)
{
    return (2 * index + 1);
}

int MinHeap::Right(int index)
{
    return (2 * index + 2);
}

void MinHeap::insert(int val, int indexSubArr)
{
    if (heapSize == maxSize)
    {
        return;
    }
    int i = heapSize;
    heapSize++;
	
    while ((i > 0) && (heap[Parent(i)].val > val))
    {
        heap[i].val = heap[Parent(i)].val;
        heap[i].indexSubArr = heap[Parent(i)].indexSubArr;
        i = Parent(i);
    }
    heap[i].val = val ;
    heap[i].indexSubArr = indexSubArr ;
}
HeapD MinHeap::deleteMin()
{
    if (heapSize < 1)
        throw std::invalid_argument("the heap is full");
    else{
        HeapD min = heap[0]; 
        heapSize--;
        heap[0] = heap[heapSize]; 
        fixHeap(0);
        return min;
    }
}

HeapD MinHeap::min()
{
    return heap[0];
}

void MinHeap::fixHeap(int index)
{
    int min;
    int left = Left(index);
    int right = Right(index);

    if ((left < heapSize) && (heap[left].val < heap[index].val))
        min = left;
    else
        min = index;
    if((right < heapSize) &&  (heap[right].val < heap[min].val))
        min = right;

    if (min != index)
    {
       mySwapH(heap[index].val, heap[min].val);
       mySwapH(heap[index].indexSubArr, heap[min].indexSubArr);
       fixHeap(min);
    }
}

void MinHeap::buildHeap(int* arr, int n)
{

    for (int i = (n / 2) - 1; i >= 0; i--)
        fixHeap(i);
}


void MinHeap::mySwapH(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}