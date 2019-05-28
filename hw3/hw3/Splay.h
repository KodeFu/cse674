#pragma once
#include "Node.h"

class CSplay
{
public:
	CSplay();
	~CSplay();
	CNode* newNode(int key);
	CNode* rightRotate(CNode *x);
	CNode* leftRotate(CNode *x);
	CNode* splay(CNode *root, int key);
	CNode* insert(CNode *root, int k);
	CNode* delete_key(CNode* root, int key);
	void preOrder(CNode *root);

	CNode* getRoot();
	void   setRoot(CNode* node);

private:
	CNode* _root;
};

