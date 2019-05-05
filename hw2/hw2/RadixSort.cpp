#include "stdafx.h"
#include "RadixSort.h"


CRadixSort::CRadixSort()
{
}


CRadixSort::~CRadixSort()
{
}

void CRadixSort::sort(std::vector<int>& vector)
{
	radixSort(vector);
}

std::string CRadixSort::identify()
{
	return "Radix Sort";
}

//
// Radix Sort based off code from course notes:
//     trifort.org/ads/index.php/dlcode/index/radixSort.cpp.html
//
// Adapted to:
//     - Use int vectors
//
void CRadixSort::radixSort(std::vector<int>& vector) 
{
	const int radix = 10;
	const int digits = 10; 
	std::queue<int> queues[radix];

	for (int i = 0, factor = 1; i < digits; factor *= radix, i++) {
		//fill up the queues
		for (int j = 0; j < vector.size(); j++) {
			queues[(vector[j] / factor) % radix].push(vector[j]);
		}

		//empty the queues 
		int k = 0;
		for (int j = 0; j < radix; j++) {
			while (!queues[j].empty()) {
				vector[k] = queues[j].front();
				queues[j].pop();
				k++;
			}
		}
	}
}