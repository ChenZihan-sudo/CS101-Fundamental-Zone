# CMake 最低版本号要求
cmake_minimum_required (VERSION 3.0)

# Specific the cmake compiler
set(CMAKE_C_COMPILER "/bin/clang")
set(CMAKE_CXX_COMPILER "/bin/clang++")

# Project name
project (ProjectName)

add_executable(Demo main.cc)

