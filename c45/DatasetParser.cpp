#include "DatasetParser.h"

DatasetParser::DatasetParser() = default;

DatasetParser::DatasetParser(const std::string& name) {
	loadFile(name);
}

void DatasetParser::loadFile(const std::string& name) {
    this->_fileStream = std::ifstream(name, std::ios_base::in);
}

void DatasetParser::loadParametersDefinition() {
    this->_fileStream.seekg(std::ios_base::beg);

}

DatasetParser::~DatasetParser() = default;
