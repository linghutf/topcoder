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
include CMakeFiles/swap_oe.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/swap_oe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/swap_oe.dir/flags.make

CMakeFiles/swap_oe.dir/swap_odd_even.cc.o: CMakeFiles/swap_oe.dir/flags.make
CMakeFiles/swap_oe.dir/swap_odd_even.cc.o: ../swap_odd_even.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/linghutf/20160820/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/swap_oe.dir/swap_odd_even.cc.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/swap_oe.dir/swap_odd_even.cc.o -c /home/linghutf/20160820/swap_odd_even.cc

CMakeFiles/swap_oe.dir/swap_odd_even.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/swap_oe.dir/swap_odd_even.cc.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/linghutf/20160820/swap_odd_even.cc > CMakeFiles/swap_oe.dir/swap_odd_even.cc.i

CMakeFiles/swap_oe.dir/swap_odd_even.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/swap_oe.dir/swap_odd_even.cc.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/linghutf/20160820/swap_odd_even.cc -o CMakeFiles/swap_oe.dir/swap_odd_even.cc.s

CMakeFiles/swap_oe.dir/swap_odd_even.cc.o.requires:

.PHONY : CMakeFiles/swap_oe.dir/swap_odd_even.cc.o.requires

CMakeFiles/swap_oe.dir/swap_odd_even.cc.o.provides: CMakeFiles/swap_oe.dir/swap_odd_even.cc.o.requires
	$(MAKE) -f CMakeFiles/swap_oe.dir/build.make CMakeFiles/swap_oe.dir/swap_odd_even.cc.o.provides.build
.PHONY : CMakeFiles/swap_oe.dir/swap_odd_even.cc.o.provides

CMakeFiles/swap_oe.dir/swap_odd_even.cc.o.provides.build: CMakeFiles/swap_oe.dir/swap_odd_even.cc.o


# Object files for target swap_oe
swap_oe_OBJECTS = \
"CMakeFiles/swap_oe.dir/swap_odd_even.cc.o"

# External object files for target swap_oe
swap_oe_EXTERNAL_OBJECTS =

swap_oe: CMakeFiles/swap_oe.dir/swap_odd_even.cc.o
swap_oe: CMakeFiles/swap_oe.dir/build.make
swap_oe: CMakeFiles/swap_oe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/linghutf/20160820/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable swap_oe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/swap_oe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/swap_oe.dir/build: swap_oe

.PHONY : CMakeFiles/swap_oe.dir/build

CMakeFiles/swap_oe.dir/requires: CMakeFiles/swap_oe.dir/swap_odd_even.cc.o.requires

.PHONY : CMakeFiles/swap_oe.dir/requires

CMakeFiles/swap_oe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/swap_oe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/swap_oe.dir/clean

CMakeFiles/swap_oe.dir/depend:
	cd /home/linghutf/20160820/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/linghutf/20160820 /home/linghutf/20160820 /home/linghutf/20160820/build /home/linghutf/20160820/build /home/linghutf/20160820/build/CMakeFiles/swap_oe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/swap_oe.dir/depend
