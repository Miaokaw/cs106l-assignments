cmake_minimum_required(VERSION 3.31)
project(assignment0)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES_FILES main.cpp)

add_executable(assignment0_run ${SOURCES_FILES})

target_link_libraries(assignment0_run)

SET_TARGET_PROPERTIES(assignment0_run PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/..")