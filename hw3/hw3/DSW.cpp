/*

	File:
		DSW.cpp

	Purpose:
		Defines the functions which implement a DSW. This class inherits from BST.

	Author:
		mpvats@syr.edu

*/
#include "stdafx.h"
#include "DSW.h"


CDSW::CDSW()
{
}


CDSW::~CDSW()
{
}

// Create vine (linked list)
void CDSW::TreeToVine(CNode* root, int& size)
{
	CNode* tail = root;
	CNode* rest = tail->right;

	size = 0;

	while (rest != NULL) {
		if (rest->left == NULL) {
			// No left, so advance the vine
			tail = rest;
			rest = rest->right;

			// Per DSW paper, we get size here so we don't have
			// to traverse list again to get size for VineToTree()
			size++;
		}
		else {
			// Rotate right
			CNode* temp = rest->left;
			rest->left = temp->right;
			temp->right = rest;

			// Update vine pointers
			rest = temp;
			tail->right = temp;
		}
	}

	std::cout << "size: " << size << std::endl;
}

// Create tree from vine (linked list)
void CDSW::VineToTree(CNode* root, int size)
{
	int leaves = size + 1 - ( (int) std::pow(2, (int)(std::log2(size + 1))) );
	Compress(root, leaves);
	size = size - leaves;
	
	while (size > 1) {
		Compress(root, (int) floor(size / 2.0));
		size = (int) floor(size / 2.0);
	}
}

// Compress
void CDSW::Compress(CNode* root, int count)
{
	CNode* scanner = root;

	for (int i = 0; i < count; i++) {
		// Left rotate
		CNode* child = scanner->right;
		scanner->right = child->right;
		scanner = scanner->right;
		child->right = scanner->left;
		scanner->left = child;
	}
}

// Balance the tree
void CDSW::BalanceTree(CNode* node)
{
	int size;

	// Allocate "pseudo-root" and set right child to point to root
	CNode* pseudoNode = new CNode();
	pseudoNode->right = GetRoot();
	pseudoNode->left = NULL;
	SetRoot(pseudoNode);

	// Create the backbone
	TreeToVine(pseudoNode, size);

	// Create tree from backbone
	VineToTree(pseudoNode, size);

	// Revert root
	SetRoot(GetRoot()->right);
}
