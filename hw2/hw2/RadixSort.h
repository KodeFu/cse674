/*

	File:
		Radix.h

	Purpose:
		Class definition for the RadixSort algorithm.

	Author:
		mpvats@syr.edu

*/

#pragma once
#include "SortInterface.h"
class CRadixSort :
	public ISortInterface
{
public:
	CRadixSort();
	~CRadixSort();
	void sort(std::vector<int>& vector);
	std::string identify();

private:
	void radixSort(std::vector<int>& data);
};

