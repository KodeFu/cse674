#include "stdafx.h"
#include "SelectionSort.h"


CSelectionSort::CSelectionSort()
{
}


CSelectionSort::~CSelectionSort()
{
}

void CSelectionSort::sort(std::vector<int>& vector) 
{
	for (size_t i = 0; i < vector.size() - 1; i++) {
		int leastIndex = i;
		for (size_t j=i+1; j<vector.size(); j++) { 
			if (vector[j] < vector[leastIndex]) {
				leastIndex = j;
			}
		}
		
		int tmp = vector[i];
		vector[i] = vector[leastIndex];
		vector[leastIndex] = tmp;
	}
}

std::string CSelectionSort::identify() 
{ 
	return "Selection Sort"; 
};