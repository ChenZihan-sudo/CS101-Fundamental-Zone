# CMake 最低版本号要求
cmake_minimum_required (VERSION 3.0)

set(CMAKE_C_COMPILER "C:\\Program Files\\mingw64\\bin\\gcc.exe")
set(CMAKE_CXX_COMPILER "C:\\Program Files\\mingw64\\bin\\g++.exe")

# 项目信息
project (ProjectName)

# 指定生成目标
add_executable(Demo main.cc)

