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
CNode* CDSW::rotateRight(CNode* gr, CNode* par, CNode* ch)
{
	if (gr != NULL) {
		gr->right = ch;
	}
	else {
		this->setRoot(ch);
	}

	CNode* chRight = ch->right;
	par->left = chRight;
	ch->right = par;

	return gr;
}

// Rotate left
void CDSW::rotateLeft(CNode* gr, CNode* par, CNode* ch)
{
	if (gr != NULL) {
		gr->right = ch;
	}
	else {
		setRoot(ch);
	}

	CNode* chLeft = ch->left;
	par->right = chLeft;
	ch->left = par;
}

// Create backbone (ordered linked list)
void CDSW::createBackbone()
{
	CNode* gr = NULL;
	CNode* par = getRoot();
	CNode* chLeft = NULL;

	while (par != NULL) {
		chLeft = par->left;
		if (chLeft != NULL) {
			// Rotate right about parent and it's left child;
			gr = rotateRight(gr, par, chLeft);

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

// Create balanced BST
void CDSW::createPerfectTree()
{
	int nodes = 0;

	createBackbone();

	for (CNode* temp = getRoot(); NULL != temp; temp = temp->right) {
		// count nodes
		nodes++;
	}

	// Make n/2 left rotations starting from the top;
	int m = std::pow(2, (int) (std::log2(nodes+1))) - 1;
	makeRotations(nodes - m);

	while (m > 1) {
		m = m / 2;
		makeRotations(m);
	}
}

// Make rotations; used by balancedBST to rotate back to a tree
void CDSW::makeRotations(int count)
{
	CNode* gr = NULL;
	CNode* par = getRoot();
	CNode* chRight = getRoot()->right;

	while (count > 0) {
		if (chRight == NULL) {
			break;
		}

		// Make n left rotations starting from the top;
		rotateLeft(gr, par, chRight);
		gr = chRight;
		par = gr->right;
		chRight = par->right;

		count--;
	}
}
