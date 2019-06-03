/*

	File:
		Splay.h

	Purpose:
		Defines the functions which implement a Splay Tree.

	Author:
		mpvats@syr.edu

*/
#pragma once
#include "BST.h"
#include "Node.h"

class CSplay : public CBST
{
public:
	CSplay();
	~CSplay();

	CNode* Search(CNode* root, int key);
	void   Insert(CNode*& node, int key);
	void   Remove(CNode*& node, int key);

private:
	void   Splay(CNode*& node, int key);
};

