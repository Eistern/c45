#pragma once
#include <iostream>
#include <map>
#include <list>

class Data {
private:
	std::map<std::string, std::string> _tags;
	std::string _className;
public:
	Data(const std::list<std::string>& tagNames, std::string tagValues, std::string className);
	Data(const Data& other);

	Data& operator=(const Data& other);
    Data& operator=(Data&& other) noexcept;

	std::string getTag(const std::string& tagName);
	std::map<std::string, std::string>& getTags();

	~Data();
};

