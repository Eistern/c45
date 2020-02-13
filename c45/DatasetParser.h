#pragma once
#include <iostream>
#include <fstream>

class DatasetParser {
private:
	std::ifstream _fileStream;
	int _dataStart = -1;
public:
    DatasetParser();
	explicit DatasetParser(const std::string& name);

	void loadFile(const std::string& name);
    void loadParametersDefinition();

	~DatasetParser();
};

