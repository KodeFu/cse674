/*

	File:
		HeapSort.h

	Purpose:
		Class definition for the HeapSort algorithm.

	Author:
		mpvats@syr.edu

*/
#pragma once
#include "SortInterface.h"

class CHeapSort :
	public ISortInterface
{
public:
	CHeapSort();
	~CHeapSort();
	void sort(std::vector<int>& vector);
	std::string identify();

private:
	void maxHeapify(std::vector<int>& vector, size_t nodeIndex, size_t heapSize);
	void buildMaxHeap(std::vector<int>& vector);
	size_t parent(size_t nodeIndex);
	size_t left(size_t nodeIndex);
	size_t right(size_t nodeIndex);
};

