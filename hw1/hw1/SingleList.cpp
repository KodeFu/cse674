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
		node->next = NULL;
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
	delete prev->next; // same as tail
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

void SingleList::Swap(int a, int b)
{
	Node *tmp = head;
	Node *prevA = NULL;
	Node *nodeA = head;
	Node *prevB = NULL;
	Node *nodeB = head;

	// search for first node
	while (tmp && (tmp->value != a))
	{
		prevA = tmp;
		tmp = tmp->next;
	}
	nodeA = tmp;

	// search for second node
	tmp = head;
	while (tmp && (tmp->value != b))
	{
		prevB = tmp;
		tmp = tmp->next;
	}
	nodeB = tmp;

	// only swap if both nodes found
	if (nodeA && nodeB)
	{
		// update prev nodes
		(prevA) ? prevA->next = nodeB : head = nodeB;
		(prevB) ? prevB->next = nodeA : head = nodeA;

		// update nodes
		tmp = nodeA->next;
		nodeA->next = nodeB->next;
		nodeB->next = tmp;
	}
}

void SingleList::Reverse()
{
	Node *prev;
	Node *curr;
	Node *next;

	// don't do anything if there are no nodes
	if (!size) return;

	// make head node the last node
	prev = NULL;
	curr = head;
	next = curr->next;

	curr->next = NULL;
	tail = curr;

	// reverse next pointer for every node thereafter
	while (next != NULL)
	{
		prev = curr;
		curr = next;
		next = curr->next;

		curr->next = prev;
	}

	// point the head to the current front node
	head = curr;
}

void SingleList::PrintNode(Node *node)
{
	if (node != NULL)
	{
		std::cout << "  -> 0x" << node << "  0x" << node->next << "  " << node->value << std::endl;
	}
	else
	{
		std::cout << "  -> NULL" << std::endl;
	}
}

void SingleList::PrintAll()
{
	std::cout << "-----------------------------------" << std::endl;
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