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
include CMakeFiles/endian.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/endian.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/endian.dir/flags.make

CMakeFiles/endian.dir/endian.c.o: CMakeFiles/endian.dir/flags.make
CMakeFiles/endian.dir/endian.c.o: ../endian.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/linghutf/topcoder/2017/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/endian.dir/endian.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/endian.dir/endian.c.o   -c /home/linghutf/topcoder/2017/endian.c

CMakeFiles/endian.dir/endian.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/endian.dir/endian.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/linghutf/topcoder/2017/endian.c > CMakeFiles/endian.dir/endian.c.i

CMakeFiles/endian.dir/endian.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/endian.dir/endian.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/linghutf/topcoder/2017/endian.c -o CMakeFiles/endian.dir/endian.c.s

CMakeFiles/endian.dir/endian.c.o.requires:

.PHONY : CMakeFiles/endian.dir/endian.c.o.requires

CMakeFiles/endian.dir/endian.c.o.provides: CMakeFiles/endian.dir/endian.c.o.requires
	$(MAKE) -f CMakeFiles/endian.dir/build.make CMakeFiles/endian.dir/endian.c.o.provides.build
.PHONY : CMakeFiles/endian.dir/endian.c.o.provides

CMakeFiles/endian.dir/endian.c.o.provides.build: CMakeFiles/endian.dir/endian.c.o


# Object files for target endian
endian_OBJECTS = \
"CMakeFiles/endian.dir/endian.c.o"

# External object files for target endian
endian_EXTERNAL_OBJECTS =

endian: CMakeFiles/endian.dir/endian.c.o
endian: CMakeFiles/endian.dir/build.make
endian: CMakeFiles/endian.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/linghutf/topcoder/2017/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable endian"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/endian.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/endian.dir/build: endian

.PHONY : CMakeFiles/endian.dir/build

CMakeFiles/endian.dir/requires: CMakeFiles/endian.dir/endian.c.o.requires

.PHONY : CMakeFiles/endian.dir/requires

CMakeFiles/endian.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/endian.dir/cmake_clean.cmake
.PHONY : CMakeFiles/endian.dir/clean

CMakeFiles/endian.dir/depend:
	cd /home/linghutf/topcoder/2017/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/linghutf/topcoder/2017 /home/linghutf/topcoder/2017 /home/linghutf/topcoder/2017/build /home/linghutf/topcoder/2017/build /home/linghutf/topcoder/2017/build/CMakeFiles/endian.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/endian.dir/depend

