cmake_minimum_required (VERSION 3.5)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

aux_source_directory(. DIR_SRCS)
add_executable(AVL.exec ${DIR_SRCS})

project(ANDROID_NATIVE_LIB_DEPENDENCIES)