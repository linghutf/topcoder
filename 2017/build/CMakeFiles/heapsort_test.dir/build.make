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
CMAKE_SOURCE_DIR = /home/linghutf/topcoder/2017

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/linghutf/topcoder/2017/build

# Include any dependencies generated for this target.
include CMakeFiles/heapsort_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/heapsort_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/heapsort_test.dir/flags.make

CMakeFiles/heapsort_test.dir/hs.cc.o: CMakeFiles/heapsort_test.dir/flags.make
CMakeFiles/heapsort_test.dir/hs.cc.o: ../hs.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/linghutf/topcoder/2017/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/heapsort_test.dir/hs.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/heapsort_test.dir/hs.cc.o -c /home/linghutf/topcoder/2017/hs.cc

CMakeFiles/heapsort_test.dir/hs.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/heapsort_test.dir/hs.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/linghutf/topcoder/2017/hs.cc > CMakeFiles/heapsort_test.dir/hs.cc.i

CMakeFiles/heapsort_test.dir/hs.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/heapsort_test.dir/hs.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/linghutf/topcoder/2017/hs.cc -o CMakeFiles/heapsort_test.dir/hs.cc.s

CMakeFiles/heapsort_test.dir/hs.cc.o.requires:

.PHONY : CMakeFiles/heapsort_test.dir/hs.cc.o.requires

CMakeFiles/heapsort_test.dir/hs.cc.o.provides: CMakeFiles/heapsort_test.dir/hs.cc.o.requires
	$(MAKE) -f CMakeFiles/heapsort_test.dir/build.make CMakeFiles/heapsort_test.dir/hs.cc.o.provides.build
.PHONY : CMakeFiles/heapsort_test.dir/hs.cc.o.provides

CMakeFiles/heapsort_test.dir/hs.cc.o.provides.build: CMakeFiles/heapsort_test.dir/hs.cc.o


# Object files for target heapsort_test
heapsort_test_OBJECTS = \
"CMakeFiles/heapsort_test.dir/hs.cc.o"

# External object files for target heapsort_test
heapsort_test_EXTERNAL_OBJECTS =

heapsort_test: CMakeFiles/heapsort_test.dir/hs.cc.o
heapsort_test: CMakeFiles/heapsort_test.dir/build.make
heapsort_test: CMakeFiles/heapsort_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/linghutf/topcoder/2017/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable heapsort_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/heapsort_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/heapsort_test.dir/build: heapsort_test

.PHONY : CMakeFiles/heapsort_test.dir/build

CMakeFiles/heapsort_test.dir/requires: CMakeFiles/heapsort_test.dir/hs.cc.o.requires

.PHONY : CMakeFiles/heapsort_test.dir/requires

CMakeFiles/heapsort_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/heapsort_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/heapsort_test.dir/clean

CMakeFiles/heapsort_test.dir/depend:
	cd /home/linghutf/topcoder/2017/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/linghutf/topcoder/2017 /home/linghutf/topcoder/2017 /home/linghutf/topcoder/2017/build /home/linghutf/topcoder/2017/build /home/linghutf/topcoder/2017/build/CMakeFiles/heapsort_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/heapsort_test.dir/depend

