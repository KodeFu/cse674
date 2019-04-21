#pragma once

class SingleList
{
public:
	struct Node 
	{
		int value;
		Node *next;
	};

	SingleList();
	~SingleList();

	void AddAtHead(Node *node);
	void AddAtTail(Node *node);
	Node *GetAtHead();
	Node *GetAtTail();
	Node *GetAtIndex(int index);
	void RemoveAtHead();
	void RemoveAtTail();
	void RemoveAll();
	void Swap(int a, int b);
	void Reverse();
	void BubbleSort(int startIndex = 0, int rangeLength = 0);
	void TeamOfFour();
	void Shuffle();
	int Size();

	void PrintNode(Node *node);
	void PrintAll();
	void PrintResults();

private:
	Node *head;
	Node *tail;
	int size;
};
