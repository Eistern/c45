#ifndef DATASET_PARSER_H
#define DATASET_PARSER_H

#include "CSVUtils.h"
#include "Data.h"

#include <iostream>
#include <fstream>
#include <vector>

class DatasetParser {
private:
	std::ifstream _fileStream;
	std::vector<std::string> _parametersDefinition;
	std::vector<Data> _dataset;
	unsigned int _dataStart = 0;
public:
    DatasetParser();
	explicit DatasetParser(const std::string& name);

	void loadFile(const std::string& name);
	void closeFile();
    void loadParametersDefinition();
    void loadData();

	~DatasetParser();
};

#endif