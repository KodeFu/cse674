/*

	File:
		MergeSort.h

	Purpose:
		Class definition for the MergeSort algorithm.

	Author:
		mpvats@syr.edu

*/
#pragma once
#include "SortInterface.h"

class CMergeSort :
	public ISortInterface
{
public:
	CMergeSort();
	~CMergeSort();
	void sort(std::vector<int>& vector);
	std::string identify();

private:
	void mergeSort(std::vector<int>& vector, int p, int r);
	void merge(std::vector<int>& vector, int p, int q, int r);
};

