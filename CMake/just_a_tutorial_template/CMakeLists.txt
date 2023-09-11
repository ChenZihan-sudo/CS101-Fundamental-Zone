# CMake 最低版本号要求
cmake_minimum_required (VERSION 3.0)

include_directories(/usr/include)

# Specific the cmake compiler
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

# Project name
project(ProjectName)

option(USE_OUTER_LIB "Use provided outer lib implementation" ON)

configure_file(
    "${PROJECT_SOURCE_DIR}/option_config"
    "${PROJECT_SOURCE_DIR}/configs/option_config.h"
)

if(USE_OUTER_LIB)
  include_directories("${PROJECT_SOURCE_DIR}/outer_lib")
  # Adds a subdirectory to the build.  
  # The ``source_dir`` specifies the directory in which the source ``CMakeLists.txt`` and code files are located.
  add_subdirectory(outer_lib)
  set(EXTRA_LIBS ${EXTRA_LIBS} the_outer_lib)
endif(USE_OUTER_LIB)

# Find all source file from the dir, stores the list in <variable>
aux_source_directory(. DIR_SRCS)

# Generate a executable program called <name>
add_executable(template_prog ${DIR_SRCS})

if(USE_OUTER_LIB)
target_link_libraries(template_prog the_outer_lib)
endif(USE_OUTER_LIB)
