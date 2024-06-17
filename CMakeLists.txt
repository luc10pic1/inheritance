cmake_minimum_required(VERSION 3.27)
project(inheritance)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES pieces.cpp pieces.h chessboard.cpp chessboard.h)
add_executable(inheritance main.cpp)
add_library(pieces ${SOURCE_FILES})
target_link_libraries(inheritance pieces)
