/*

	File:
		SingleList.h

	Purpose:
		Defines the SingleList class which contains the node definition and operations for
		the single-linked list.

	Author:
		mpvats@syr.edu

*/

#pragma once

class SingleList
{
public:
	struct Node 
	{
		int value;                // Value / key
		Node *next;               // Pointer to next node
	};

	SingleList();                 // Constructor
	~SingleList();                // Destructor

	void AddAtHead(Node *node);   // Adds a node to the HEAD
	void AddAtTail(Node *node);   // Adds a node to the TAIL
	Node *GetAtHead();            // Get the node at HEAD
	Node *GetAtTail();            // Get the node at TAIL
	Node *GetAtIndex(int index);  // Get the node for a node value
	void RemoveAtHead();          // Remove node at HEAD
	void RemoveAtTail();          // Remove node at TAIL
	void RemoveAll();             // Remove (deallocate) all nodes
	void Swap(Node *left);        // Swap adjacent nodes
	void BubbleSort(              // Bubble sort algorithm, to sort at a starting index 
		int startIndex = 0,       // for a specfified range 
		int rangeLength = 0);
	int  Size();                  // Get number of nodes in list

	void TeamOfFour();            // Perform TeamOfFour operation
	void Reverse();               // Print all nodes
	void Shuffle();               // Print results per lab requirement

	void PrintNode(Node *node);
	void PrintAll();
	void PrintResults();

private:
	Node *head;                   // HEAD pointer
	Node *tail;                   // TAIL pointer
	int size;                     // List size
};
