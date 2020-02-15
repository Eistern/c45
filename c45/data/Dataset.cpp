#include "Dataset.h"

#include <utility>
#include <cmath>
#include <algorithm>


Dataset::Dataset(std::vector<std::string> parametersNames, std::vector<Data> data) : _params(std::move(parametersNames)), _set(std::move(data)) {
    _generateCounts();
}

void Dataset::_generateCounts() {
    for (auto& dataInstance : this->_set) {
        std::string value = dataInstance.getClass();
        this->_counts[value]++;
    }
}

float Dataset::getEntropy() const {
    float result = 0.0;
    auto length = (float) getSize();

    for (auto& caseCount :  this->_counts) {
        float probability = (float) caseCount.second / length;
        result -= (probability) * log2f(probability);
    }
    return result;
}

int Dataset::getSize() const {
    return this->_set.size();
}

std::vector<std::string> Dataset::getValues(const std::string &parameter) const {
    std::vector<std::string> result;

    for (auto& record : this->_set) {
        std::string tagValue = record.getTag(parameter);
        if (std::find(result.begin(), result.end(), tagValue) == result.end()) {
            result.push_back(tagValue);
        }
    }

    return result;
}

void Dataset::filterByParam(const std::string &paramName, const std::string &paramValue) {
    auto res_it_set = std::remove_if(this->_set.begin(), this->_set.end(), [paramName, paramValue](Data const& member) { return member.getTag(paramName) != paramValue; });
    this->_set.erase(res_it_set, this->_set.end());

    auto res_it_params = std::remove_if(this->_params.begin(), this->_params.end(), [paramName](std::string const& param){ return param == paramName; });
    this->_params.erase(res_it_params, this->_params.end());

    _generateCounts();
}

const std::vector<std::string> &Dataset::getParamsNames() const {
    return this->_params;
}

const std::vector<Data> &Dataset::getCases() const {
    return this->_set;
}

Dataset::Dataset(const Dataset &other) = default;

Dataset::~Dataset() = default;
