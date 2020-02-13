#include "Data.h"


Data::Data(std::list<std::string> tagNames, std::string tagValues, std::string _className) : className(_className) {
	this->tags = std::map<std::string, std::string>();

	size_t pos = 0;
	std::string token;
	auto namesIterator = tagNames.begin();

	while ((pos = tagValues.find(',')) != std::string::npos) {
		token = tagValues.substr(0, pos);
		this->tags.insert(*namesIterator, token);
		tagValues.erase(0, pos + 1);
		namesIterator++;
	}
	this->tags.insert(*namesIterator, tagValues);
}

Data::Data(const Data &other) {
    this->className = other.className;
    this->tags = other.tags;
}

Data &Data::operator=(const Data &other) {
    if (this != &other) {
        this->className = other.className;
        this->tags = other.tags;
    }
    return *this;
}

Data &Data::operator=(Data &&other) noexcept {
    if (this != &other) {
        this->className = std::move(other.className);
        this->tags = std::move(other.tags);
    }
    return *this;
}

Data::~Data() = default;
