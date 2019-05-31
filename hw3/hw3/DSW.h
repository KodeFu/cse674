/*

	File:
		DSW.h

	Purpose:
		Defines the functions which implement a DSW. This class inherits from BST.

	Author:
		mpvats@syr.edu

*/
#pragma once
#include "BST.h"

class CDSW : public CBST
{
public:
	CDSW();
	~CDSW();

	CNode* RotateRight(CNode* gr, CNode* par, CNode* ch);
	void   RotateLeft(CNode* gr, CNode* par, CNode* ch);
	void   BalanceTree(CNode* node);

private:
	void   TreeToVine(CNode* root);
	void   VineToTree(CNode* root);
	void   Compress(CNode* root, int count);

	// Deprecate
	void   CreatePerfectTree();
	void   CreateBackbone();
	void   MakeRotations(int count);
};

