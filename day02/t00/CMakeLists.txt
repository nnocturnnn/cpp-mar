cmake_minimum_required(VERSION 3.16)
project(uniqueWords LANGUAGES CXX)

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

set(SOURCE_EXE main.cpp)
include_directories(src)

add_subdirectory(src)
add_executable(uniqueWords ${SOURCE_EXE})
target_link_libraries(uniqueWords SOURCE_LIB)
