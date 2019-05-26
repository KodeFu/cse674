#pragma once
#include "Node.h"

class CBST
{
public:
	CBST();
	~CBST();
	void inorder(CNode *node);
	CNode* insert(CNode* node, int key);
	CNode* remove(CNode* root, int key);
	CNode* getRoot();

private:
	CNode *minValueNode(CNode* node);
	CNode *root;
};

