#pragma once

#include "stdafx.h"

struct ISortInterface { 
	ISortInterface() {} 
	virtual ~ISortInterface() {}
	virtual void sort(std::vector<int>& vector) = 0; 
	virtual std::string identify() { return ""; };
	void display(std::vector<int>& vector) { for (unsigned int i = 0; i < vector.size(); i++) { std::cout << i << " " << vector[i] << std::endl; } };
};
