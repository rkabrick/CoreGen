# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/fconlon/Documents/CoreGen

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fconlon/Documents/CoreGen/build

# Include any dependencies generated for this target.
include src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/depend.make

# Include the progress variables for this target.
include src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/progress.make

# Include the compile flags for this target's objects.
include src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/flags.make

src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/CoreGenPluginImpl.cpp.o: src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/flags.make
src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/CoreGenPluginImpl.cpp.o: ../src/CoreGenPlugin/CoreGenPluginImpl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fconlon/Documents/CoreGen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/CoreGenPluginImpl.cpp.o"
	cd /home/fconlon/Documents/CoreGen/build/src/CoreGenPlugin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CoreGenPluginImpl.dir/CoreGenPluginImpl.cpp.o -c /home/fconlon/Documents/CoreGen/src/CoreGenPlugin/CoreGenPluginImpl.cpp

src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/CoreGenPluginImpl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CoreGenPluginImpl.dir/CoreGenPluginImpl.cpp.i"
	cd /home/fconlon/Documents/CoreGen/build/src/CoreGenPlugin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fconlon/Documents/CoreGen/src/CoreGenPlugin/CoreGenPluginImpl.cpp > CMakeFiles/CoreGenPluginImpl.dir/CoreGenPluginImpl.cpp.i

src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/CoreGenPluginImpl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CoreGenPluginImpl.dir/CoreGenPluginImpl.cpp.s"
	cd /home/fconlon/Documents/CoreGen/build/src/CoreGenPlugin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fconlon/Documents/CoreGen/src/CoreGenPlugin/CoreGenPluginImpl.cpp -o CMakeFiles/CoreGenPluginImpl.dir/CoreGenPluginImpl.cpp.s

src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/CoreGenPluginImpl.cpp.o.requires:

.PHONY : src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/CoreGenPluginImpl.cpp.o.requires

src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/CoreGenPluginImpl.cpp.o.provides: src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/CoreGenPluginImpl.cpp.o.requires
	$(MAKE) -f src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/build.make src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/CoreGenPluginImpl.cpp.o.provides.build
.PHONY : src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/CoreGenPluginImpl.cpp.o.provides

src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/CoreGenPluginImpl.cpp.o.provides.build: src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/CoreGenPluginImpl.cpp.o


# Object files for target CoreGenPluginImpl
CoreGenPluginImpl_OBJECTS = \
"CMakeFiles/CoreGenPluginImpl.dir/CoreGenPluginImpl.cpp.o"

# External object files for target CoreGenPluginImpl
CoreGenPluginImpl_EXTERNAL_OBJECTS =

src/CoreGenPlugin/libCoreGenPluginImpl.a: src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/CoreGenPluginImpl.cpp.o
src/CoreGenPlugin/libCoreGenPluginImpl.a: src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/build.make
src/CoreGenPlugin/libCoreGenPluginImpl.a: src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fconlon/Documents/CoreGen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libCoreGenPluginImpl.a"
	cd /home/fconlon/Documents/CoreGen/build/src/CoreGenPlugin && $(CMAKE_COMMAND) -P CMakeFiles/CoreGenPluginImpl.dir/cmake_clean_target.cmake
	cd /home/fconlon/Documents/CoreGen/build/src/CoreGenPlugin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CoreGenPluginImpl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/build: src/CoreGenPlugin/libCoreGenPluginImpl.a

.PHONY : src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/build

src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/requires: src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/CoreGenPluginImpl.cpp.o.requires

.PHONY : src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/requires

src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/clean:
	cd /home/fconlon/Documents/CoreGen/build/src/CoreGenPlugin && $(CMAKE_COMMAND) -P CMakeFiles/CoreGenPluginImpl.dir/cmake_clean.cmake
.PHONY : src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/clean

src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/depend:
	cd /home/fconlon/Documents/CoreGen/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fconlon/Documents/CoreGen /home/fconlon/Documents/CoreGen/src/CoreGenPlugin /home/fconlon/Documents/CoreGen/build /home/fconlon/Documents/CoreGen/build/src/CoreGenPlugin /home/fconlon/Documents/CoreGen/build/src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CoreGenPlugin/CMakeFiles/CoreGenPluginImpl.dir/depend

