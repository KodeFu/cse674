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
			gr = rotateRight(gr, par, chLeft);
			par = chLeft;
		}
		else {
			gr = par;
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
		if (NULL != chRight) {
			rotateLeft(gr, par, chRight);
			gr = chRight;
			par = gr->right;
			chRight = par->right;
		}
		else {
			break;
		}

		count--;
	}
}
