#ifndef MINHEAP_H
#define MINHEAP_H
#include <stdexcept>
#include <iostream>
struct HeapD
{
	int indexSubArr;
	int val;
};

class MinHeap
{
	
private:
	HeapD* heap;
	int maxSize;
	int heapSize;
	int Left(int index);
	int Right(int index);
	int Parent(int index);

public :
	MinHeap(int k) 
	{
		maxSize = k;
		heap = new HeapD[maxSize];
		heapSize = 0;
	};
	MinHeap(int* arr, int n);
	~MinHeap() {};
	void insert(int val, int indexSubArr);
	HeapD deleteMin();
	HeapD min();
	HeapD* getHeap() { return heap; }
	void fixHeap(int index);
	void buildHeap(int* arr, int n);
	void mySwapH(int& a, int& b);
};
#endif // !MINHEAP_H
