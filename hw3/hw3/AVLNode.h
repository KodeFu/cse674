#pragma once
class CAVLNode
{
public:
	CAVLNode();
	~CAVLNode();

	int key;		           // Key
	CAVLNode *left;            // Pointer to left child node
	CAVLNode *right;           // Pointer to right child node
	int height;	               // Tree height from this node down
};

