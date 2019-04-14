#pragma once

class LinkedList
{
public:
	struct Node 
	{
		int value;
		Node *next;
	};

	LinkedList();
	~LinkedList();

	void AddAtHead(Node *node);
	void AddAtTail(Node *node);
	Node *Get(int index);
	Node *RemoveAtHead();
	Node *RemoveAtTail();
	void RemoveAll();
	int Size();

	void PrintAll();

private:
	Node *head;
	Node *tail;
	int size;
};

