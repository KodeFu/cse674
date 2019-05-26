/*

	File:
		BST.h

	Purpose:
		Defines the functions which implement a BST.

	Author:
		mpvats@syr.edu

*/
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
	void removeAll(CNode* node);
	CNode* getRoot();

private:
	CNode *minValueNode(CNode* node);
	CNode *_root;
};

