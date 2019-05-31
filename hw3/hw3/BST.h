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
	void   RemoveAll(CNode* node);
	
	virtual int    Height(CNode *node);
	virtual CNode* Insert(CNode* node, int key);
	virtual CNode* Remove(CNode* node, int key);

protected:
	CNode* SmallestNode(CNode* node);

private:
	CNode* _root;
};

