#pragma once

#include "stdafx.h"

struct ISortInterface { 
	ISortInterface() {} 
	virtual ~ISortInterface() {}
	virtual void sort(std::vector<int>& vector) = 0; 
};
