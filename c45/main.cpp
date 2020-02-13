#include "DatasetParser.h"

int main(int argc, char** argv) {
    if (argc < 1) {
        std::cout << "Usage: <dataset_filename>" << std::endl;
        return 1;
    }

    DatasetParser preProcessor(argv[0]);
}