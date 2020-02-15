#include "data/DatasetParser.h"

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
    std::cout << "Dataset initialized" << std::endl;
}