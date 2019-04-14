// hw1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SingleList.h"
#include "DoubleList.h"

int main()
{
	std::cout << "Homework 1: Linked List" << std::endl;

	SingleList *ll = new SingleList();

	SingleList::Node *tmp = new SingleList::Node();
	tmp->value = 1;
	ll->AddAtHead(tmp);

	tmp = new SingleList::Node();
	tmp->value = 2;
	ll->AddAtHead(tmp);

	tmp = new SingleList::Node();
	tmp->value = 3;
	//ll->AddAtHead(tmp);

	tmp = new SingleList::Node();
	tmp->value = 77;
	//ll->AddAtTail(tmp);

	tmp = new SingleList::Node();
	tmp->value = 99;
	//ll->AddAtTail(tmp);

	tmp = new SingleList::Node();
	tmp->value = 4;
	//ll->AddAtHead(tmp);

	ll->PrintAll();

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

    return 0;
}

