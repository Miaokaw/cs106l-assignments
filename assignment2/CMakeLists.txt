cmake_minimum_required(VERSION 3.31)
project(assignment2)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES_FILES main.cpp)

add_executable(assignment2_run ${SOURCES_FILES})

target_link_libraries(assignment2_run)

SET_TARGET_PROPERTIES(assignment2_run PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/..")