#pragma once
#include "SortInterface.h"
class CCountingSort :
	public ISortInterface
{
public:
	CCountingSort();
	~CCountingSort();
	void sort(std::vector<int>& vector);
	std::string identify();

private:
	void countingSort(std::vector<int>& vector);
};

