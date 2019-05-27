#pragma once
class CAVLNode
{
public:
	CAVLNode();
	~CAVLNode();

	int key;		           // key
	CAVLNode *left;            // Pointer to left child node
	CAVLNode *right;           // Pointer to right child node
	int height; 
};

