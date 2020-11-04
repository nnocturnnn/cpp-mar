 cmake_minimum_required(VERSION 3.16)
 project(simpleSort)
 set(SOURCE_EXE main.cpp)
 set(CMAKE_CXX_EXTENSIONS OFF)
 add_compile_options(
         -std=c++17
         -Werror
         -Wall
         -Wextra
         -Wpedantic
 )
 set(SOURCE_EXE main.cpp)

 add_executable(simpleSort ${SOURCE_EXE})
