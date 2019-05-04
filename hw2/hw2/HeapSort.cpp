#include "stdafx.h"
#include "HeapSort.h"


CHeapSort::CHeapSort()
{
}


CHeapSort::~CHeapSort()
{
}

void CHeapSort::sort(std::vector<int>& vector)
{
	size_t heapSize = vector.size();

	// build the max heap
	buildMaxHeap(vector);

	// go through all node starting at last-1, since last node gets swapped with
	// the first index which is the maximum value in the heap; simply put, we 
	// take the top of the heap, put it at the end of the vector, we do this
	// in descending order always placing the new max before the previous max
	for (size_t nodeIndex = vector.size() - 1; nodeIndex > 0; nodeIndex-- ) {

		// swap max index with root node
		int tmp = vector[0];
		vector[0] = vector[nodeIndex];
		vector[nodeIndex] = tmp;

		// heapify at the top root node, but only heapify up to the nodes
		// less than what has already been sorted; that's why we reduce the
		// heapsize by one
		heapSize = heapSize - 1;
		maxHeapify(vector, 0, heapSize);
	}
}

std::string CHeapSort::identify() 
{ 
	return "Heap Sort"; 
}

void CHeapSort::maxHeapify(std::vector<int>& vector, size_t nodeIndex, size_t heapSize)
{
	size_t largestNode;
	size_t leftNode = left(nodeIndex);
	size_t rightNode = right(nodeIndex);

	// check if left node is larger then root node
	if ((leftNode < heapSize) && (vector[leftNode] > vector[nodeIndex])) {

		// largest is left node
		largestNode = leftNode;
	}
	else {
		// largest is (current) nodeIndex
		largestNode = nodeIndex;
	}

	if ((rightNode < heapSize) && (vector[rightNode] > vector[largestNode])) {
		
		// largest is right node
		largestNode = rightNode;
	}

	// check if root is not the largest, which means that left or right 
	// were the largest
	if (largestNode != nodeIndex) {
		int tmp = vector[nodeIndex];
		vector[nodeIndex] = vector[largestNode];
		vector[largestNode] = tmp;

		maxHeapify(vector, largestNode, heapSize);
	}
}

void CHeapSort::buildMaxHeap(std::vector<int>& vector)
{
	// start by maxHeapify'ing the entire vector
	size_t heapSize = vector.size();

	// vector[n/2...n] are nodes which are all leaves, so we start at vector[n/2 -1]
	// all the way to the first node; by doing this we bubble up max values to the
	// top of the heap
	for (int nodeIndex = vector.size() / 2 - 1; nodeIndex >= 0; nodeIndex--) {
		
		// call maxHeapify at each (every) root node of the subtree
		maxHeapify(vector, nodeIndex, heapSize);
	}

}

// get parent node
size_t CHeapSort::parent(size_t nodeIndex)
{
	return nodeIndex / 2;
}

// get left child node
size_t CHeapSort::left(size_t nodeIndex)
{
	return (2 * nodeIndex) + 1;
}

// get right child node
size_t CHeapSort::right(size_t nodeIndex)
{
	return (2 * nodeIndex) + 2;
}