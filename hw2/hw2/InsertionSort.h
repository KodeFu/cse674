#pragma once
#include "SortInterface.h"
class CInsertionSort :
	public ISortInterface
{
public:
	CInsertionSort();
	~CInsertionSort();
	void sort(std::vector<int>& vector);
	std::string identify();
};

