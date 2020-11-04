cmake_minimum_required(VERSION 3.16)

project(walletManage)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_EXE main.cpp)

set(SOURCE_LIB walletManager.cpp)

add_library(walletManage STATIC ${SOURCE_LIB})

add_executable(walletManager ${SOURCE_EXE})

target_link_libraries(walletManager walletManage)
