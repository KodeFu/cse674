#include "stdafx.h"
#include "BubbleSort.h"


CBubbleSort::CBubbleSort()
{
}


CBubbleSort::~CBubbleSort()
{
}

void CBubbleSort::sort(std::vector<int>& vector)
{
	for (int i = 0; i < vector.size(); i++) {
		for (int j = i + 1; j < vector.size(); j++) {
			if (vector[j] < vector[i])
			{
				int tmp = vector[i];
				vector[i] = vector[j];
				vector[j] = tmp;
			}
		}
	}
}

std::string CBubbleSort::identify()
{
	return "BubbleSort";
}