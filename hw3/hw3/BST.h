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

	void   Display(CNode *node);
	void   RemoveAll(CNode* node);

	virtual int   Height(CNode *node);
	virtual void  Insert(CNode*& node, int key);
	virtual void  Remove(CNode*& node, int key);

	CNode* _root;

protected:
	virtual CNode* SmallestNode(CNode* node);
	virtual CNode* RotateRight(CNode* node, bool updateHeight=false);
	virtual CNode* RotateLeft(CNode* node, bool updateHeight=false);

};

