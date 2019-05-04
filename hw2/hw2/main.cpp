// hw2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SortInterface.h"

#include "BubbleSort.h"
#include "BubbleSortWithFlag.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "HeapSort.h"

int main()
{
	CBubbleSort *bubbleSort = new CBubbleSort();
	CBubbleSortWithFlag *bubbleSortWithFlag = new CBubbleSortWithFlag();
	CInsertionSort *insertionSort = new CInsertionSort();
	CSelectionSort *selectionSort = new CSelectionSort();
	CHeapSort *heapSort = new CHeapSort();

	std::vector<ISortInterface *> sorters;
	//sorters.push_back(bubbleSort);
	//sorters.push_back(bubbleSortWithFlag);
	//sorters.push_back(insertionSort);
	//sorters.push_back(selectionSort);
	sorters.push_back(heapSort);

	std::vector<int> t;
	t.push_back(5);
	t.push_back(3);
	t.push_back(2);
	t.push_back(7);
	t.push_back(9);
	t.push_back(4);
	t.push_back(10);
	t.push_back(1);
	t.push_back(15);

	// Add sorters
	for (unsigned int i = 0; i < sorters.size(); i++) {
		std::string str = sorters[i]->identify();
		std::cout << str << std::endl;
		sorters[i]->sort(t);
		sorters[i]->display(t);
	}

	sorters.clear();
	delete bubbleSort;
	delete bubbleSortWithFlag;
	delete insertionSort;
	delete selectionSort;
	delete heapSort;

	std::cout << "Press a key..." << std::endl;
	std::cin.get();

    return 0;
}

