#include "data/DatasetParser.h"
#include "decision_tree/C45Tree.h"

#include <algorithm>
#include <iterator>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Usage: ./c45.exe <dataset_filename>" << std::endl;
        return 1;
    }
    std::cout << "Starting parsing " << argv[1] << "........" << std::endl;
    DatasetParser preProcessor(argv[1]);
    preProcessor.loadParametersDefinition();
    preProcessor.loadData();
    std::cout << "Pars completed!" << std::endl;

    Dataset dataset = preProcessor.initDataset();
    std::cout << "Dataset initialized!" << std::endl;

    C45Tree decisionTreeStart(dataset);
    std::cout << "Tree initialized!" << std::endl;

    C45Tree* currentNode = &decisionTreeStart;
    std::string answer;
    while (true) {
        std::string className = currentNode->getClassName();
        std::vector<std::string> childrenNames = currentNode->getChildrenNames();

        std::cout << className;
        if (childrenNames.empty()) {
            char repeat;
            std::cout << " is an answer" << std::endl;
            std::cout << "Retry? (Y/n)" << std::endl;
            std::cin >> repeat;
            if (repeat == 'Y') {
                currentNode = &decisionTreeStart;
                continue;
            } else {
                return 0;
            }
        }
        std::cout << "? (";
        std::copy(childrenNames.begin(), childrenNames.end(), std::ostream_iterator<std::string>(std::cout, "/"));
        std::cout << ")" << std::endl;

        std::string classAnswer;
        std::cin >> classAnswer;

        currentNode = currentNode->getChild(classAnswer);
        if (currentNode == nullptr) {
            std::cout << "Incorrect answer. Exiting....";
            return 1;
        }
    }
}