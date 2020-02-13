#pragma once

#include <string>

class CSVParser {
    std::string _currentLine;
    char _delimiter;
public:
    CSVParser(const char& delimiter);

    void loadLine(std::string& line);

    ~CSVParser();
};
