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
include CMakeFiles/five_colors.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/five_colors.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/five_colors.dir/flags.make

CMakeFiles/five_colors.dir/five_color_shortest_dis.cc.o: CMakeFiles/five_colors.dir/flags.make
CMakeFiles/five_colors.dir/five_color_shortest_dis.cc.o: ../five_color_shortest_dis.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/linghutf/20160820/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/five_colors.dir/five_color_shortest_dis.cc.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/five_colors.dir/five_color_shortest_dis.cc.o -c /home/linghutf/20160820/five_color_shortest_dis.cc

CMakeFiles/five_colors.dir/five_color_shortest_dis.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/five_colors.dir/five_color_shortest_dis.cc.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/linghutf/20160820/five_color_shortest_dis.cc > CMakeFiles/five_colors.dir/five_color_shortest_dis.cc.i

CMakeFiles/five_colors.dir/five_color_shortest_dis.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/five_colors.dir/five_color_shortest_dis.cc.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/linghutf/20160820/five_color_shortest_dis.cc -o CMakeFiles/five_colors.dir/five_color_shortest_dis.cc.s

CMakeFiles/five_colors.dir/five_color_shortest_dis.cc.o.requires:

.PHONY : CMakeFiles/five_colors.dir/five_color_shortest_dis.cc.o.requires

CMakeFiles/five_colors.dir/five_color_shortest_dis.cc.o.provides: CMakeFiles/five_colors.dir/five_color_shortest_dis.cc.o.requires
	$(MAKE) -f CMakeFiles/five_colors.dir/build.make CMakeFiles/five_colors.dir/five_color_shortest_dis.cc.o.provides.build
.PHONY : CMakeFiles/five_colors.dir/five_color_shortest_dis.cc.o.provides

CMakeFiles/five_colors.dir/five_color_shortest_dis.cc.o.provides.build: CMakeFiles/five_colors.dir/five_color_shortest_dis.cc.o


# Object files for target five_colors
five_colors_OBJECTS = \
"CMakeFiles/five_colors.dir/five_color_shortest_dis.cc.o"

# External object files for target five_colors
five_colors_EXTERNAL_OBJECTS =

five_colors: CMakeFiles/five_colors.dir/five_color_shortest_dis.cc.o
five_colors: CMakeFiles/five_colors.dir/build.make
five_colors: CMakeFiles/five_colors.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/linghutf/20160820/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable five_colors"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/five_colors.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/five_colors.dir/build: five_colors

.PHONY : CMakeFiles/five_colors.dir/build

CMakeFiles/five_colors.dir/requires: CMakeFiles/five_colors.dir/five_color_shortest_dis.cc.o.requires

.PHONY : CMakeFiles/five_colors.dir/requires

CMakeFiles/five_colors.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/five_colors.dir/cmake_clean.cmake
.PHONY : CMakeFiles/five_colors.dir/clean

CMakeFiles/five_colors.dir/depend:
	cd /home/linghutf/20160820/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/linghutf/20160820 /home/linghutf/20160820 /home/linghutf/20160820/build /home/linghutf/20160820/build /home/linghutf/20160820/build/CMakeFiles/five_colors.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/five_colors.dir/depend

