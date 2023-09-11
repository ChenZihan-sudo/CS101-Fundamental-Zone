# CMake 最低版本号要求
cmake_minimum_required (VERSION 3.0)

# include_directories(/usr/include)

# Specific the cmake compiler
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

# Project name
project (ProjectName)

# Find all source file from the dir, stores the list in <variable>
aux_source_directory(. DIR_SRCS)

add_subdirectory(outer_lib)

# Generate a executable program called <name>
add_executable(template_prog ${DIR_SRCS})

target_link_libraries(template_prog the_outer_lib)

