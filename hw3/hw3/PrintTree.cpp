/*

	File:
		PrintTree.cpp

	Purpose:
		Defines the functions to visually display a BST.

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
#include "stdafx.h"
#include "PrintTree.h"


CPrintTree::CPrintTree()
{
}


CPrintTree::~CPrintTree()
{
}

#if false
// 
// https://stackoverflow.com/questions/801740/c-how-to-draw-a-binary-tree-to-the-console
//
void CPrintTree::printBT(const std::string& prefix, const CNode* node, bool isLeft)
{
	if (node != nullptr)
	{
		std::cout << prefix;

		std::cout << (isLeft ? "|--" : "|--");

		// print the value of the node
		std::cout << node->key << std::endl;

		// enter the next tree level - left and right branch
		printBT(prefix + (isLeft ? "|   " : "    "), node->left, true);
		printBT(prefix + (isLeft ? "|   " : "    "), node->right, false);
	}
}

void CPrintTree::printBT(const CNode* node)
{
	printBT("", node, false);
}

#else
//
// aux display and verification routines, helpful but not essential 
// https://rosettacode.org/wiki/AVL_tree/C
//
void CPrintTree::show_trunks(struct trunk *p)
{
	if (!p) return;
	show_trunks(p->prev);
	printf("%s", p->str);
}

void CPrintTree::show_tree(const CNode *root, struct trunk *prev, int is_left)
{
	if (root == NULL) return;
 
	struct trunk this_disp = { prev, "    " };
	char *prev_str = this_disp.str;
	show_tree(root->left, &this_disp, 1);
 
	if (!prev)
		this_disp.str = "---";
	else if (is_left) {
		this_disp.str = ".--";
		prev_str = "   |";
	} else {
		this_disp.str = "`--";
		prev->str = prev_str;
	}
 
	show_trunks(&this_disp);
	printf("%d\n", root->key);
 
	if (prev) prev->str = prev_str;
	this_disp.str = "   |";
 
	show_tree(root->right, &this_disp, 0);
	if (!prev) puts("");
}

void CPrintTree::printBT(const CNode* node)
{
	show_tree(node, 0, 0);
}
#endif