cmake_minimum_required(VERSION 3.14)
project(cppsonic_example)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(libs)

add_executable(cppsonic_example example.cpp src/cppsonic.cpp src/cppsonic.h)
target_link_libraries(cppsonic_example ${CPR_LIBRARIES} ${TINYXML2_LIBRARIES})
include_directories(${CPR_INCLUDE_DIRS} ${TINYXML2_INCLUDE_DIRS})
