#include "Data.h"

#include <utility>
#include <cctype>
#include <algorithm>

Data::Data(const std::vector<std::string>& tagNames, std::string tagValues) {
	this->_tags = std::map<std::string, std::string>();

	size_t pos = 0;
	std::string token;
	auto namesIterator = tagNames.begin();

	while ((pos = tagValues.find(';')) != std::string::npos) {
		token = tagValues.substr(0, pos);
        std::transform(token.begin(), token.end(), token.begin(),
                       [](unsigned char c){ return std::tolower(c); });
		this->_tags.insert(std::pair<std::string, std::string>(*namesIterator, token));
		tagValues.erase(0, pos + 1);
		namesIterator++;
	}
    this->_className = tagValues;
}

Data::Data(const Data &other) = default;

Data &Data::operator=(const Data &other) {
    if (this != &other) {
        this->_className = other._className;
        this->_tags = other._tags;
    }
    return *this;
}

std::string Data::getTag(const std::string &tagName) const {
    auto result = this->_tags.find(tagName);
    if (result == this->_tags.end())
        throw std::exception();

    return result->second;
}

std::string Data::getClass() const {
    return this->_className;
}

Data &Data::operator=(Data &&other) noexcept {
    if (this != &other) {
        this->_className = std::move(other._className);
        this->_tags = std::move(other._tags);
    }
    return *this;
}

Data::~Data() = default;
