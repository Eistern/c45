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


Data::~Data()
{
}
