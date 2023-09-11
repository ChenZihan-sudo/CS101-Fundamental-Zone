*CMake Offical Documentation: https://cmake.org/cmake/help/latest/*

## Basic
### Add executable
Generate a executable program called <name>
```cmake
add_executable(<name> [WIN32] [MACOSX_BUNDLE]
               [EXCLUDE_FROM_ALL]
               [source1] [source2 ...])
```

### Add mulitiple source code
**ADD MULTI SOURCE CODE FILE PATH**  
Collects the names of all the source files in the specified directory and stores the list in the <variable> provided.
```cmake
aux_source_directory(<dir> <variable>)
```

### Include directories
**INCLUDE HEADER FILE PATH**  
Add the given directories to those the compiler uses to search for include files. Relative paths are interpreted as relative to the current source directory.
```cmake
include_directories([AFTER|BEFORE] [SYSTEM] dir1 [dir2 ...])
```

### Add subdirectory
**ADD SUBDIR CMAKELISTS**  
Adds a subdirectory to the build. The source_dir specifies the directory in which the source CMakeLists.txt and code files are located.
```cmake
add_subdirectory(source_dir [binary_dir] [EXCLUDE_FROM_ALL] [SYSTEM])
```

## Custom compile options
### Set options
Provide an option that the user can optionally select.
```cmake
option(<variable> "<help_text>" [value])
```
### Set output for config file
Copy a file to another location and modify its contents.
Create a file as path of `<input>`, `configure_file` will generate `<output>` file.
In `<input>` file, use `#cmakedefine <name>` to define an option
```cmake
configure_file(<input> <output>)
```

### Use control statement with variable option to customize your operations
```cmake
#if(<variable declared using option()>)
# ...
#endif
```

## Library
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
```cmakes
target_link_libraries(<target> ... <item>... ...)```

### Custom compile options

# PROJECT_BIN_DIR PROJECT_SOURCE_DIR