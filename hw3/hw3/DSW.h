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

	void   BalanceTree(CNode* node);

private:
	void   TreeToVine(CNode* root, int& size);
	void   VineToTree(CNode* root, int size);
	void   Compress(CNode* root, int count);
};

