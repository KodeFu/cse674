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
	SingleList *ll = new SingleList();
	SingleList::Node *tmp = NULL;

	// Single List
	for (int i = 0; i < 100; i++)
	{
		tmp = new SingleList::Node();
		tmp->value = g_S2[i];
		ll->AddAtTail(tmp);
	}

	std::cout << "***** Before the Team of Four operation *****" << std::endl;
	//ll->PrintResults();
	//ll->Shuffle();
	std::cout << "***** After the Team of Four operation *****" << std::endl;
	//ll->PrintResults();

	ll->RemoveAll();
	delete ll;
}


void ReverseS1()
{
	SingleList *ll = new SingleList();
	SingleList::Node *tmp = NULL;

	// Single List
	for (int i = 0; i < 100; i++)
	{
		tmp = new SingleList::Node();
		tmp->value = g_S1[i];
		ll->AddAtTail(tmp);
	}

	std::cout << "***** Before the Reverse operation *****" << std::endl;
	ll->PrintResults();
	ll->Reverse();
	std::cout << "***** After the Reverse operation *****" << std::endl;
	ll->PrintResults();

	ll->RemoveAll();
	delete ll;
}

void ReverseS2()
{
	SingleList *ll = new SingleList();
	SingleList::Node *tmp = NULL;

	// Single List
	for (int i = 0; i < 100; i++)
	{
		tmp = new SingleList::Node();
		tmp->value = g_S2[i];
		ll->AddAtTail(tmp);
	}

	std::cout << "***** Before the Reverse operation *****" << std::endl;
	ll->PrintResults();
	ll->Reverse();
	std::cout << "***** After the Reverse operation *****" << std::endl;
	ll->PrintResults();

	ll->RemoveAll();
	delete ll;
}

void ShuffleS1()
{
	SingleList *ll = new SingleList();
	SingleList::Node *tmp = NULL;

	// Single List
	for (int i = 0; i < 100; i++)
	{
		tmp = new SingleList::Node();
		tmp->value = g_S1[i];
		ll->AddAtTail(tmp);
	}

	std::cout << "***** Before the Shuffle operation *****" << std::endl;
	ll->PrintResults();
	ll->Shuffle();
	std::cout << "***** After the Shuffle operation *****" << std::endl;
	ll->PrintResults();

	ll->RemoveAll();
	delete ll;
}

void ShuffleS2()
{
	SingleList *ll = new SingleList();
	SingleList::Node *tmp = NULL;

	// Single List
	for (int i = 0; i < 100; i++)
	{
		tmp = new SingleList::Node();
		tmp->value = g_S2[i];
		ll->AddAtTail(tmp);
	}

	std::cout << "***** Before the Shuffle operation *****" << std::endl;
	ll->PrintResults();
	ll->Shuffle();
	std::cout << "***** After the Shuffle operation *****" << std::endl;
	ll->PrintResults();

	ll->RemoveAll();
	delete ll;
}

int main()
{
	std::cout << "Homework 1: Linked List" << std::endl;

	generateS1();
	generateS2();

	TeamOfFourS2();

	ReverseS1();
	ReverseS2();

	ShuffleS1();
	ShuffleS2();

	std::cout << "Press any key to continue..." << std::endl;
	getchar();
    return 0;
}

