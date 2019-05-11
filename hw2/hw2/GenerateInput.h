#pragma once
class CGenerateInput
{
public:
	CGenerateInput();
	~CGenerateInput();
	int getMaxRange();
	void setMaxRange(int value);

	void generateRandom(std::vector<int>& data);
	void generateAscending(std::vector<int>& data);
	void generateDescending(std::vector<int>& data);

	void writeFile(std::vector<int> data, std::string filename);
	void readFile(std::vector<int>& data, std::string filename);
private:
	int  max_range;
};

