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
include CMakeFiles/regex_test_std.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/regex_test_std.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/regex_test_std.dir/flags.make

CMakeFiles/regex_test_std.dir/regex_test_std.cc.o: CMakeFiles/regex_test_std.dir/flags.make
CMakeFiles/regex_test_std.dir/regex_test_std.cc.o: ../regex_test_std.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/linghutf/20160820/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/regex_test_std.dir/regex_test_std.cc.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/regex_test_std.dir/regex_test_std.cc.o -c /home/linghutf/20160820/regex_test_std.cc

CMakeFiles/regex_test_std.dir/regex_test_std.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/regex_test_std.dir/regex_test_std.cc.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/linghutf/20160820/regex_test_std.cc > CMakeFiles/regex_test_std.dir/regex_test_std.cc.i

CMakeFiles/regex_test_std.dir/regex_test_std.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/regex_test_std.dir/regex_test_std.cc.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/linghutf/20160820/regex_test_std.cc -o CMakeFiles/regex_test_std.dir/regex_test_std.cc.s

CMakeFiles/regex_test_std.dir/regex_test_std.cc.o.requires:

.PHONY : CMakeFiles/regex_test_std.dir/regex_test_std.cc.o.requires

CMakeFiles/regex_test_std.dir/regex_test_std.cc.o.provides: CMakeFiles/regex_test_std.dir/regex_test_std.cc.o.requires
	$(MAKE) -f CMakeFiles/regex_test_std.dir/build.make CMakeFiles/regex_test_std.dir/regex_test_std.cc.o.provides.build
.PHONY : CMakeFiles/regex_test_std.dir/regex_test_std.cc.o.provides

CMakeFiles/regex_test_std.dir/regex_test_std.cc.o.provides.build: CMakeFiles/regex_test_std.dir/regex_test_std.cc.o


# Object files for target regex_test_std
regex_test_std_OBJECTS = \
"CMakeFiles/regex_test_std.dir/regex_test_std.cc.o"

# External object files for target regex_test_std
regex_test_std_EXTERNAL_OBJECTS =

regex_test_std: CMakeFiles/regex_test_std.dir/regex_test_std.cc.o
regex_test_std: CMakeFiles/regex_test_std.dir/build.make
regex_test_std: CMakeFiles/regex_test_std.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/linghutf/20160820/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable regex_test_std"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/regex_test_std.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/regex_test_std.dir/build: regex_test_std

.PHONY : CMakeFiles/regex_test_std.dir/build

CMakeFiles/regex_test_std.dir/requires: CMakeFiles/regex_test_std.dir/regex_test_std.cc.o.requires

.PHONY : CMakeFiles/regex_test_std.dir/requires

CMakeFiles/regex_test_std.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/regex_test_std.dir/cmake_clean.cmake
.PHONY : CMakeFiles/regex_test_std.dir/clean

CMakeFiles/regex_test_std.dir/depend:
	cd /home/linghutf/20160820/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/linghutf/20160820 /home/linghutf/20160820 /home/linghutf/20160820/build /home/linghutf/20160820/build /home/linghutf/20160820/build/CMakeFiles/regex_test_std.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/regex_test_std.dir/depend

