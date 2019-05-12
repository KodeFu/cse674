/*

	File:
		BubbleSortWithFlag.h

	Purpose:
		Class definition for the BubbleSort w/Flag algorithm. This algorithm is like the 
		BubbleSort algorithm except if no swaps are detect, the sort is considered complete.

	Author:
		mpvats@syr.edu

*/
#pragma once
#include "SortInterface.h"

class CBubbleSortWithFlag :
	public ISortInterface
{
public:
	CBubbleSortWithFlag();
	~CBubbleSortWithFlag();
	void sort(std::vector<int>& vector);
	std::string identify();
};

