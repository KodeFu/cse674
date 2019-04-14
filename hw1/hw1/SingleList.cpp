#include "stdafx.h"
#include "SingleList.h"


SingleList::SingleList()
{
	size = 0;
	head = NULL;
	tail = NULL;
}


SingleList::~SingleList()
{
	RemoveAll();
}

void SingleList::AddAtHead(SingleList::Node *node)
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

void SingleList::AddAtTail(SingleList::Node *node)
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

SingleList::Node *SingleList::GetAtHead()
{
	return head;
}

SingleList::Node *SingleList::GetAtTail()
{
	return tail;
}

SingleList::Node *SingleList::GetAtIndex(int index)
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

void SingleList::RemoveAtHead()
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

void SingleList::RemoveAtTail()
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

void SingleList::RemoveAll()
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

int SingleList::Size()
{
	return size;
}

void SingleList::PrintNode(Node *node)
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

void SingleList::PrintAll()
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