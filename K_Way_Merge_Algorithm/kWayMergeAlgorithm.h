#ifndef KWAYMERGEALGORITHM_H
#define KWAYMERGEALGORITHM_H
#include "minHeap.h"
#include <iostream>
#include <math.h>

using namespace std;

class kWayMergeAlgorithm
{
public:
	kWayMergeAlgorithm() 
	{
		
	}
	~kWayMergeAlgorithm() {}
	void kWayMergeAlgo(int k, int n, long int * arr);
	 void quickSort(long int* arr, int low, int high);
	int partition(long int* arr, int left, int right);
	void static mySwap(long int& a,long int& b);


	int  currIndexFromSubArray(int n, int k, int* idxs, int i);
	bool isLastInSubArray(int n, int  k, int* subArrayIndexes, int  i);
	int subarraySize(int n, int k, int subArrayIndex);

private:
	int* _arr;
	int _size;
};

#endif // !KWAYMERGEALGORITHM_H


//void mergeKArrays(int k, MinHeap* heap);
	//void divideToKarrays(int left, int right, int k);
