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
include CMakeFiles/z-algo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/z-algo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/z-algo.dir/flags.make

CMakeFiles/z-algo.dir/z-algo.cc.o: CMakeFiles/z-algo.dir/flags.make
CMakeFiles/z-algo.dir/z-algo.cc.o: ../z-algo.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/linghutf/20160820/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/z-algo.dir/z-algo.cc.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/z-algo.dir/z-algo.cc.o -c /home/linghutf/20160820/z-algo.cc

CMakeFiles/z-algo.dir/z-algo.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/z-algo.dir/z-algo.cc.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/linghutf/20160820/z-algo.cc > CMakeFiles/z-algo.dir/z-algo.cc.i

CMakeFiles/z-algo.dir/z-algo.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/z-algo.dir/z-algo.cc.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/linghutf/20160820/z-algo.cc -o CMakeFiles/z-algo.dir/z-algo.cc.s

CMakeFiles/z-algo.dir/z-algo.cc.o.requires:

.PHONY : CMakeFiles/z-algo.dir/z-algo.cc.o.requires

CMakeFiles/z-algo.dir/z-algo.cc.o.provides: CMakeFiles/z-algo.dir/z-algo.cc.o.requires
	$(MAKE) -f CMakeFiles/z-algo.dir/build.make CMakeFiles/z-algo.dir/z-algo.cc.o.provides.build
.PHONY : CMakeFiles/z-algo.dir/z-algo.cc.o.provides

CMakeFiles/z-algo.dir/z-algo.cc.o.provides.build: CMakeFiles/z-algo.dir/z-algo.cc.o


# Object files for target z-algo
z__algo_OBJECTS = \
"CMakeFiles/z-algo.dir/z-algo.cc.o"

# External object files for target z-algo
z__algo_EXTERNAL_OBJECTS =

z-algo: CMakeFiles/z-algo.dir/z-algo.cc.o
z-algo: CMakeFiles/z-algo.dir/build.make
z-algo: CMakeFiles/z-algo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/linghutf/20160820/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable z-algo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/z-algo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/z-algo.dir/build: z-algo

.PHONY : CMakeFiles/z-algo.dir/build

CMakeFiles/z-algo.dir/requires: CMakeFiles/z-algo.dir/z-algo.cc.o.requires

.PHONY : CMakeFiles/z-algo.dir/requires

CMakeFiles/z-algo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/z-algo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/z-algo.dir/clean

CMakeFiles/z-algo.dir/depend:
	cd /home/linghutf/20160820/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/linghutf/20160820 /home/linghutf/20160820 /home/linghutf/20160820/build /home/linghutf/20160820/build /home/linghutf/20160820/build/CMakeFiles/z-algo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/z-algo.dir/depend
