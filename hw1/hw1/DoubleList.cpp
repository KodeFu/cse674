#include "stdafx.h"
#include "DoubleList.h"


DoubleList::DoubleList()
{
	size = 0;
	head = NULL;
	tail = NULL;
}


DoubleList::~DoubleList()
{
	RemoveAll();
}

void DoubleList::AddAtHead(DoubleList::Node *node)
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

void DoubleList::AddAtTail(DoubleList::Node *node)
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

DoubleList::Node *DoubleList::GetAtHead()
{
	return head;
}

DoubleList::Node *DoubleList::GetAtTail()
{
	return tail;
}

DoubleList::Node *DoubleList::GetAtIndex(int index)
{
	Node *tmp = head;
	int current = 0;

	if ((index < 1) || (index > size))
	{
		return NULL;
	}

	while (tmp != NULL)
	{
		current++;
		
		if (current == index)
		{
			return tmp;
		}

		tmp = tmp->next;
	}

	return NULL;
}

void DoubleList::RemoveAtHead()
{
	if (size == 0) return;
	if (size == 1)
	{
		delete head;
		head = NULL;
		tail = NULL;
		size = 0;
		return;
	}

	Node *tmp = head;
	head = head->next;
	delete tmp;

	size--;
}

void DoubleList::RemoveAtTail()
{
	if (size == 0) return;
	if (size == 1) 
	{
		delete head;
		head = NULL;
		tail = NULL;
		size = 0;
		return;
	}

	Node *prev = GetAtIndex(size - 1);
	delete prev->next;
	prev->next = NULL;
	tail = prev;

	size--;
}

void DoubleList::RemoveAll()
{
	Node *tmp = head;
	Node *next = NULL;

	while (tmp != NULL)
	{
		Node *next = tmp->next;
		std::cout << "deleting node: " << tmp << std::endl;
		delete tmp;

		tmp = next;
		size--;
	}

	head = NULL;
	tail = NULL;
}

int DoubleList::Size()
{
	return size;
}

void DoubleList::PrintNode(Node *node)
{
	if (node != NULL)
	{
		std::cout << "node: " << &node << " " << node << std::endl;
		std::cout << node->value << std::endl;
		std::cout << node->next << std::endl;
	}
	else
	{
		std::cout << "node: NULL" << std::endl;
	}
}

void DoubleList::PrintAll()
{
	std::cout << "size: " << size << std::endl;
	std::cout << "head: " << head << std::endl;
	std::cout << "tail: " << tail << std::endl;

	Node *tmp = head;
	while (tmp != NULL)
	{
		PrintNode(tmp);
		tmp = tmp->next;
	}
}