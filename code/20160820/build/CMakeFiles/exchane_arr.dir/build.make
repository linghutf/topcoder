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
include CMakeFiles/exchane_arr.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/exchane_arr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exchane_arr.dir/flags.make

CMakeFiles/exchane_arr.dir/meituan.cc.o: CMakeFiles/exchane_arr.dir/flags.make
CMakeFiles/exchane_arr.dir/meituan.cc.o: ../meituan.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/linghutf/20160820/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/exchane_arr.dir/meituan.cc.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/exchane_arr.dir/meituan.cc.o -c /home/linghutf/20160820/meituan.cc

CMakeFiles/exchane_arr.dir/meituan.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exchane_arr.dir/meituan.cc.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/linghutf/20160820/meituan.cc > CMakeFiles/exchane_arr.dir/meituan.cc.i

CMakeFiles/exchane_arr.dir/meituan.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exchane_arr.dir/meituan.cc.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/linghutf/20160820/meituan.cc -o CMakeFiles/exchane_arr.dir/meituan.cc.s

CMakeFiles/exchane_arr.dir/meituan.cc.o.requires:

.PHONY : CMakeFiles/exchane_arr.dir/meituan.cc.o.requires

CMakeFiles/exchane_arr.dir/meituan.cc.o.provides: CMakeFiles/exchane_arr.dir/meituan.cc.o.requires
	$(MAKE) -f CMakeFiles/exchane_arr.dir/build.make CMakeFiles/exchane_arr.dir/meituan.cc.o.provides.build
.PHONY : CMakeFiles/exchane_arr.dir/meituan.cc.o.provides

CMakeFiles/exchane_arr.dir/meituan.cc.o.provides.build: CMakeFiles/exchane_arr.dir/meituan.cc.o


# Object files for target exchane_arr
exchane_arr_OBJECTS = \
"CMakeFiles/exchane_arr.dir/meituan.cc.o"

# External object files for target exchane_arr
exchane_arr_EXTERNAL_OBJECTS =

exchane_arr: CMakeFiles/exchane_arr.dir/meituan.cc.o
exchane_arr: CMakeFiles/exchane_arr.dir/build.make
exchane_arr: CMakeFiles/exchane_arr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/linghutf/20160820/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable exchane_arr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/exchane_arr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exchane_arr.dir/build: exchane_arr

.PHONY : CMakeFiles/exchane_arr.dir/build

CMakeFiles/exchane_arr.dir/requires: CMakeFiles/exchane_arr.dir/meituan.cc.o.requires

.PHONY : CMakeFiles/exchane_arr.dir/requires

CMakeFiles/exchane_arr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/exchane_arr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/exchane_arr.dir/clean

CMakeFiles/exchane_arr.dir/depend:
	cd /home/linghutf/20160820/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/linghutf/20160820 /home/linghutf/20160820 /home/linghutf/20160820/build /home/linghutf/20160820/build /home/linghutf/20160820/build/CMakeFiles/exchane_arr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/exchane_arr.dir/depend
