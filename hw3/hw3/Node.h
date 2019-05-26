#pragma once
class CNode
{
public:
	CNode();
	~CNode();

	int key;                // key
	CNode *left;            // Pointer to left child node
	CNode *right;           // Pointer to right child node
};

