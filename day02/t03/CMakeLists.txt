 cmake_minimum_required(VERSION 3.16)
 project(tesLibrary)
 set(SOURCE_EXE main.cpp)
 set(CMAKE_CXX_STANDARD 17)
 set(CMAKE_CXX_STANDARD_REQUIRED YES)
 set(CMAKE_CXX_EXTENSIONS OFF)
 add_compile_options(
         -Werror
         -Wall
         -Wextra
         -Wpedantic
         -Wno-unused-parameter
 )
 set(SOURCE_EXE main.cpp )

 add_executable(tesLibrary ${SOURCE_EXE})
