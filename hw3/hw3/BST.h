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
	CNode* getRoot();
	void   inorder(CNode *node);
	int    getHeight(CNode *node);
	CNode* insert(CNode* node, int key);
	CNode* remove(CNode* root, int key);
	void   removeAll(CNode* node);
	void   setRoot(CNode* node);

private:
	CNode *minValueNode(CNode* node);
	CNode *_root;
};

