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

LinkedList::Node *LinkedList::GetAtHead()
{
	return head;
}

LinkedList::Node *LinkedList::GetAtTail()
{
	return tail;
}

LinkedList::Node *LinkedList::GetAtIndex(int index)
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

void LinkedList::RemoveAtHead()
{
	Node *tmp = head;

	if (head != NULL)
	{
		head = head->next;
		delete tmp;

		size--;
	}
}

void LinkedList::RemoveAtTail()
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
		size--;
	}

	head = NULL;
	tail = NULL;
}

int LinkedList::Size()
{
	return size;
}

void LinkedList::PrintNode(Node *node)
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

void LinkedList::PrintAll()
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