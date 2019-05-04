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

