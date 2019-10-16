cmake_minimum_required(VERSION 3.14)
project(tinyxml2)
set(TINYXML2_LIBRARIES tinyxml2 CACHE INTERNAL "")
set(TINYXML2_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include CACHE INTERNAL "")
add_library(${TINYXML2_LIBRARIES}
            "${TINYXML2_INCLUDE_DIRS}/tinyxml2/tinyxml2.cpp"
            "${TINYXML2_INCLUDE_DIRS}/tinyxml2/tinyxml2.h")
include_directories(${TINYXML2_INCLUDE_DIRS})
install(TARGETS ${TINYXML2_LIBRARIES})
install(DIRECTORY include/tinyxml2 DESTINATION include)
