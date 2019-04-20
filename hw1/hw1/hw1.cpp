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
	/*
	SingleList *ll = new SingleList();

	SingleList::Node *tmp = new SingleList::Node();
	tmp->value = 1;
	ll->AddAtHead(tmp);

	tmp = new SingleList::Node();
	tmp->value = 2;
	ll->AddAtHead(tmp);

	tmp = new SingleList::Node();
	tmp->value = 3;
	ll->AddAtHead(tmp);

	tmp = new SingleList::Node();
	tmp->value = 77;
	ll->AddAtTail(tmp);

	tmp = new SingleList::Node();
	tmp->value = 99;
	ll->AddAtTail(tmp);

	tmp = new SingleList::Node();
	tmp->value = 4;
	ll->AddAtHead(tmp);

	ll->PrintAll();
	ll->Swap(4, 99);
	ll->PrintAll();
	*/
	/*
	ll->PrintNode(ll->GetAtIndex(1));
	ll->PrintNode(ll->GetAtIndex(3));
	ll->PrintNode(ll->GetAtIndex(0));
	ll->PrintNode(ll->GetAtIndex(10));
	
	std::cout << "---> GetAtHead..." << std::endl;
	ll->PrintNode(ll->GetAtHead());
	std::cout << "---> GetAtTail..." << std::endl;
	ll->PrintNode(ll->GetAtTail());

	ll->RemoveAtHead();
	ll->RemoveAtTail();

	ll->PrintAll();
	std::cout << "final size: " << ll->Size() << std::endl;

	ll->RemoveAll();
	std::cout << "final size: " << ll->Size() << std::endl;

	delete ll;
	*/
	/*
	DoubleList *ll = new DoubleList();

	DoubleList::Node *tmp = new DoubleList::Node();
	tmp->value = 1;
	ll->AddAtHead(tmp);

	tmp = new DoubleList::Node();
	tmp->value = 2;
	ll->AddAtHead(tmp);

	tmp = new DoubleList::Node();
	tmp->value = 3;
	ll->AddAtHead(tmp);

	tmp = new DoubleList::Node();
	tmp->value = 77;
	ll->AddAtTail(tmp);

	tmp = new DoubleList::Node();
	tmp->value = 99;
	ll->AddAtTail(tmp);

	tmp = new DoubleList::Node();
	tmp->value = 4;
	ll->AddAtHead(tmp);

	ll->PrintAll();
	*/
	/*
	ll->PrintNode(ll->GetAtIndex(1));
	ll->PrintNode(ll->GetAtIndex(3));
	ll->PrintNode(ll->GetAtIndex(0));
	ll->PrintNode(ll->GetAtIndex(10));

	std::cout << "---> GetAtHead..." << std::endl;
	ll->PrintNode(ll->GetAtHead());
	std::cout << "---> GetAtTail..." << std::endl;
	ll->PrintNode(ll->GetAtTail());

	ll->RemoveAtHead();
	ll->RemoveAtTail();

	ll->PrintAll();
	std::cout << "final size: " << ll->Size() << std::endl;
	
	ll->RemoveAll();
	std::cout << "final size: " << ll->Size() << std::endl;
	*/
	//delete ll;

	generateS1();
	generateS2();

	getchar();
	return 0;
	

	SingleList *singleList = new SingleList();

	for (int i = 1; i <= 100; i++)
	{
		SingleList::Node *tmp = new SingleList::Node();
		tmp->value = i;
		singleList->AddAtTail(tmp);
	}
	singleList->PrintAll();
	singleList->RemoveAll();
	delete singleList;

	getchar();
    return 0;
}

