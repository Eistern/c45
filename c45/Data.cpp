#include "Data.h"

#include <utility>

Data::Data(const std::list<std::string>& tagNames, std::string tagValues, std::string className) : _className(std::move(className)) {
	this->_tags = std::map<std::string, std::string>();

	size_t pos = 0;
	std::string token;
	auto namesIterator = tagNames.begin();

	while ((pos = tagValues.find(',')) != std::string::npos) {
		token = tagValues.substr(0, pos);
		this->_tags.insert(std::pair<std::string, std::string>(*namesIterator, token));
		tagValues.erase(0, pos + 1);
		namesIterator++;
	}
    this->_tags.insert(std::pair<std::string, std::string>(*namesIterator, tagValues));
}

Data::Data(const Data &other) {
    this->_className = other._className;
    this->_tags = other._tags;
}
Data &Data::operator=(const Data &other) {
    if (this != &other) {
        this->_className = other._className;
        this->_tags = other._tags;
    }
    return *this;
}

std::string Data::getTag(const std::string &tagName) {
    auto result = this->_tags.find(tagName);
    if (result == this->_tags.end())
        throw std::exception();

    return result->second;
}

Data &Data::operator=(Data &&other) noexcept {
    if (this != &other) {
        this->_className = std::move(other._className);
        this->_tags = std::move(other._tags);
    }
    return *this;
}

std::map<std::string, std::string>& Data::getTags() {
    return this->_tags;
}

Data::~Data() = default;
