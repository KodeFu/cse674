// hw1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SingleList.h"
#include "DoubleList.h"

#include <time.h>

int g_S1[100];
int g_S2[100];

void generateS1()
{
	memset(g_S1, 0, sizeof(g_S1));

	for (int i=0; i < 100; i++)
	{
		g_S1[i] = i + 1;
	}
}

void generateS2(unsigned int seed=0)
{
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

			if (!isInTable[randomNumber])
			{
				isInTable[randomNumber] = true;
				g_S2[i] = randomNumber + 1;
				break;
			}
		}
	}
}

void TeamOfFourS2()
{
	SingleList *sl = new SingleList();
	SingleList::Node *sltmp = NULL;

	// Single List
	for (int i = 0; i < 100; i++)
	{
		sltmp = new SingleList::Node();
		sltmp->value = g_S2[i];
		sl->AddAtTail(sltmp);
	}

	std::cout << "***** Before the Team of Four operation *****" << std::endl;
	sl->PrintResults();
	sl->TeamOfFour();
	std::cout << "***** After the Team of Four operation *****" << std::endl;
	sl->PrintResults();

	sl->RemoveAll();
	delete sl;

	DoubleList *dl = new DoubleList();
	DoubleList::Node *dltmp = NULL;

	// Single List
	for (int i = 0; i < 100; i++)
	{
		dltmp = new DoubleList::Node();
		dltmp->value = g_S2[i];
		dl->AddAtTail(dltmp);
	}

	std::cout << "***** Before the Team of Four operation *****" << std::endl;
	dl->PrintResults();
	dl->TeamOfFour();
	std::cout << "***** After the Team of Four operation *****" << std::endl;
	dl->PrintResults();

	dl->RemoveAll();
	delete dl;
}


void ReverseS1()
{
	SingleList *sl = new SingleList();
	SingleList::Node *sltmp = NULL;

	// Single List
	for (int i = 0; i < 100; i++)
	{
		sltmp = new SingleList::Node();
		sltmp->value = g_S1[i];
		sl->AddAtTail(sltmp);
	}

	std::cout << "***** Before the Reverse operation *****" << std::endl;
	sl->PrintResults();
	sl->Reverse();
	std::cout << "***** After the Reverse operation *****" << std::endl;
	sl->PrintResults();

	sl->RemoveAll();
	delete sl;

	DoubleList *dl = new DoubleList();
	DoubleList::Node *dltmp = NULL;

	// Double List
	for (int i = 0; i < 100; i++)
	{
		dltmp = new DoubleList::Node();
		dltmp->value = g_S1[i];
		dl->AddAtTail(dltmp);
	}

	std::cout << "***** Before the Reverse operation *****" << std::endl;
	dl->PrintResults();
	dl->Reverse();
	std::cout << "***** After the Reverse operation *****" << std::endl;
	dl->PrintResults();

	dl->RemoveAll();
	delete dl;
}

void ReverseS2()
{
	SingleList *sl = new SingleList();
	SingleList::Node *sltmp = NULL;

	// Single List
	for (int i = 0; i < 100; i++)
	{
		sltmp = new SingleList::Node();
		sltmp->value = g_S2[i];
		sl->AddAtTail(sltmp);
	}

	std::cout << "***** Before the Reverse operation *****" << std::endl;
	sl->PrintResults();
	sl->Reverse();
	std::cout << "***** After the Reverse operation *****" << std::endl;
	sl->PrintResults();

	sl->RemoveAll();
	delete sl;

	DoubleList *dl = new DoubleList();
	DoubleList::Node *dltmp = NULL;

	// Double List
	for (int i = 0; i < 100; i++)
	{
		dltmp = new DoubleList::Node();
		dltmp->value = g_S2[i];
		dl->AddAtTail(dltmp);
	}

	std::cout << "***** Before the Reverse operation *****" << std::endl;
	dl->PrintResults();
	dl->Reverse();
	std::cout << "***** After the Reverse operation *****" << std::endl;
	dl->PrintResults();

	dl->RemoveAll();
	delete dl;
}

void ShuffleS1()
{
	SingleList *sl = new SingleList();
	SingleList::Node *sltmp = NULL;

	// Single List
	for (int i = 0; i < 100; i++)
	{
		sltmp = new SingleList::Node();
		sltmp->value = g_S1[i];
		sl->AddAtTail(sltmp);
	}

	std::cout << "***** Before the Shuffle operation *****" << std::endl;
	sl->PrintResults();
	sl->Shuffle();
	std::cout << "***** After the Shuffle operation *****" << std::endl;
	sl->PrintResults();

	sl->RemoveAll();
	delete sl;

	DoubleList *dl = new DoubleList();
	DoubleList::Node *dltmp = NULL;

	// Double List
	for (int i = 0; i < 100; i++)
	{
		dltmp = new DoubleList::Node();
		dltmp->value = g_S1[i];
		dl->AddAtTail(dltmp);
	}

	std::cout << "***** Before the Shuffle operation *****" << std::endl;
	dl->PrintResults();
	dl->Shuffle();
	std::cout << "***** After the Shuffle operation *****" << std::endl;
	dl->PrintResults();

	dl->RemoveAll();
	delete dl;
}

void ShuffleS2()
{
	SingleList *sl = new SingleList();
	SingleList::Node *sltmp = NULL;

	// Single List
	for (int i = 0; i < 100; i++)
	{
		sltmp = new SingleList::Node();
		sltmp->value = g_S2[i];
		sl->AddAtTail(sltmp);
	}

	std::cout << "***** Before the Shuffle operation *****" << std::endl;
	sl->PrintResults();
	sl->Shuffle();
	std::cout << "***** After the Shuffle operation *****" << std::endl;
	sl->PrintResults();

	sl->RemoveAll();
	delete sl;

	DoubleList *dl = new DoubleList();
	DoubleList::Node *dltmp = NULL;

	// Double List
	for (int i = 0; i < 100; i++)
	{
		dltmp = new DoubleList::Node();
		dltmp->value = g_S2[i];
		dl->AddAtTail(dltmp);
	}

	std::cout << "***** Before the Shuffle operation *****" << std::endl;
	dl->PrintResults();
	dl->Shuffle();
	std::cout << "***** After the Shuffle operation *****" << std::endl;
	dl->PrintResults();

	dl->RemoveAll();
	delete dl;
}

int main()
{
	std::cout << "Homework 1: Linked List" << std::endl;

	generateS1();
	generateS2();

	//TeamOfFourS2();

	//ReverseS1();
	//ReverseS2();

	ShuffleS1();
	ShuffleS2();

	std::cout << "Press any key to continue..." << std::endl;
	getchar();
    return 0;
}

