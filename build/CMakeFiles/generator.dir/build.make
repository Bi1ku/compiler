# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/biiku/code/interpreter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/biiku/code/interpreter/build

# Include any dependencies generated for this target.
include CMakeFiles/generator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/generator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/generator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/generator.dir/flags.make

CMakeFiles/generator.dir/src/generator.c.o: CMakeFiles/generator.dir/flags.make
CMakeFiles/generator.dir/src/generator.c.o: /Users/biiku/code/interpreter/src/generator.c
CMakeFiles/generator.dir/src/generator.c.o: CMakeFiles/generator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/biiku/code/interpreter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/generator.dir/src/generator.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/generator.dir/src/generator.c.o -MF CMakeFiles/generator.dir/src/generator.c.o.d -o CMakeFiles/generator.dir/src/generator.c.o -c /Users/biiku/code/interpreter/src/generator.c

CMakeFiles/generator.dir/src/generator.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/generator.dir/src/generator.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/biiku/code/interpreter/src/generator.c > CMakeFiles/generator.dir/src/generator.c.i

CMakeFiles/generator.dir/src/generator.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/generator.dir/src/generator.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/biiku/code/interpreter/src/generator.c -o CMakeFiles/generator.dir/src/generator.c.s

# Object files for target generator
generator_OBJECTS = \
"CMakeFiles/generator.dir/src/generator.c.o"

# External object files for target generator
generator_EXTERNAL_OBJECTS =

libgenerator.dylib: CMakeFiles/generator.dir/src/generator.c.o
libgenerator.dylib: CMakeFiles/generator.dir/build.make
libgenerator.dylib: libutils.dylib
libgenerator.dylib: CMakeFiles/generator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/biiku/code/interpreter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libgenerator.dylib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/generator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/generator.dir/build: libgenerator.dylib
.PHONY : CMakeFiles/generator.dir/build

CMakeFiles/generator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/generator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/generator.dir/clean

CMakeFiles/generator.dir/depend:
	cd /Users/biiku/code/interpreter/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/biiku/code/interpreter /Users/biiku/code/interpreter /Users/biiku/code/interpreter/build /Users/biiku/code/interpreter/build /Users/biiku/code/interpreter/build/CMakeFiles/generator.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/generator.dir/depend

