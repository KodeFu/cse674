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

