#pragma once
#include <iostream>
#include <fstream>

class FileProcessor {
private:
	std::ifstream fileStream;
public:
	FileProcessor(std::string name);
	~FileProcessor();
};

