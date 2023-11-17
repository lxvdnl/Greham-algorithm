cmake_minimum_required(VERSION 3.10)
project(GrehamAlgorithm)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_DIR src)

set(SOURCES
    ${SOURCE_DIR}/main.cpp
    ${SOURCE_DIR}/Point.cpp
    ${SOURCE_DIR}/QuickSort.cpp
    ${SOURCE_DIR}/AVL_Tree.cpp
    ${SOURCE_DIR}/Stack.cpp
    
)

set(HEADERS
    headers/AVL_Tree.h
    headers/Point.h
    headers/QuickSort.h
    headers/Stack.h
)

include_directories(
    ${SOURCE_DIR}/../headers
)

add_executable(GrehamAlgorithm ${SOURCES} ${HEADERS})