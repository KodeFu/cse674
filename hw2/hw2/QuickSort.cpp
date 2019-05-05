#include "stdafx.h"
#include "QuickSort.h"


CQuickSort::CQuickSort()
{
}


CQuickSort::~CQuickSort()
{
}

void CQuickSort::sort(std::vector<int>& vector)
{
	int p = 0;
	int r = vector.size() - 1;

	quicksort(vector, p, r);
}

std::string CQuickSort::identify()
{
	return "Quick Sort";
}

int CQuickSort::partition(std::vector<int>& vector, int p, int r)
{
	int tmp;
	int pivot = vector[r]; // pivot set to last element
	int i = p - 1; // index of less than pivot

	// go through vector up to the pivot; sort them such that items less than
	// pivot are left of the pivot and items greater then pivot are to the right
	for (int j = p; j <= r - 1; j++) {

		// if item less than pivot, advance i which is the counter for the less
		// than list
		if (vector[j] <= pivot) {
			i = i + 1;
			
			// swap item to the left
			tmp = vector[i];
			vector[i] = vector[j];
			vector[j] = tmp;
		}
	}

	// put the pivot in the right spot; between left and right halves
	tmp = vector[i+1];
	vector[i+1] = vector[r];
	vector[r] = tmp;

	return i + 1;
}

void CQuickSort::quicksort(std::vector<int>& vector, int p, int r)
{
	if (p < r) {
		int q = partition(vector, p, r);
		quicksort(vector, p, q - 1);
		quicksort(vector, q + 1, r);
	}
}