#pragma once
#include "Node.h"

class CBST
{
public:
	CBST();
	~CBST();
	void inorder(CNode *node);
	CNode* insert(CNode* node, int key);
	CNode* getRoot();

private:
	CNode *root;
};

