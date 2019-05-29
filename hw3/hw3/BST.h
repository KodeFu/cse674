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
	CNode* GetRoot();
	void   SetRoot(CNode* node);
	void   Display(CNode *node);
	int    Height(CNode *node);
	CNode* Insert(CNode* node, int key);
	CNode* Remove(CNode* node, int key);
	void   RemoveAll(CNode* node);

private:
	CNode* SmallestNode(CNode* node);

	CNode* _root;
};

