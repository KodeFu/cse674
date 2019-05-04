#include "stdafx.h"
#include "InsertionSort.h"


CInsertionSort::CInsertionSort()
{
}


CInsertionSort::~CInsertionSort()
{
}

void CInsertionSort::sort(std::vector<int>& vector)
{
	// go through each element in the vector
	for (size_t i = 1; i < vector.size(); i++) {

		// 
		int j = i;

		// if previous value is less then current, swap them; keep doing this
		// until we've gone through the rest of the vector (descending)
		while ((j > 0) && (vector[j - 1] > vector[j])) {
			int tmp = vector[j - 1];
			vector[j - 1] = vector[j];
			vector[j] = tmp;

			j--;
		}
	}
}

std::string CInsertionSort::identify() 
{ 
	return "Insertion Sort"; 
};