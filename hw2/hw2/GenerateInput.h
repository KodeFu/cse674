/*

	File:
		GenerateInput.h

	Purpose:
		Class definition for the generating input data.

	Author:
		mpvats@syr.edu

*/
#pragma once

class CGenerateInput
{
public:
	CGenerateInput();
	~CGenerateInput();

	int getMaxRange();
	void setMaxRange(int value);

	void generateInputFiles();

	void generateRandom(std::vector<int>& data);
	void generateAscending(std::vector<int>& data);
	void generateDescending(std::vector<int>& data);

	void getAscending(std::vector<int>& data, int maxElements);
	void getDescending(std::vector<int>& data, int maxElements);
	void getRandom(std::vector<int>& data, int maxElements);

	void writeFile(std::vector<int> data, std::string filename);
	void readFile(std::vector<int>& data, std::string filename, int maxElements);

private:
	int  max_range;
};

