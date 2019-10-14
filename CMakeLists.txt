cmake_minimum_required(VERSION 3.14)
project(cppsonic)

set(CMAKE_CXX_STANDARD 17)

add_executable(cppsonic example.cpp src/cppsonic.h src/cppsonic.cpp)
