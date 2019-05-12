/*

	File:
		SmoothSort.h

	Purpose:
		Class definition for the SmoothSort algorithm.

	Author:
		mpvats@syr.edu

*/
#pragma once
#include "SortInterface.h"

class CSmoothSort :
	public ISortInterface
{
public:
	CSmoothSort();
	~CSmoothSort();
	void sort(std::vector<int>& vector);
	std::string identify();

private:
	void sift(std::vector<int>& A);
	void trinkle(std::vector<int>& A);
	void semiTrinkle(std::vector<int>& A);

	int q, r, p, b, c, r1, b1, c1;
};

