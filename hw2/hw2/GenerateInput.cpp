#include "stdafx.h"
#include "GenerateInput.h"


CGenerateInput::CGenerateInput()
{
	max_range = 1000000;
}


CGenerateInput::~CGenerateInput()
{
}

int CGenerateInput::getMaxRange()
{
	return max_range;
}

void CGenerateInput::setMaxRange(int value)
{
	max_range = value;
}


void CGenerateInput::generateRandom(std::vector<int>& data)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < max_range; i++) {
		data.push_back(((rand() << 15) | rand()) % max_range + 1);
	}
}

void CGenerateInput::generateAscending(std::vector<int>& data)
{
	for (int i = 1; i <= max_range; i++) {
		data.push_back(i);
	}
}

void CGenerateInput::generateDescending(std::vector<int>& data)
{
	for (int i = max_range; i >= 1; i--) {
		data.push_back(i);
	}
}

void CGenerateInput::writeFile(std::vector<int> data, std::string filename)
{
	std::ofstream f;
	f.open(filename);
	for (int i = 0; i < ((int)data.size()); i += 10)
	{
		f << data[i + 0] << "-";
		f << data[i + 1] << "-";
		f << data[i + 2] << "-";
		f << data[i + 3] << "-";
		f << data[i + 4] << "-";
		f << data[i + 5] << "-";
		f << data[i + 6] << "-";
		f << data[i + 7] << "-";
		f << data[i + 8] << "-";
		f << data[i + 9];

		if (i + 10 < ((int) data.size())) {
			f << std::endl;
		}
	}
	f.close();
}

void CGenerateInput::readFile(std::vector<int>& data, std::string filename, int maxElements)
{
	int i = 0;
	std::string line;

	data.clear();

	std::ifstream f(filename);
	if (f.is_open()) {
		while (std::getline(f, line))
		{
			std::stringstream lineStream(line);
			std::string segment;
			while (std::getline(lineStream, segment, '-')) {
				data.push_back(std::stoi(segment));
			}

			if (((int) data.size()) >= maxElements) {
				break;
			}
		}

		f.close();
	}
}

void CGenerateInput::generateInputFiles()
{
	// generate random
	std::vector<int> random;
	generateRandom(random);
	writeFile(random, "random.txt");

	// generate ascending
	std::vector<int> ascending;
	generateAscending(ascending);
	writeFile(ascending, "ascending.txt");

	// generate descending
	std::vector<int> descending;
	generateDescending(descending);
	writeFile(descending, "descending.txt");
}

void CGenerateInput::getAscending(std::vector<int>& data, int maxElements)
{
	readFile(data, "ascending.txt", maxElements);
}

void CGenerateInput::getDescending(std::vector<int>& data, int maxElements)
{
	readFile(data, "descending.txt", maxElements);
}

void CGenerateInput::getRandom(std::vector<int>& data, int maxElements)
{
	readFile(data, "random.txt", maxElements);
}
