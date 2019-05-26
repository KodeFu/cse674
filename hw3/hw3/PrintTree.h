/*

	File:
		PrintTree.h

	Purpose:
		Defines the functions to visually display a BST.
	
	Code adapted from:
	https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c

	Author:
	    Adrian Schneider
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

	static void printBT(const std::string& prefix, const CNode* node, bool isLeft);
	static void printBT(const CNode* node);
};

