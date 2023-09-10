# CMake 最低版本号要求
cmake_minimum_required (VERSION 3.0)

# include_directories(/usr/include)

# Specific the cmake compiler
set(CMAKE_C_COMPILER "/bin/clang")
set(CMAKE_CXX_COMPILER "/bin/clang++")

# Project name
project (ProjectName)

add_executable(template_prog 
               main.cc 
               outer_lib/outer_lib.c)

