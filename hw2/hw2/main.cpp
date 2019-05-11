// hw2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SortInterface.h"

#include "BubbleSort.h"
#include "BubbleSortWithFlag.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "RadixSort.h"
#include "CountingSort.h"
#include "SmoothSort.h"

#define MAX_RANGE 10000

void generateRandom(std::vector<int>& data)
{
	srand((unsigned int) time(NULL));
	for (int i = 0; i < MAX_RANGE; i++) {
		data.push_back(((rand() << 15) | rand()) % MAX_RANGE + 1);
	}
}

int main()
{
	CBubbleSort *bubbleSort = new CBubbleSort();
	CBubbleSortWithFlag *bubbleSortWithFlag = new CBubbleSortWithFlag();
	CInsertionSort *insertionSort = new CInsertionSort();
	CSelectionSort *selectionSort = new CSelectionSort();
	CHeapSort *heapSort = new CHeapSort();
	CMergeSort *mergeSort = new CMergeSort();
	CQuickSort *quickSort = new CQuickSort();
	CRadixSort *radixSort = new CRadixSort();
	CCountingSort *countingSort = new CCountingSort();
	CSmoothSort *smoothSort = new CSmoothSort();

	std::vector<ISortInterface *> sorters;
	sorters.push_back(bubbleSort);
	sorters.push_back(bubbleSortWithFlag);
	sorters.push_back(insertionSort);
	sorters.push_back(selectionSort);
	sorters.push_back(heapSort);
	sorters.push_back(mergeSort);
	sorters.push_back(quickSort);
	sorters.push_back(radixSort);
	sorters.push_back(countingSort);
	sorters.push_back(smoothSort);

	std::vector<int> t;

	// Add sorters
	for (unsigned int i = 0; i < sorters.size(); i++) {
		
		// generate some data
		t.clear();
		generateRandom(t);

		// run the sorter
		//std::string str = ;
		std::cout << sorters[i]->identify() << std::endl;
		sorters[i]->sort(t);
		//sorters[i]->display(t);
	}

	sorters.clear();
	delete bubbleSort;
	delete bubbleSortWithFlag;
	delete insertionSort;
	delete selectionSort;
	delete heapSort;
	delete mergeSort;
	delete quickSort;
	delete radixSort;
	delete countingSort;
	delete smoothSort;

	std::cout << "Press a key..." << std::endl;
	std::cin.get();

    return 0;
}

