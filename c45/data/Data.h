#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <map>
#include <vector>

class Data {
private:
	std::map<std::string, std::string> _tags;
	std::string _className;
public:
	Data(const std::vector<std::string>& tagNames, std::string tagValues);
	Data(const Data& other);

	Data& operator=(const Data& other);
    Data& operator=(Data&& other) noexcept;

	std::string getTag(const std::string& tagName) const;
	std::string getClass() const;

	~Data();
};

#endif