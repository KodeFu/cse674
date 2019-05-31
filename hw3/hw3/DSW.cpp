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

// Rotate right
CNode* CDSW::RotateRight(CNode* gr, CNode* par, CNode* ch)
{
	if (gr != NULL) {
		gr->right = ch;
	}
	else {
		this->SetRoot(ch);
	}

	CNode* chRight = ch->right;
	par->left = chRight;
	ch->right = par;

	return gr;
}

// Rotate left
void CDSW::RotateLeft(CNode* gr, CNode* par, CNode* ch)
{
	if (gr != NULL) {
		gr->right = ch;
	}
	else {
		SetRoot(ch);
	}

	CNode* chLeft = ch->left;
	par->right = chLeft;
	ch->left = par;
}

// Create backbone (ordered linked list)
void CDSW::CreateBackbone()
{
	CNode* gr = NULL;
	CNode* par = GetRoot();
	CNode* chLeft = NULL;

	while (par != NULL) {
		chLeft = par->left;
		if (chLeft != NULL) {
			// Rotate right about parent and it's left child;
			gr = RotateRight(gr, par, chLeft);

			// Set parent to the left child that just became the parent
			par = chLeft;
		}
		else {
			// set grandparent to parent
			gr = par;

			// set parent to the right child
			par = par->right;
		}
	}
}


// Create backbone (ordered linked list)
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

// Create tree from vine (ordered linked list)
void CDSW::VineToTree(CNode* root, int size)
{
	int leaves = size + 1 - std::pow(2, (int)(std::log2(size + 1)));
	Compress(root, leaves);
	size = size - leaves;
	
	while (size > 1) {
		Compress(root, floor(size / 2.0));
		size = floor(size / 2.0);
	}
}

void CDSW::Compress(CNode* root, int count)
{
	CNode* scanner = root;

	for (int i = 0; i < count; i++) {
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

// Create balanced BST
void CDSW::CreatePerfectTree()
{
	int nodes = 0;

	CreateBackbone();

	for (CNode* temp = GetRoot(); NULL != temp; temp = temp->right) {
		// count nodes
		nodes++;
	}

	// Make n/2 left rotations starting from the top;
	int m = std::pow(2, (int) (std::log2(nodes+1))) - 1;
	MakeRotations(nodes - m);

	while (m > 1) {
		m = m / 2;
		MakeRotations(m);
	}
}

// Make rotations; used by balancedBST to rotate back to a tree
void CDSW::MakeRotations(int count)
{
	CNode* gr = NULL;
	CNode* par = GetRoot();
	CNode* chRight = GetRoot()->right;

	while (count > 0) {
		if (chRight == NULL) {
			break;
		}

		// Make n left rotations starting from the top;
		RotateLeft(gr, par, chRight);
		gr = chRight;
		par = gr->right;
		chRight = par->right;

		count--;
	}
}
