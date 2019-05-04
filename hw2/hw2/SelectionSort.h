#pragma once
#include "SortInterface.h"
class CSelectionSort :
	public ISortInterface
{
public:
	CSelectionSort();
	~CSelectionSort();
	void sort(std::vector<int>& vector);
	std::string identify();
};

