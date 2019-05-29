/*

	File:
		Splay.h

	Purpose:
		Defines the functions which implement a Splay Tree.

	Author:
		mpvats@syr.edu

*/
#pragma once
#include "Node.h"

class CSplay
{
public:
	CSplay();
	~CSplay();
	CNode* GetRoot();
	void   SetRoot(CNode* node);
	void   Display(CNode *node);
	int    Height(CNode *node);
	CNode* Insert(CNode *node, int key);
	CNode* Remove(CNode* node, int key);
	void   RemoveAll(CNode* node);

private:
	CNode* newNode(int key);
	CNode* RotateRight(CNode *node);
	CNode* RotateLeft(CNode *node);
	CNode* Splay(CNode *node, int key);

	CNode* _root;
};

