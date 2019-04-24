/*

	File:
		SingleList.cpp

	Purpose:
		Defines the SingleList class which contains the node implementation and operations for
		the single-linked list.

	Author:
		mpvats@syr.edu

*/

#include "stdafx.h"
#include "SingleList.h"

//#define VERBOSE 1 // uncomment to print pointer information

//
// Constructor
//
// Initialize members
//
SingleList::SingleList()
{
	size = 0;
	head = NULL;
	tail = NULL;
}

//
// Destructor
//
// Destroy / cleanup object on destruction
//
SingleList::~SingleList()
{
	RemoveAll();
}

//
// AddAtHead
//
// Adds a node to the HEAD
//
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

//
// AddAtTail
//
// Adds a node to the TAIL
//
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

//
// GetAtHead
//
// Get the node at HEAD
//
SingleList::Node *SingleList::GetAtHead()
{
	return head;
}

//
// GetAtTail
//
// Get the node at TAIL
//
SingleList::Node *SingleList::GetAtTail()
{
	return tail;
}

//
// GetAtIndex
//
// Get the node for a node value
//
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

//
// RemoveAtHead
//
// Remove node at HEAD
//
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

//
// RemoveAtTail
//
// Remove node at TAIL
//
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

//
// RemoveAll
//
// Remove (deallocate) all nodes
//
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

//
// Size
//
// Get number of nodes in list
//
int SingleList::Size()
{
	return size;
}

//
// Swap
//
// Swap adjacent nodes
//
void SingleList::Swap(Node *left)
{
	Node *prev = NULL;

	// search for previous node
	Node *tmp = head;
	while (tmp && (tmp != left))
	{
		prev = tmp;
		tmp = tmp->next;
	}

	Node *nodeA = left;
	Node *nodeB = left->next;

	if (nodeA && nodeB)
	{
		if (prev)
		{
			prev->next = nodeB;
		}
		else
		{
			head = nodeB;
		}

		nodeA->next = nodeB->next;
		nodeB->next = nodeA;

		// adjust tail if node points to NULL
		if (nodeA->next == NULL) tail = nodeA;
		if (nodeB->next == NULL) tail = nodeB;
	}
}

//
// Reverse
//
// Perform Reverse operation
//
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

//
// BubbleSort
//
// Bubble sort algorithm, to sort at a starting index
// for a specfified range
//
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

//
// TeamOfFour
//
// Perform TeamOfFour operation
//
void SingleList::TeamOfFour()
{
	for (int i = 0; i < size; i+=4)
	{
		BubbleSort(i, 4);
	}
}

//
// Shuffle
//
// Perform Shuffle operation
//
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

//
// PrintNode
//
// Print a node
//
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

//
// PrintAll
//
// Print all nodes
//
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

//
// PrintResults
//
// Print results per lab requirement
//
void SingleList::PrintResults()
{
	for (int i = 0; i < size/4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << GetAtIndex(i * 4 + j)->value;
			std::cout << ", ";
		}

		std::cout << std::endl;
	}
#ifdef VERBOSE
	PrintAll();
#endif
}