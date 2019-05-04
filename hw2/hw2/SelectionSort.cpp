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

		// leastIndex holds the index of the smallest value
		int leastIndex = i;

		// find the smallest value
		for (size_t j=i+1; j<vector.size(); j++) { 
			if (vector[j] < vector[leastIndex]) {
				leastIndex = j;
			}
		}
		
		// swap the smallest value with the left hand side
		int tmp = vector[i];
		vector[i] = vector[leastIndex];
		vector[leastIndex] = tmp;
	}
}

std::string CSelectionSort::identify() 
{ 
	return "Selection Sort"; 
};