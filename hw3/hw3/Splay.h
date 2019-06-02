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

	CNode* CSplay::Search(CNode* root, int key);
	CNode* Insert(CNode* node, int key);
	CNode* Remove(CNode* node, int key);

private:
	CNode* newNode(int key);
	CNode* Splay(CNode* node, int key);
};

