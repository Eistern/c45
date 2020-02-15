cmake_minimum_required(VERSION 3.15)
project(c45)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(c45
        data/Data.cpp
        data/Data.h
        data/DatasetParser.cpp
        data/DatasetParser.h
        main.cpp CSVUtils.h data/Dataset.cpp data/Dataset.h)
