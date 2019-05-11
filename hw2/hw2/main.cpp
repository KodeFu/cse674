// hw2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SortInterface.h"

#include "BubbleSort.h"
#include "BubbleSortWithFlag.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "RadixSort.h"
#include "CountingSort.h"
#include "SmoothSort.h"
#include "GenerateInput.h"
#include "WindowsStopWatch.h"

#define MAX_RANGE 10000

void generateRandom(std::vector<int>& data)
{
	srand((unsigned int) time(NULL));
	for (int i = 0; i < MAX_RANGE; i++) {
		data.push_back(((rand() << 15) | rand()) % MAX_RANGE + 1);
	}
}

int main()
{
	CWindowsStopWatch *stopWatch;

	CBubbleSort *bubbleSort = new CBubbleSort();
	CBubbleSortWithFlag *bubbleSortWithFlag = new CBubbleSortWithFlag();
	CInsertionSort *insertionSort = new CInsertionSort();
	CSelectionSort *selectionSort = new CSelectionSort();
	CHeapSort *heapSort = new CHeapSort();
	CMergeSort *mergeSort = new CMergeSort();
	CQuickSort *quickSort = new CQuickSort();
	CRadixSort *radixSort = new CRadixSort();
	CCountingSort *countingSort = new CCountingSort();
	CSmoothSort *smoothSort = new CSmoothSort();

	std::vector<ISortInterface *> sorters;
	sorters.push_back(bubbleSort);
	sorters.push_back(bubbleSortWithFlag);
	sorters.push_back(insertionSort);
	sorters.push_back(selectionSort);
	sorters.push_back(heapSort);
	sorters.push_back(mergeSort);
	sorters.push_back(quickSort);
	sorters.push_back(radixSort);
	sorters.push_back(countingSort);
	sorters.push_back(smoothSort);

	// Create input data files
	CGenerateInput *genInput = new CGenerateInput();
	genInput->setMaxRange(1000000);

	// Uncomment to regenerate input file. Otherwise current input files ascending.txt, 
	// descending.txt and random.txt will be reused.
	//genInput->generateInputFiles();

	// Run sorters
	int step;
	int maxStep;
	for (unsigned int i = 0; i < sorters.size(); i++) {
				
		// Set starting step
		step = 1000;
		maxStep = 1000000;

		while (step <= maxStep) {

			for (unsigned int j = 0; j < 3; j++) {

				// Generate some data
				std::vector<int> *t = new std::vector<int>;
				t->clear();
				genInput->getRandom(*t, step);

				std::cout << step << ": " << sorters[i]->identify();

				// Start the stop measurement
				stopWatch = new CWindowsStopWatch();
				stopWatch->start();

				// Run the sorter
				sorters[i]->sort(*t);

				// Stop the measurement
				stopWatch->stop();
				std::cout << " time: " << stopWatch->getTime() << std::endl;
				delete stopWatch;

				// Delete the data
				delete t;
			}

			if (step == maxStep) break;

			// Double the step
			step = step * 2;
			if (step > maxStep) step = maxStep;
		}
	}

	delete genInput;

	sorters.clear();
	delete bubbleSort;
	delete bubbleSortWithFlag;
	delete insertionSort;
	delete selectionSort;
	delete heapSort;
	delete mergeSort;
	delete quickSort;
	delete radixSort;
	delete countingSort;
	delete smoothSort;

	std::cout << "Press a key..." << std::endl;
	std::cin.get();

    return 0;
}

