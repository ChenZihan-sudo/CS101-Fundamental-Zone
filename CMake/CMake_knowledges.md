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

### Set and output message of variables
https://stackoverflow.com/questions/29078618/set-syntax-in-cmake
Set or unset `<variable>` in the current function or directory scope
```cmake
set(<variable> <value>... [PARENT_SCOPE])
message([<mode>] "message text" ...)
```
Example: 
```cmake
set (VALUE_1 "default value")
set (VALUE_2 "default value")

set (VALUE_1 "value 1")  # A
set (VALUE_2 ${VALUE_2} "value 2")  # B

message("value 1:" ${VALUE_1})
message("value 2:" ${VALUE_2})
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
target_link_libraries(<target> ... <item>... ...)
```

### Custom compile options

# PROJECT_BIN_DIR PROJECT_SOURCE_DIR


## Install
### Customize install rules
Specify rules to run at install time.
```cmake
install(TARGETS <target>... [...])
install(IMPORTED_RUNTIME_ARTIFACTS <target>... [...])
install({FILES | PROGRAMS} <file>... [...])
install(DIRECTORY <dir>... [...])
install(SCRIPT <file> [...])
install(CODE <code> [...])
install(EXPORT <export-name> [...])
install(RUNTIME_DEPENDENCY_SET <set-name> [...])
```
