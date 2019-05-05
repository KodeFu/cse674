#pragma once
#include "SortInterface.h"
class CSmoothSort :
	public ISortInterface
{
public:
	CSmoothSort();
	~CSmoothSort();
	void sort(std::vector<int>& vector);
	std::string identify();
};

