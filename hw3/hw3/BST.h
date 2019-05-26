#pragma once
#include "Node.h"

class CBST
{
public:
	CNode *root;

	CBST();
	~CBST();
	void inorder(CNode *node);
	CNode* insert(CNode* node, int key);

};

