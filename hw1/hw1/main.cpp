/*

	File:
		main.cpp
	
	Purpose: 
		Defines the entry point for this console application.

	Author: 
		mpvats@syr.edu

*/


#include "stdafx.h"
#include "SingleList.h"
#include "DoubleList.h"

#include <time.h>

int g_S1[100];	// Stores sequence S1: sequence of numbers from 1..100
int g_S2[100];  // Stores sequence S2: pseudo-random sequence of distinct numbers of length 100

//
// Generates sequence S1 and stores it in g_S1.
//
// This is a sequence of numbers from 1..100.
//
void generateS1()
{
	// zero the memory
	memset(g_S1, 0, sizeof(g_S1));

	// each element is 1 to 100
	for (int i=0; i < 100; i++)
	{
		g_S1[i] = i + 1;
	}
}

//
// Generates sequence S2 and stores it in g_S2.
//
// This is a sequence of distinct numbers from 1..100. This function will keep
// generating random number until all elments are filled.
//
void generateS2(unsigned int seed=0)
{
	// each element represents whether the value has been
	// stored in the g_S2 array
	bool isInTable[100];

	// initialize arrays
	memset(isInTable, false, sizeof(isInTable));
	memset(g_S2, 0, sizeof(g_S2));

	// generate seed
	(!seed) ? srand((unsigned)time(NULL)) : srand(seed);
	
	for (int i = 0; i < 100; i++)
	{
		// get distinct numbers
		while (true)
		{
			int randomNumber = rand() % 100;

			// only add the random number to g_S2 if it's not already added. 
			// if it was added already, generate another number.
			if (!isInTable[randomNumber])
			{
				isInTable[randomNumber] = true;
				g_S2[i] = randomNumber + 1;
				break;
			}
		}
	}
}

//
// Extecute the Team of Four operation on S2
//
// Given a linked list of numbers, it will rearrange the list so that, for each block in the list of
// size 4, the node will be sorted in ascending order, according to the data stored in these nodes.
//
void TeamOfFourS2()
{
	SingleList *sl = new SingleList();
	SingleList::Node *sltmp = NULL;

	// Populate the Single List w/S2
	for (int i = 0; i < 100; i++)
	{
		sltmp = new SingleList::Node();
		sltmp->value = g_S2[i];
		sl->AddAtTail(sltmp);
	}

	std::cout << "*****        Single Linked List         *****" << std::endl;
	std::cout << "***** Before the Team of Four operation *****" << std::endl;
	sl->PrintResults();

	// Exectue the TeamOfFour
	sl->TeamOfFour();

	std::cout << "***** After the Team of Four operation *****" << std::endl;
	sl->PrintResults();

	sl->RemoveAll();
	delete sl;

	DoubleList *dl = new DoubleList();
	DoubleList::Node *dltmp = NULL;

	// Populate the Double List w/S2
	for (int i = 0; i < 100; i++)
	{
		dltmp = new DoubleList::Node();
		dltmp->value = g_S2[i];
		dl->AddAtTail(dltmp);
	}

	std::cout << "*****        Double Linked List         *****" << std::endl;
	std::cout << "***** Before the Team of Four operation *****" << std::endl;
	dl->PrintResults();

	// Exectue the TeamOfFour
	dl->TeamOfFour();

	std::cout << "***** After the Team of Four operation *****" << std::endl;
	dl->PrintResults();

	dl->RemoveAll();
	delete dl;
}

//
// Extecute the Reverse operation on S1
//
// Given a linked list of numbers, it will rearrange the list so that the numbers will be in reverse
// order.
//
void ReverseS1()
{
	SingleList *sl = new SingleList();
	SingleList::Node *sltmp = NULL;

	// Populate the Single List w/S1
	for (int i = 0; i < 100; i++)
	{
		sltmp = new SingleList::Node();
		sltmp->value = g_S1[i];
		sl->AddAtTail(sltmp);
	}

	std::cout << "*****        Single Linked List    *****" << std::endl;
	std::cout << "***** Before the Reverse operation *****" << std::endl;
	sl->PrintResults();

	// Exectue the Reverse
	sl->Reverse();

	std::cout << "***** After the Reverse operation *****" << std::endl;
	sl->PrintResults();

	sl->RemoveAll();
	delete sl;

	DoubleList *dl = new DoubleList();
	DoubleList::Node *dltmp = NULL;

	// Populate the Double List w/S1
	for (int i = 0; i < 100; i++)
	{
		dltmp = new DoubleList::Node();
		dltmp->value = g_S1[i];
		dl->AddAtTail(dltmp);
	}

	std::cout << "*****      Double Linked List      *****" << std::endl;
	std::cout << "***** Before the Reverse operation *****" << std::endl;
	dl->PrintResults();

	// Exectue the Reverse
	dl->Reverse();

	std::cout << "***** After the Reverse operation *****" << std::endl;
	dl->PrintResults();

	dl->RemoveAll();
	delete dl;
}

