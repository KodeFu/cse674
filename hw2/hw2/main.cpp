/*

	File:
		main.cpp

	Purpose:
		The hw2 application which performs several sorting methods on random ascending, random
		descending, and random data.

	Author:
		mpvats@syr.edu

*/

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
	/*std::vector<int> d;
	genInput->generateRandom(d);
	genInput->writeFile(d, "random.txt");
	quickSort->sort(d);
	genInput->writeFile(d, "ascending.txt");
	std::reverse(d.begin(), d.end());
	genInput->writeFile(d, "descending.txt");
	*/

	//
	// ASCENDING DATA RUN
	//
	std::cout << "============================================" << std::endl;
	std::cout << " Ascending" << std::endl;
	std::cout << "============================================" << std::endl;
	int step;
	int maxStep = 1000000;
	int sum;
	for (unsigned int i = 0; i < sorters.size(); i++) {
				
		// Set starting step
		step = 1000;

		while (step <= maxStep) {

			sum = 0;
			std::cout << sorters[i]->identify() << " " << step;

			for (unsigned int j = 0; j < 3; j++) {

				// Generate some data
				std::vector<int> *t = new std::vector<int>;
				genInput->getAscending(*t, step);

				// Start the stop measurement
				stopWatch = new CWindowsStopWatch();
				stopWatch->start();

				// Run the sorter
				sorters[i]->sort(*t);

				// Stop the measurement
				stopWatch->stop();
				std::cout << " " << stopWatch->getTime();
				sum += stopWatch->getTime();
				delete stopWatch;

				// Delete the data
				delete t;
			}

			std::cout << " " << sum / 3;
			std::cout << std::endl;

			if (step == maxStep) break;

			// Double the step
			step = step * 2;
			if (step > maxStep) step = maxStep;
		}
	}

	//
	// DESCENDING DATA RUN
	//
	std::cout << "============================================" << std::endl;
	std::cout << " Descending" << std::endl;
	std::cout << "============================================" << std::endl;
	for (unsigned int i = 0; i < sorters.size(); i++) {

		// Set starting step
		step = 1000;

		while (step <= maxStep) {

			//
			// DESCENDING DATA RUN
			//
			sum = 0;
			std::cout << sorters[i]->identify() << " " << step;

			for (unsigned int j = 0; j < 3; j++) {

				// Generate some data
				std::vector<int> *t = new std::vector<int>;
				genInput->getDescending(*t, step);


				// Start the stop measurement
				stopWatch = new CWindowsStopWatch();
				stopWatch->start();

				// Run the sorter
				sorters[i]->sort(*t);

				// Stop the measurement
				stopWatch->stop();
				std::cout << " " << stopWatch->getTime();
				sum += stopWatch->getTime();
				delete stopWatch;

				// Delete the data
				delete t;
			}

			std::cout << " " << sum / 3;
			std::cout << std::endl;

			if (step == maxStep) break;

			// Double the step
			step = step * 2;
			if (step > maxStep) step = maxStep;
		}
	}

	//
	// RANDOM DATA RUN
	//
	std::cout << "============================================" << std::endl;
	std::cout << " Random" << std::endl;
	std::cout << "============================================" << std::endl;
	for (unsigned int i = 0; i < sorters.size(); i++) {

		// Set starting step
		step = 1000;

		while (step <= maxStep) {

			//
			// RANDOM DATA RUN
			//
			sum = 0;
			std::cout << sorters[i]->identify() << " " << step;

			for (unsigned int j = 0; j < 3; j++) {

				// Generate some data
				std::vector<int> *t = new std::vector<int>;
				genInput->getRandom(*t, step);


				// Start the stop measurement
				stopWatch = new CWindowsStopWatch();
				stopWatch->start();

				// Run the sorter
				sorters[i]->sort(*t);

				// Stop the measurement
				stopWatch->stop();
				std::cout << " " << stopWatch->getTime();
				sum += stopWatch->getTime();
				delete stopWatch;

				// Delete the data
				delete t;
			}

			std::cout << " " << sum / 3;
			std::cout << std::endl;

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

    return 0;
}

