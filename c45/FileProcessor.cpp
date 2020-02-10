#include "FileProcessor.h"


FileProcessor::FileProcessor(std::string name) {
	this->fileStream = std::ifstream(name, std::ios_base::in);
}


FileProcessor::~FileProcessor() {
}
