#include "stdafx.h"
#include "LinkedList.h"


LinkedList::LinkedList()
{
	size = 0;
	head = NULL;
	tail = NULL;
}


LinkedList::~LinkedList()
{
	RemoveAll();
}

void LinkedList::AddAtHead(LinkedList::Node *node)
{
	if (head == NULL) // empty list
	{
		head = node;
		tail = node;
		node->next = NULL;
	}
	else
	{
		node->next = head;
		head = node;
	}

	size++;
}

void LinkedList::AddAtTail(LinkedList::Node *node)
{
	if (head == NULL) // empty list
	{
		head = node;
		tail = node;
		node->next = NULL;
	}
	else
	{
		tail->next = node;
		tail = node;
	}

	size++;
}

LinkedList::Node *LinkedList::Get(int index)
{
	return NULL;
}

LinkedList::Node *LinkedList::RemoveAtHead()
{
	return NULL;
}

LinkedList::Node *LinkedList::RemoveAtTail()
{
	return NULL;
}

void LinkedList::RemoveAll()
{
	Node *tmp = head;
	Node *next = NULL;

	while (tmp != NULL)
	{
		Node *next = tmp->next;
		std::cout << "deleting node: " << tmp << std::endl;
		delete tmp;

		tmp = next;
	}
}

int LinkedList::Size()
{
	return size;
}

void LinkedList::PrintAll()
{
	std::cout << "size: " << size << std::endl;
	std::cout << "head: " << head << std::endl;
	std::cout << "tail: " << tail << std::endl;

	Node *tmp = head;
	while (tmp != NULL)
	{
		std::cout << "node: " << &tmp << " " << tmp << std::endl;
		std::cout << tmp->value << std::endl;
		std::cout << tmp->next << std::endl;
		tmp = tmp->next;
	}
}