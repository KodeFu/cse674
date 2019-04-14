// hw1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LinkedList.h"

int main()
{
	std::cout << "Homework 1: Linked List" << std::endl;

	LinkedList *ll = new LinkedList();

	LinkedList::Node *tmp = new LinkedList::Node();
	tmp->value = 1;
	ll->AddAtHead(tmp);

	tmp = new LinkedList::Node();
	tmp->value = 2;
	ll->AddAtHead(tmp);

	tmp = new LinkedList::Node();
	tmp->value = 3;
	ll->AddAtHead(tmp);

	tmp = new LinkedList::Node();
	tmp->value = 77;
	ll->AddAtTail(tmp);

	tmp = new LinkedList::Node();
	tmp->value = 99;
	ll->AddAtTail(tmp);

	tmp = new LinkedList::Node();
	tmp->value = 4;
	ll->AddAtHead(tmp);

	ll->PrintAll();

	delete ll;

    return 0;
}

