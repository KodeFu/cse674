#include "stdafx.h"
#include "CountingSort.h"

//
// Counting sort based off course notes:
//     trifort.org/ads/index.php/dlcode/index/countingSort.cpp.html
//
// Changelog:
//     - Use C++ class structure
//     - Handle large data sets (1000000)
//
CCountingSort::CCountingSort()
{
}


CCountingSort::~CCountingSort()
{
}

void CCountingSort::sort(std::vector<int>& vector)
{
	countingSort(vector);
}

std::string CCountingSort::identify()
{
	return "Counting Sort";
}

void CCountingSort::countingSort(std::vector<int>& vector) 
{
	const int max_value = 1000000;
	std::vector<int> counts;

	//clear counts
	for (int i = 0; i < max_value; ++i) {
		counts.push_back(0);
	}

	//calculate count of each number
	for (size_t i = 0; i < vector.size(); ++i) {
		++counts[vector[i]];
	}

	//write back to the array
	vector.clear();
	for (int i = 0; i < max_value; ++i) {
		int c = counts[i];
		for (int j = 0; j < c; ++j) {
			vector.push_back(i);
		}
	}
}