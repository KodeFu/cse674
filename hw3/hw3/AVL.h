/*

	File:
		AVL.h

	Purpose:
		Defines the functions which implement a AVL Tree.

	Author:
		mpvats@syr.edu

*/
#pragma once
#include "BST.h"
#include "Node.h"

class CAVL : public CBST
{
public:
	CAVL();
	~CAVL();

	int    Height(CNode *node);
	CNode* Insert(CNode* node, int key);
	CNode* Remove(CNode* node, int key);

private:
	CNode* SmallestNode(CNode* node);
	CNode* RotateRight(CNode *node);
	CNode* RotateLeft(CNode *node);
	int    GetBalanceFactor(CNode *node);
};

