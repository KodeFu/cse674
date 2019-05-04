// hw2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SortInterface.h"

#include "BubbleSort.h"
#include "BubbleSortWithFlag.h"

int main()
{
	CBubbleSort *bubbleSort = new CBubbleSort();
	CBubbleSortWithFlag *bubbleSortWithFlag = new CBubbleSortWithFlag();
	std::vector<ISortInterface *> sorters;
	sorters.push_back(bubbleSort);
	sorters.push_back(bubbleSortWithFlag);

	std::vector<int> t;
	t.push_back(5);
	t.push_back(3);
	t.push_back(2);
	t.push_back(7);
	t.push_back(9);
	t.push_back(4);

	// Add sorters
	for (int i = 0; i < sorters.size(); i++) {
		std::string str = sorters[i]->identify();
		std::cout << str << std::endl;
		sorters[i]->sort(t);
		sorters[i]->display(t);
	}

	delete bubbleSort;
	delete bubbleSortWithFlag;

	std::cout << "Press a key..." << std::endl;
	std::cin.get();

    return 0;
}

