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
		node->prev = NULL;
	}
	else
	{
		node->next = head;
		node->next->prev = node;
		node->prev = NULL;
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
		node->prev = NULL;
	}
	else
	{
		tail->next = node;
		node->next = NULL;
		node->prev = tail;
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

	if ((index < 0) || (index >= size))
	{
		return NULL;
	}

	while (tmp != NULL)
	{	
		if (current == index)
		{
			return tmp;
		}

		tmp = tmp->next;
		current++;
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
	head->prev = NULL;
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

	Node *prev = tail->prev;
	delete prev->next; // same as tail
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
		delete tmp;

		tmp = next;
		size--;
	}

	head = NULL;
	tail = NULL;
}

void DoubleList::Swap(Node *left)
{
	Node *nodeA = left;
	Node *nodeB = left->next;

	if (nodeA && nodeB)
	{
		if (nodeA->prev)
		{
			nodeA->prev->next = nodeB;
		}
		else
		{
			head = nodeB;
		}

		if (nodeB->next)
		{
			nodeB->next->prev = nodeA;
		}

		nodeA->next = nodeB->next;
		nodeB->prev = nodeA->prev;
		nodeB->next = nodeA;
		nodeA->prev = nodeB;
	}
}

void DoubleList::Reverse()
{
	Node *curr;
	Node *next;

	// start from the tail
	curr = tail;

	// get next node; work with this after curr
	next = curr->prev;

	// adjust the node's pointers
	curr->prev = NULL; // head
	curr->next = next;

	while (next != NULL)
	{
		curr = next;

		next = curr->prev;
		curr->prev = curr->next;
		curr->next = next;
	}

	// swap head and tail
	Node *tmp = head;
	head = tail;
	tail = tmp;
}

void DoubleList::BubbleSort(int startIndex, int rangeLength)
{
	bool swapped = true;
	Node *curr = NULL;
	Node *next = NULL;
	int range = 0;

	if ((startIndex < 0) || (startIndex >= size))
	{
		return;
	}

	if (startIndex + rangeLength > size)
	{
		return;
	}

	while (swapped)
	{
		swapped = false;
		(!startIndex) ? curr = head : curr = GetAtIndex(startIndex);
		(!rangeLength) ? range = size : range = startIndex + rangeLength;

		Node *next = curr->next;
		for (int i = startIndex; i < range - 1; i++)
		{
			if (curr->value > next->value)
			{
				Swap(curr);
				swapped = true;

				// if we did swap, curr stays the same since it
				// swapped with next
			}
			else
			{
				// if we didn't swap, curr advances to next
				curr = next;
			}

			if (curr->next != NULL)
			{
				next = curr->next;
			}
			else
			{
				break;
			}
		}
	}
}

void DoubleList::TeamOfFour()
{
	for (int i = 0; i < size; i += 4)
	{
		BubbleSort(i, 4);
	}
}

void DoubleList::Shuffle()
{
	int halfDeck = size / 2;

	Node *leftCurr = head;
	Node *leftNext = NULL;

	Node *rightCurr = GetAtIndex(halfDeck);
	Node *rightNext = NULL;

	for (int i = 0; i < halfDeck; i++)
	{
		leftNext = leftCurr->next;
		leftCurr->next = rightCurr;

		rightNext = rightCurr->next;
		if (rightNext == NULL)
		{
			// end of right half of deck
			break;
		}

		rightCurr->next = leftNext;

		leftCurr = leftNext;
		rightCurr = rightNext;
		rightNext = rightCurr->next;
	}
}


int DoubleList::Size()
{
	return size;
}

void DoubleList::PrintNode(Node *node)
{
	if (node != NULL)
	{
		std::cout << "  -> 0x" << node << "  0x" << node->prev << "  0x" << node->next << "  " << node->value << std::endl;
	}
	else
	{
		std::cout << "  -> NULL" << std::endl;
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

void DoubleList::PrintResults()
{
	for (int i = 0; i < size / 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << GetAtIndex(i * 4 + j)->value;
			std::cout << ", ";
		}

		std::cout << std::endl;
	}
}