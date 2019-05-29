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
	void   CreatePerfectTree();

private:
	void   CreateBackbone();
	void   MakeRotations(int count);
};

