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

	for (size_t i = 0; i < vector.size(); i++) {
		swapped = false;
		for (size_t j = i + 1; j < vector.size(); j++) {
			if (vector[j] < vector[i])
			{
				int tmp = vector[i];
				vector[i] = vector[j];
				vector[j] = tmp;

				swapped = true;
			}
		}

		if (!swapped) break;
	}
}

std::string CBubbleSortWithFlag::identify()
{
	return "BubbleSort with Flag";
}