#include "kWayMergeAlgorithm.h"

void kWayMergeAlgorithm::kWayMergeAlgo(int k, int n, long int* arr)
{
	int sizeSubArrCeil = ceil((double(n)) /(double) k);
	int sizeSubArrFloor = n / k;

	if (n < k || k==1)
	{
		return quickSort(arr, 0 , n-1 );
	}
	else
	{
		for (int i = 0; i < k; i++)
		{
			if (i < (n % k))
			{
				int subStart = (i * (ceil(((double)n) / ((double)k))));
				kWayMergeAlgo(k, sizeSubArrCeil, arr + subStart);
			}
			else
			{
				int subStart = (ceil(((double)n) / ((double)k))) * (n % k) +((i - (n % k)) * (n / k));
				kWayMergeAlgo(k, sizeSubArrFloor, arr + subStart);
			}
		}

		int* ArrayOfIndexes = new int[k]();
		MinHeap* heap = new MinHeap(k);
		int i = 0;
		int* resultArray = new int[n]();
		HeapD minItem;

		for (int i = 0; i < k; i++) {
			int subArrayCurrIndex = currIndexFromSubArray(n, k, ArrayOfIndexes, i);
			heap->insert(arr[subArrayCurrIndex], i);
		}

		while (i < n) {
			minItem = heap->deleteMin();
			resultArray[i] = minItem.val;
			ArrayOfIndexes[minItem.indexSubArr] = ArrayOfIndexes[minItem.indexSubArr] + 1;

			if (!isLastInSubArray(n, k, ArrayOfIndexes, minItem.indexSubArr)) {
				int subArrayCurrIndex = currIndexFromSubArray(n, k, ArrayOfIndexes, minItem.indexSubArr);
				int nextToInsert = arr[subArrayCurrIndex];
				heap->insert(nextToInsert, minItem.indexSubArr);
			}
				i++;
		}
			
		for (int i = 0; i < n; i++) {
			arr[i] = resultArray[i];
		}
		delete[] resultArray;
		delete[] ArrayOfIndexes;
	}
}

bool kWayMergeAlgorithm :: isLastInSubArray(int n,int  k, int * subArrayIndexes,int  i) {
	return subArrayIndexes[i] >= subarraySize(n, k, i);
}

int kWayMergeAlgorithm :: subarraySize(int n, int k, int subArrayIndex) {
	if (subArrayIndex < (n % k)) {
		return  (ceil(((double)n) / ((double)k)));
	}
	return floor(n / k);
}

int  kWayMergeAlgorithm :: currIndexFromSubArray(int n, int k, int * idxs, int i) {
	if (i < (n % k)) {
		return i * (ceil(((double)n) / ((double)k))) + idxs[i];
	}
	return (ceil(((double)n) / ((double)k))) * (n % k) + (i - (n % k)) *floor(n / k) + idxs[i];
}


void kWayMergeAlgorithm::quickSort(long int* arr, int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = partition(arr, low, high);

		quickSort(arr, low, pivot - 1); 
		quickSort(arr, pivot + 1, high); 
	}
}

int kWayMergeAlgorithm:: partition(long int* arr, int left, int right)
{
	int pivot = left;

	while (left < right)
	{

		if (arr[left] > arr[right])
		{
			mySwap(arr[left], arr[right]);
			if (pivot == left)
			{
				left++;
				pivot = right;
			}
			else
			{
				right--;
				pivot = left;
			}
		}
		else
		{
			if (pivot == left)
				right--;

			else
				left++;
		}
	}
	return pivot;
}

void kWayMergeAlgorithm::mySwap(long int& a, long int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

