#include "DatasetParser.h"

DatasetParser::DatasetParser() = default;

DatasetParser::DatasetParser(const std::string& name) : DatasetParser() {
	loadFile(name);
}

void DatasetParser::loadFile(const std::string& name) {
    this->_fileStream = std::ifstream(name, std::ios_base::in);
}

void DatasetParser::loadParametersDefinition() {
    if (!this->_fileStream.is_open()) {
        std::cerr << "File is not opened!" << std::endl;
        throw std::exception();
    }

    this->_fileStream.seekg(0, std::ios_base::beg);
    std::string parametersDefinition;
    std::getline(this->_fileStream, parametersDefinition);
    this->_dataStart = this->_fileStream.tellg();

    this->_parametersDefinition = CSVUtils::parseLineToList(parametersDefinition, ';');
}

void DatasetParser::loadData() {
    if (!this->_fileStream.is_open() || this->_dataStart == -1)
        throw std::exception();

    this->_fileStream.seekg(this->_dataStart, std::ios_base::beg);

    this->_dataset.clear();

    std::string dataString;
    while (std::getline(this->_fileStream, dataString)) {
        std::cout << dataString << std::endl;
        this->_dataset.emplace_back(Data(this->_parametersDefinition, dataString));
    }
}

DatasetParser::~DatasetParser() {
    this->_fileStream.close();
};