//
// Extecute the Reverse operation on S2
//
// Given a linked list of numbers, it will rearrange the list so that the numbers will be in reverse
// order.
//
void ReverseS2()
{
	SingleList *sl = new SingleList();
	SingleList::Node *sltmp = NULL;

	// Populate the Single List w/S2
	for (int i = 0; i < 100; i++)
	{
		sltmp = new SingleList::Node();
		sltmp->value = g_S2[i];
		sl->AddAtTail(sltmp);
	}

	std::cout << "*****       Single Linked List     *****" << std::endl;
	std::cout << "***** Before the Reverse operation *****" << std::endl;
	sl->PrintResults();

	// Exectue the Reverse
	sl->Reverse();

	std::cout << "***** After the Reverse operation *****" << std::endl;
	sl->PrintResults();

	sl->RemoveAll();
	delete sl;

	DoubleList *dl = new DoubleList();
	DoubleList::Node *dltmp = NULL;

	// Populate the Double List w/S2
	for (int i = 0; i < 100; i++)
	{
		dltmp = new DoubleList::Node();
		dltmp->value = g_S2[i];
		dl->AddAtTail(dltmp);
	}

	std::cout << "*****      Double Linked List      *****" << std::endl;
	std::cout << "***** Before the Reverse operation *****" << std::endl;
	dl->PrintResults();

	// Exectue the Reverse
	dl->Reverse();

	std::cout << "***** After the Reverse operation *****" << std::endl;
	dl->PrintResults();

	dl->RemoveAll();
	delete dl;
}

//
// Extecute the Shuffle operation on S1
//
// Given a linked list of numbers, it will shue the rst half of the list with the second half
// of the list so that the nodes will be listed from each half alternatively.
//
void ShuffleS1()
{
	SingleList *sl = new SingleList();
	SingleList::Node *sltmp = NULL;

	// Populate the Single List w/S1
	for (int i = 0; i < 100; i++)
	{
		sltmp = new SingleList::Node();
		sltmp->value = g_S1[i];
		sl->AddAtTail(sltmp);
	}

	std::cout << "*****      Single Linked List      *****" << std::endl;
	std::cout << "***** Before the Shuffle operation *****" << std::endl;
	sl->PrintResults();

	// Exectue the Shuffle
	sl->Shuffle();

	std::cout << "***** After the Shuffle operation *****" << std::endl;
	sl->PrintResults();

	sl->RemoveAll();
	delete sl;

	DoubleList *dl = new DoubleList();
	DoubleList::Node *dltmp = NULL;

	// Populate the Double List w/S1
	for (int i = 0; i < 100; i++)
	{
		dltmp = new DoubleList::Node();
		dltmp->value = g_S1[i];
		dl->AddAtTail(dltmp);
	}

	std::cout << "*****      Double Linked List      *****" << std::endl;
	std::cout << "***** Before the Shuffle operation *****" << std::endl;
	dl->PrintResults();

	// Exectue the Shuffle
	dl->Shuffle();

	std::cout << "***** After the Shuffle operation *****" << std::endl;
	dl->PrintResults();

	dl->RemoveAll();
	delete dl;
}

//
// Extecute the Shuffle operation on S2
//
// Given a linked list of numbers, it will shue the rst half of the list with the second half
// of the list so that the nodes will be listed from each half alternatively.
//
void ShuffleS2()
{
	SingleList *sl = new SingleList();
	SingleList::Node *sltmp = NULL;

	// Populate the Single List w/S2
	for (int i = 0; i < 100; i++)
	{
		sltmp = new SingleList::Node();
		sltmp->value = g_S2[i];
		sl->AddAtTail(sltmp);
	}

	std::cout << "*****      Single Linked List      *****" << std::endl;
	std::cout << "***** Before the Shuffle operation *****" << std::endl;
	sl->PrintResults();

	// Exectue the Shuffle
	sl->Shuffle();

	std::cout << "***** After the Shuffle operation *****" << std::endl;
	sl->PrintResults();

	sl->RemoveAll();
	delete sl;

	DoubleList *dl = new DoubleList();
	DoubleList::Node *dltmp = NULL;

	// Populate the Double List w/S2
	for (int i = 0; i < 100; i++)
	{
		dltmp = new DoubleList::Node();
		dltmp->value = g_S2[i];
		dl->AddAtTail(dltmp);
	}

	std::cout << "*****      Double Linked List      *****" << std::endl;
	std::cout << "***** Before the Shuffle operation *****" << std::endl;
	dl->PrintResults();

	// Exectue the Shuffle
	dl->Shuffle();

	std::cout << "***** After the Shuffle operation *****" << std::endl;
	dl->PrintResults();

	dl->RemoveAll();
	delete dl;
}

int main()
{
	std::cout << "Homework 1: Linked List" << std::endl;

	generateS1();   // generate S1 sequence
	generateS2();   // generate S2 sequence

	                // Test Case 1 and 2
	TeamOfFourS2(); // Exectue Team of Four using S2

					// Test Case 3 and 4
	ReverseS1();    // Execute Reverse using S1

					// Test Case 5 and 6
	ReverseS2();    // Execute Reverse using S2

					// Test Case 7 and 8
	ShuffleS1();    // Execute Shuffle using S1

					// Test Case 9 and 10
	ShuffleS2();    // Execute Shuffle using S2
	
	std::cout << "Press any key to continue..." << std::endl;
	getchar();

    return 0;
}

