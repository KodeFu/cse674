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
void CDSW::rotateRight(CNode* gr, CNode* par, CNode* ch)
{
	if (gr->right == par) {
		gr->right = ch;
	}
	else {
		gr->left = ch;
	}

	CNode* ch_right = ch->right;
	par->left = ch_right;
	ch->right = par;
}

// Rotate left
void CDSW::rotateLeft(CNode* gr, CNode* par, CNode* ch)
{
	if (gr->right == par) {
		gr->right = ch;
	}
	else {
		gr->left = ch;
	}

	CNode* ch_left = ch->left;
	par->right = ch_left;
	ch->left = par;
}