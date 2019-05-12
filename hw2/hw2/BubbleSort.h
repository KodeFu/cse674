/*

File:
    BubbleSort.h

Purpose:
    Class definition for the BubbleSort algorithm.

Author:
    mpvats@syr.edu

*/

#pragma once
#include "SortInterface.h"
class CBubbleSort :
	public ISortInterface
{
public:
	CBubbleSort();
	~CBubbleSort();
	void sort(std::vector<int>& vector);
	std::string identify();
};

