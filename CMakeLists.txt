cmake_minimum_required(VERSION 3.27)
project(untitled)

set(CMAKE_CXX_STANDARD 23)

add_executable(untitled
        "parallel prog 1.cpp"
        FileWriter.cpp
        Matrix.cpp)
