 cmake_minimum_required(VERSION 3.16)
 project(stdAlgoV2)
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
 set(SOURCE_EXE main.cpp src/stdAlgoV2.cpp)

 add_executable(stdAlgoV2 ${SOURCE_EXE})
