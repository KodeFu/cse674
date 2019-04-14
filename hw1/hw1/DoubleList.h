#pragma once

class DoubleList
{
public:
	struct Node 
	{
		int value;
		Node *prev;
		Node *next;
	};

	DoubleList();
	~DoubleList();

	void AddAtHead(Node *node);
	void AddAtTail(Node *node);
	Node *GetAtHead();
	Node *GetAtTail();
	Node *GetAtIndex(int index);
	void RemoveAtHead();
	void RemoveAtTail();
	void RemoveAll();
	int Size();

	void PrintNode(Node *node);
	void PrintAll();

private:
	Node *head;
	Node *tail;
	int size;
};

