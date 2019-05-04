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
	for (unsigned int i = 1; i < vector.size(); i++) {
		int j = i;
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