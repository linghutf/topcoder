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
include CMakeFiles/touzi.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/touzi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/touzi.dir/flags.make

CMakeFiles/touzi.dir/touzi.cc.o: CMakeFiles/touzi.dir/flags.make
CMakeFiles/touzi.dir/touzi.cc.o: ../touzi.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/linghutf/20160820/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/touzi.dir/touzi.cc.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/touzi.dir/touzi.cc.o -c /home/linghutf/20160820/touzi.cc

CMakeFiles/touzi.dir/touzi.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/touzi.dir/touzi.cc.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/linghutf/20160820/touzi.cc > CMakeFiles/touzi.dir/touzi.cc.i

CMakeFiles/touzi.dir/touzi.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/touzi.dir/touzi.cc.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/linghutf/20160820/touzi.cc -o CMakeFiles/touzi.dir/touzi.cc.s

CMakeFiles/touzi.dir/touzi.cc.o.requires:

.PHONY : CMakeFiles/touzi.dir/touzi.cc.o.requires

CMakeFiles/touzi.dir/touzi.cc.o.provides: CMakeFiles/touzi.dir/touzi.cc.o.requires
	$(MAKE) -f CMakeFiles/touzi.dir/build.make CMakeFiles/touzi.dir/touzi.cc.o.provides.build
.PHONY : CMakeFiles/touzi.dir/touzi.cc.o.provides

CMakeFiles/touzi.dir/touzi.cc.o.provides.build: CMakeFiles/touzi.dir/touzi.cc.o


# Object files for target touzi
touzi_OBJECTS = \
"CMakeFiles/touzi.dir/touzi.cc.o"

# External object files for target touzi
touzi_EXTERNAL_OBJECTS =

touzi: CMakeFiles/touzi.dir/touzi.cc.o
touzi: CMakeFiles/touzi.dir/build.make
touzi: CMakeFiles/touzi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/linghutf/20160820/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable touzi"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/touzi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/touzi.dir/build: touzi

.PHONY : CMakeFiles/touzi.dir/build

CMakeFiles/touzi.dir/requires: CMakeFiles/touzi.dir/touzi.cc.o.requires

.PHONY : CMakeFiles/touzi.dir/requires

CMakeFiles/touzi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/touzi.dir/cmake_clean.cmake
.PHONY : CMakeFiles/touzi.dir/clean

CMakeFiles/touzi.dir/depend:
	cd /home/linghutf/20160820/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/linghutf/20160820 /home/linghutf/20160820 /home/linghutf/20160820/build /home/linghutf/20160820/build /home/linghutf/20160820/build/CMakeFiles/touzi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/touzi.dir/depend
