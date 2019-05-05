#pragma once
#include "SortInterface.h"
class CQuickSort :
	public ISortInterface
{
public:
	CQuickSort();
	~CQuickSort();
	void sort(std::vector<int>& vector);
	std::string identify();

private:
	int partition(std::vector<int>& vector, int p, int r);
	void quicksort(std::vector<int>& vector, int p, int r);
};

