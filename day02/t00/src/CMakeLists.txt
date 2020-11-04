cmake_minimum_required(VERSION 3.16)
project(mylib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

add_compile_options(
    -pipe
    -Wall
    -Wextra
    -Werror
    -Wpedantic
)

set(SOURCE_LIB myFunction.cpp uniqueWords.cpp)
add_library(SOURCE_LIB STATIC ${SOURCE_LIB})
