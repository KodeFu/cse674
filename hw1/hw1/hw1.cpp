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

int main()
{
	std::cout << "Homework 1: Linked List" << std::endl;
	
	SingleList *ll = new SingleList();

	SingleList::Node *tmp = new SingleList::Node();
	tmp->value = 7;
	ll->AddAtHead(tmp);

	tmp = new SingleList::Node();
	tmp->value = 3;
	ll->AddAtTail(tmp);

	tmp = new SingleList::Node();
	tmp->value = 9;
	ll->AddAtTail(tmp);

	tmp = new SingleList::Node();
	tmp->value = 2;
	ll->AddAtTail(tmp);

	tmp = new SingleList::Node();
	tmp->value = 6;
	ll->AddAtTail(tmp);

	tmp = new SingleList::Node();
	tmp->value = 1;
	ll->AddAtTail(tmp);

	tmp = new SingleList::Node();
	tmp->value = 8;
	ll->AddAtTail(tmp);

	tmp = new SingleList::Node();
	tmp->value = 5;
	ll->AddAtTail(tmp);


	ll->PrintAll();
	//ll->RemoveAtTail();
	//ll->PrintAll();

	//ll->BubbleSort(0,4);
	//ll->BubbleSort(4, 4);
	ll->Shuffle();
	ll->PrintAll();

	getchar();

	ll->RemoveAll();
	delete ll;

    return 0;
}

