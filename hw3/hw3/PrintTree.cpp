/*

	File:
		PrintTree.cpp

	Purpose:
		Defines the functions to visually display a BST.

	Code adapted from:
	https://stackoverflow.com/questions/801740/c-how-to-draw-a-binary-tree-to-the-console

	Author:
		Adrian Schneider
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
