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

	void rotateRight(CNode* gr, CNode* par, CNode* ch);
	void rotateLeft(CNode* gr, CNode* par, CNode* ch);
};

