/*

	File:
		AVL.h

	Purpose:
		Defines the functions which implement a AVL Tree.

	Author:
		mpvats@syr.edu

*/
#pragma once
#include "Node.h"

class CAVL
{
public:
	CAVL();
	~CAVL();

	CNode* GetRoot();
	void      SetRoot(CNode* node);
	void      Display(CNode *node);
	int       Height(CNode *node);
	CNode* Insert(CNode* node, int key);
	CNode* Remove(CNode* node, int key);
	void      RemoveAll(CNode* node);

private:
	CNode* SmallestNode(CNode* node);
	CNode* RotateRight(CNode *node);
	CNode* RotateLeft(CNode *node);
	int       GetBalanceFactor(CNode *node);
	CNode* _root;
};

