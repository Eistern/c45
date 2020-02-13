#include "DatasetParser.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Usage: <dataset_filename>" << std::endl;
        return 1;
    }
    std::cout << "Starting parsing " << argv[1] << std::endl;
    DatasetParser preProcessor(argv[1]);
    preProcessor.loadParametersDefinition();
    preProcessor.loadData();
}