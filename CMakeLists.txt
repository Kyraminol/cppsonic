cmake_minimum_required(VERSION 3.14)
project(cppsonic)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(libs)

add_executable(cppsonic example.cpp src/cppsonic.cpp src/cppsonic.h)
target_link_libraries(cppsonic ${CPR_LIBRARIES})
include_directories(${CPR_INCLUDE_DIRS} ${JSON_INCLUDE_DIRS})
