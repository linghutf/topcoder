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
include CMakeFiles/fifa.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fifa.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fifa.dir/flags.make

CMakeFiles/fifa.dir/fifa.cc.o: CMakeFiles/fifa.dir/flags.make
CMakeFiles/fifa.dir/fifa.cc.o: ../fifa.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/linghutf/20160820/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fifa.dir/fifa.cc.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fifa.dir/fifa.cc.o -c /home/linghutf/20160820/fifa.cc

CMakeFiles/fifa.dir/fifa.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fifa.dir/fifa.cc.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/linghutf/20160820/fifa.cc > CMakeFiles/fifa.dir/fifa.cc.i

CMakeFiles/fifa.dir/fifa.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fifa.dir/fifa.cc.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/linghutf/20160820/fifa.cc -o CMakeFiles/fifa.dir/fifa.cc.s

CMakeFiles/fifa.dir/fifa.cc.o.requires:

.PHONY : CMakeFiles/fifa.dir/fifa.cc.o.requires

CMakeFiles/fifa.dir/fifa.cc.o.provides: CMakeFiles/fifa.dir/fifa.cc.o.requires
	$(MAKE) -f CMakeFiles/fifa.dir/build.make CMakeFiles/fifa.dir/fifa.cc.o.provides.build
.PHONY : CMakeFiles/fifa.dir/fifa.cc.o.provides

CMakeFiles/fifa.dir/fifa.cc.o.provides.build: CMakeFiles/fifa.dir/fifa.cc.o


# Object files for target fifa
fifa_OBJECTS = \
"CMakeFiles/fifa.dir/fifa.cc.o"

# External object files for target fifa
fifa_EXTERNAL_OBJECTS =

fifa: CMakeFiles/fifa.dir/fifa.cc.o
fifa: CMakeFiles/fifa.dir/build.make
fifa: CMakeFiles/fifa.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/linghutf/20160820/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable fifa"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fifa.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fifa.dir/build: fifa

.PHONY : CMakeFiles/fifa.dir/build

CMakeFiles/fifa.dir/requires: CMakeFiles/fifa.dir/fifa.cc.o.requires

.PHONY : CMakeFiles/fifa.dir/requires

CMakeFiles/fifa.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fifa.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fifa.dir/clean

CMakeFiles/fifa.dir/depend:
	cd /home/linghutf/20160820/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/linghutf/20160820 /home/linghutf/20160820 /home/linghutf/20160820/build /home/linghutf/20160820/build /home/linghutf/20160820/build/CMakeFiles/fifa.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fifa.dir/depend

