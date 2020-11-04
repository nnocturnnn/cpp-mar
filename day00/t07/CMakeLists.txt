 cmake_minimum_required(VERSION 3.16)
 project(inventory)
 set(SOURCE_EXE main.cpp)
 set(CMAKE_CXX_EXTENSIONS OFF)
 add_compile_options(
         -std=c++17
         -Werror
         -Wall
         -Wextra
         -Wpedantic
 )
 set(SOURCE_EXE src/command.cpp src/validate.cpp main.cpp)

 add_executable(inventory ${SOURCE_EXE})
