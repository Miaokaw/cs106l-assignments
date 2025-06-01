cmake_minimum_required(VERSION 3.31)
project(assignment1)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES_FILES main.cpp)

add_executable(assignment1_run ${SOURCES_FILES})

target_link_libraries(assignment1_run)

SET_TARGET_PROPERTIES(assignment1_run PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/..")