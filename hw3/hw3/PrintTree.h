/*

	File:
		PrintTree.h

	Purpose:
		Defines the functions to visually display a BST.
	
	Code adapted from:
	https://stackoverflow.com/questions/801740/c-how-to-draw-a-binary-tree-to-the-console

	Author:
	    user1571409
		mpvats@syr.edu

	Changelog:
	   - Updated to support CNode
	   - Updated formatting

*/
#pragma once
#include "Node.h"

class CPrintTree
{
public:
	CPrintTree();
	~CPrintTree();

	static int _print_t(CNode *tree, int is_left, int offset, int depth, char s[20][255]);
	static void print_t(CNode *tree);
};

