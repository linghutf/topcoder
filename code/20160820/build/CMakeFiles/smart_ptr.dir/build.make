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
include CMakeFiles/smart_ptr.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/smart_ptr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/smart_ptr.dir/flags.make

CMakeFiles/smart_ptr.dir/test_sp.cc.o: CMakeFiles/smart_ptr.dir/flags.make
CMakeFiles/smart_ptr.dir/test_sp.cc.o: ../test_sp.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/linghutf/20160820/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/smart_ptr.dir/test_sp.cc.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/smart_ptr.dir/test_sp.cc.o -c /home/linghutf/20160820/test_sp.cc

CMakeFiles/smart_ptr.dir/test_sp.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smart_ptr.dir/test_sp.cc.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/linghutf/20160820/test_sp.cc > CMakeFiles/smart_ptr.dir/test_sp.cc.i

CMakeFiles/smart_ptr.dir/test_sp.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smart_ptr.dir/test_sp.cc.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/linghutf/20160820/test_sp.cc -o CMakeFiles/smart_ptr.dir/test_sp.cc.s

CMakeFiles/smart_ptr.dir/test_sp.cc.o.requires:

.PHONY : CMakeFiles/smart_ptr.dir/test_sp.cc.o.requires

CMakeFiles/smart_ptr.dir/test_sp.cc.o.provides: CMakeFiles/smart_ptr.dir/test_sp.cc.o.requires
	$(MAKE) -f CMakeFiles/smart_ptr.dir/build.make CMakeFiles/smart_ptr.dir/test_sp.cc.o.provides.build
.PHONY : CMakeFiles/smart_ptr.dir/test_sp.cc.o.provides

CMakeFiles/smart_ptr.dir/test_sp.cc.o.provides.build: CMakeFiles/smart_ptr.dir/test_sp.cc.o


# Object files for target smart_ptr
smart_ptr_OBJECTS = \
"CMakeFiles/smart_ptr.dir/test_sp.cc.o"

# External object files for target smart_ptr
smart_ptr_EXTERNAL_OBJECTS =

smart_ptr: CMakeFiles/smart_ptr.dir/test_sp.cc.o
smart_ptr: CMakeFiles/smart_ptr.dir/build.make
smart_ptr: CMakeFiles/smart_ptr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/linghutf/20160820/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable smart_ptr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/smart_ptr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/smart_ptr.dir/build: smart_ptr

.PHONY : CMakeFiles/smart_ptr.dir/build

CMakeFiles/smart_ptr.dir/requires: CMakeFiles/smart_ptr.dir/test_sp.cc.o.requires

.PHONY : CMakeFiles/smart_ptr.dir/requires

CMakeFiles/smart_ptr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/smart_ptr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/smart_ptr.dir/clean

CMakeFiles/smart_ptr.dir/depend:
	cd /home/linghutf/20160820/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/linghutf/20160820 /home/linghutf/20160820 /home/linghutf/20160820/build /home/linghutf/20160820/build /home/linghutf/20160820/build/CMakeFiles/smart_ptr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/smart_ptr.dir/depend

