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
include CMakeFiles/memcpy.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/memcpy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/memcpy.dir/flags.make

CMakeFiles/memcpy.dir/memcpy.cc.o: CMakeFiles/memcpy.dir/flags.make
CMakeFiles/memcpy.dir/memcpy.cc.o: ../memcpy.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/linghutf/20160820/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/memcpy.dir/memcpy.cc.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/memcpy.dir/memcpy.cc.o -c /home/linghutf/20160820/memcpy.cc

CMakeFiles/memcpy.dir/memcpy.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/memcpy.dir/memcpy.cc.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/linghutf/20160820/memcpy.cc > CMakeFiles/memcpy.dir/memcpy.cc.i

CMakeFiles/memcpy.dir/memcpy.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/memcpy.dir/memcpy.cc.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/linghutf/20160820/memcpy.cc -o CMakeFiles/memcpy.dir/memcpy.cc.s

CMakeFiles/memcpy.dir/memcpy.cc.o.requires:

.PHONY : CMakeFiles/memcpy.dir/memcpy.cc.o.requires

CMakeFiles/memcpy.dir/memcpy.cc.o.provides: CMakeFiles/memcpy.dir/memcpy.cc.o.requires
	$(MAKE) -f CMakeFiles/memcpy.dir/build.make CMakeFiles/memcpy.dir/memcpy.cc.o.provides.build
.PHONY : CMakeFiles/memcpy.dir/memcpy.cc.o.provides

CMakeFiles/memcpy.dir/memcpy.cc.o.provides.build: CMakeFiles/memcpy.dir/memcpy.cc.o


# Object files for target memcpy
memcpy_OBJECTS = \
"CMakeFiles/memcpy.dir/memcpy.cc.o"

# External object files for target memcpy
memcpy_EXTERNAL_OBJECTS =

memcpy: CMakeFiles/memcpy.dir/memcpy.cc.o
memcpy: CMakeFiles/memcpy.dir/build.make
memcpy: CMakeFiles/memcpy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/linghutf/20160820/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable memcpy"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/memcpy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/memcpy.dir/build: memcpy

.PHONY : CMakeFiles/memcpy.dir/build

CMakeFiles/memcpy.dir/requires: CMakeFiles/memcpy.dir/memcpy.cc.o.requires

.PHONY : CMakeFiles/memcpy.dir/requires

CMakeFiles/memcpy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/memcpy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/memcpy.dir/clean

CMakeFiles/memcpy.dir/depend:
	cd /home/linghutf/20160820/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/linghutf/20160820 /home/linghutf/20160820 /home/linghutf/20160820/build /home/linghutf/20160820/build /home/linghutf/20160820/build/CMakeFiles/memcpy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/memcpy.dir/depend

