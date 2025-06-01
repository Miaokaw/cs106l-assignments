cmake_minimum_required(VERSION 3.31)
project(assignment7)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES_FILES main.cpp)

add_executable(main ${SOURCES_FILES})


target_link_libraries(main)

SET_TARGET_PROPERTIES(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/..")