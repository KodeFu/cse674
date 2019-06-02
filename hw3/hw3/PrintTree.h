/*

	File:
		PrintTree.h

	Purpose:
		Defines the functions to visually display a BST. There are two implementation here
		which are controlled by ifdefs at compile time. Both here since I liked them both
		and wasn't sure which one to ultimately use.

	Code adapted from:
	https://stackoverflow.com/questions/801740/c-how-to-draw-a-binary-tree-to-the-console
	https://rosettacode.org/wiki/AVL_tree/C

	Author:
		Adrian Schneider
		Rosetta Code
		mpvats@syr.edu

	Changelog:
	   - Updated to support CNode
	   - Updated formatting
	   - Use as static functions

*/
#pragma once
#include "Node.h"

class CPrintTree
{
public:
	CPrintTree();
	~CPrintTree();

#if false
	static void printBT(const std::string& prefix, const CNode* node, bool isLeft);
	static void printBT(const CNode* node);
#else
	struct trunk {
		struct trunk *prev;
		char * str;
	};
	static void show_trunks(struct trunk *p);
	static void show_tree(const CNode *root, struct trunk *prev, int is_left);
	static void printBT(const CNode* node);
#endif
};

