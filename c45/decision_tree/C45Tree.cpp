#include "C45Tree.h"

#include <cmath>

C45Tree::C45Tree(const Dataset& originDataset) : _children() {
    if (originDataset.getSize() == 1) {
        this->_className = originDataset.getCases().at(0).getClass();
    } else {
        const auto& paramNames = originDataset.getParamsNames();
        float maxGainRatio = 0.0;

        float originEntropy = originDataset.getEntropy();
        auto originSize = (float) originDataset.getSize();

        std::string bestParam;
        std::map<std::string, Dataset> bestSeparation;

        for (auto& paramName : paramNames) {
            float informationGain = originEntropy;
            float intrinsicValue = 0.0;
            float gainRatio;
            std::map<std::string, Dataset> currentSeparation;

            const auto& paramValues = originDataset.getValues(paramName);
            for (auto& paramValue : paramValues) {
                Dataset separatedDataset(originDataset);
                separatedDataset.filterByParam(paramName, paramValue);
                currentSeparation.insert(std::pair<std::string, Dataset>(paramValue, separatedDataset));

                informationGain -= (float) separatedDataset.getSize() / originSize * separatedDataset.getEntropy();
                intrinsicValue -= (float) separatedDataset.getSize() / originSize * log2f((float) separatedDataset.getSize() / originSize);
            }

            gainRatio = informationGain / intrinsicValue;
            if (gainRatio > maxGainRatio) {
                bestParam = paramName;
                bestSeparation = currentSeparation;
            }
        }

        this->_className = bestParam;
        for (auto& subset : bestSeparation) {
            this->_children.insert(std::pair<std::string, C45Tree>(subset.first, C45Tree(subset.second)));
        }
    }
}

std::vector<std::string> C45Tree::getChildrenNames() const {
    std::vector<std::string> result;
    for (auto& entry : this->_children) {
        result.push_back(entry.first);
    }

    return result;
}

std::string C45Tree::getClassName() const {
    return this->_className;
}

C45Tree C45Tree::getChild(const std::string &name) {
    return this->_children.at(name);
}

C45Tree::~C45Tree() = default;
