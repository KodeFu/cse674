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

	Node *prev = GetAtIndex(size - 2);
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

		// adjust tail if node points to NULL
		if (nodeA->next == NULL) tail = nodeA;
		if (nodeB->next == NULL) tail = nodeB;
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

void SingleList::BubbleSort(int startIndex, int rangeLength)
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
				Swap(curr->value, next->value);
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

void SingleList::Shuffle()
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

void SingleList::PrintResults()
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << GetAtIndex(i * 4 + j)->value;
			std::cout << ", ";
		}

		std::cout << std::endl;
	}
}