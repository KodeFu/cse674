#include "stdafx.h"
#include "BubbleSortWithFlag.h"


CBubbleSortWithFlag::CBubbleSortWithFlag()
{
}


CBubbleSortWithFlag::~CBubbleSortWithFlag()
{
}

void CBubbleSortWithFlag::sort(std::vector<int>& vector)
{
	bool swapped;

	// go through each element in the vector
	for (size_t i = 0; i < vector.size(); i++) {

		// swapped holds whether we swapped or not
		swapped = false;

		// compare is to the next element in the vector
		for (size_t j = i + 1; j < vector.size(); j++) {

			// swap elements if the current element is smaller then the previous element
			if (vector[j] < vector[i])	{
				int tmp = vector[i];
				vector[i] = vector[j];
				vector[j] = tmp;

				swapped = true;
			}
		}

		// if we didn't swap in the run through the vector, vector must be sorted
		if (!swapped) break;
	}
}

std::string CBubbleSortWithFlag::identify()
{
	return "BubbleSort with Flag";
}