*CMake Offical Documentation: https://cmake.org/cmake/help/latest/*

### Add executable
Generate a executable program called <name>
```cmake
add_executable(<name> [WIN32] [MACOSX_BUNDLE]
               [EXCLUDE_FROM_ALL]
               [source1] [source2 ...])
```

### Add source code
Collects the names of all the source files in the specified directory and stores the list in the <variable> provided.
```cmake
aux_source_directory(<dir> <variable>)
```

### Add Subdirectory
Adds a subdirectory to the build. The source_dir specifies the directory in which the source CMakeLists.txt and code files are located.
```cmake
add_subdirectory(source_dir [binary_dir] [EXCLUDE_FROM_ALL] [SYSTEM])
```

### Add library
Add a library to the project using the specified source files.

#### Normal libraries
```cmake
add_library(<name> [STATIC | SHARED | MODULE]
            [EXCLUDE_FROM_ALL]
            [<source>...])
```

### Linking a library
Specify libraries or flags to use when linking a given target and/or its dependents. Usage requirements from linked library targets will be propagated. Usage requirements of a target's dependencies affect compilation of its own sources.
```cmake 
target_link_libraries(<target> ... <item>... ...)```