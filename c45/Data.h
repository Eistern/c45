#pragma once
#include <iostream>
#include <map>
#include <list>

class Data {
private:
	std::map<std::string, std::string> tags;
	std::string className;
public:
	Data(std::list<std::string> tagNames, std::string tagValues, std::string _className);
	~Data();
};

