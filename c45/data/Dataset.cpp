#include "Dataset.h"

#include <utility>
#include <cmath>
#include <algorithm>


Dataset::Dataset(std::vector<std::string> parametersNames, std::vector<Data> data) : _params(std::move(parametersNames)), _set(std::move(data)) {
    _generateCounts();
}

void Dataset::_generateCounts() {
    this->_counts = std::map<std::string, std::map<std::string, int>>();
    for (auto& param : this->_params) {
        std::map<std::string, int> classCounts;
        for (auto& dataInstance : this->_set) {
            std::string value = dataInstance.getTag(param);
            classCounts[value]++;
        }

        this->_counts.insert(std::pair<std::string, std::map<std::string, int>>(param, classCounts));
    }
}

float Dataset::getEntropy() {
    float result = 0.0;
    auto length = (float) getSize();

    for (auto& param: this->_params) {
        for (auto& caseCount :  this->_counts[param]) {
            float probability = (float) caseCount.second / length;
            result -= (probability) * logf(probability) / logf(2);
        }
    }
    return result;
}

int Dataset::getSize() const {
    return this->_set.size();
}

std::vector<std::string> Dataset::getValues(const std::string &parameter) {
    std::vector<std::string> result;

    auto subMap = this->_counts.find(parameter);
    if (subMap == this->_counts.end())
        throw std::exception();

    for (auto& record : (*subMap).second) {
        if (record.second > 0)
            result.push_back(record.first);
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
