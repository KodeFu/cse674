/*

	File:
		AVL.h

	Purpose:
		Defines the functions which implement a AVL Tree.

	Author:
		mpvats@syr.edu

*/
#pragma once
#include "AVLNode.h"

class CAVL
{
public:
	CAVL();
	~CAVL();

	CAVLNode* GetRoot();
	void      SetRoot(CAVLNode* node);
	void      Display(CAVLNode *node);
	int       Height(CAVLNode *node);
	CAVLNode* Insert(CAVLNode* node, int key);
	CAVLNode* Remove(CAVLNode* node, int key);
	void      RemoveAll(CAVLNode* node);

private:
	CAVLNode* SmallestNode(CAVLNode* node);
	CAVLNode* RotateRight(CAVLNode *node);
	CAVLNode* RotateLeft(CAVLNode *node);
	int       GetBalanceFactor(CAVLNode *node);
	CAVLNode* _root;
};

