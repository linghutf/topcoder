# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/linghutf/20160820

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/linghutf/20160820/build

# Include any dependencies generated for this target.
include CMakeFiles/read_file.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/read_file.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/read_file.dir/flags.make

CMakeFiles/read_file.dir/read_file.c.o: CMakeFiles/read_file.dir/flags.make
CMakeFiles/read_file.dir/read_file.c.o: ../read_file.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/linghutf/20160820/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/read_file.dir/read_file.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/read_file.dir/read_file.c.o   -c /home/linghutf/20160820/read_file.c

CMakeFiles/read_file.dir/read_file.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/read_file.dir/read_file.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/linghutf/20160820/read_file.c > CMakeFiles/read_file.dir/read_file.c.i

CMakeFiles/read_file.dir/read_file.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/read_file.dir/read_file.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/linghutf/20160820/read_file.c -o CMakeFiles/read_file.dir/read_file.c.s

CMakeFiles/read_file.dir/read_file.c.o.requires:

.PHONY : CMakeFiles/read_file.dir/read_file.c.o.requires

CMakeFiles/read_file.dir/read_file.c.o.provides: CMakeFiles/read_file.dir/read_file.c.o.requires
	$(MAKE) -f CMakeFiles/read_file.dir/build.make CMakeFiles/read_file.dir/read_file.c.o.provides.build
.PHONY : CMakeFiles/read_file.dir/read_file.c.o.provides

CMakeFiles/read_file.dir/read_file.c.o.provides.build: CMakeFiles/read_file.dir/read_file.c.o


# Object files for target read_file
read_file_OBJECTS = \
"CMakeFiles/read_file.dir/read_file.c.o"

# External object files for target read_file
read_file_EXTERNAL_OBJECTS =

read_file: CMakeFiles/read_file.dir/read_file.c.o
read_file: CMakeFiles/read_file.dir/build.make
read_file: CMakeFiles/read_file.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/linghutf/20160820/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable read_file"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/read_file.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/read_file.dir/build: read_file

.PHONY : CMakeFiles/read_file.dir/build

CMakeFiles/read_file.dir/requires: CMakeFiles/read_file.dir/read_file.c.o.requires

.PHONY : CMakeFiles/read_file.dir/requires

CMakeFiles/read_file.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/read_file.dir/cmake_clean.cmake
.PHONY : CMakeFiles/read_file.dir/clean

CMakeFiles/read_file.dir/depend:
	cd /home/linghutf/20160820/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/linghutf/20160820 /home/linghutf/20160820 /home/linghutf/20160820/build /home/linghutf/20160820/build /home/linghutf/20160820/build/CMakeFiles/read_file.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/read_file.dir/depend

