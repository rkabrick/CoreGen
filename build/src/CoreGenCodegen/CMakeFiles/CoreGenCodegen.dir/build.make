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
include src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/depend.make

# Include the progress variables for this target.
include src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/progress.make

# Include the compile flags for this target's objects.
include src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/flags.make

src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenCodegen.cpp.o: src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/flags.make
src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenCodegen.cpp.o: ../src/CoreGenCodegen/CoreGenCodegen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fconlon/Documents/CoreGen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenCodegen.cpp.o"
	cd /home/fconlon/Documents/CoreGen/build/src/CoreGenCodegen && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CoreGenCodegen.dir/CoreGenCodegen.cpp.o -c /home/fconlon/Documents/CoreGen/src/CoreGenCodegen/CoreGenCodegen.cpp

src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenCodegen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CoreGenCodegen.dir/CoreGenCodegen.cpp.i"
	cd /home/fconlon/Documents/CoreGen/build/src/CoreGenCodegen && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fconlon/Documents/CoreGen/src/CoreGenCodegen/CoreGenCodegen.cpp > CMakeFiles/CoreGenCodegen.dir/CoreGenCodegen.cpp.i

src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenCodegen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CoreGenCodegen.dir/CoreGenCodegen.cpp.s"
	cd /home/fconlon/Documents/CoreGen/build/src/CoreGenCodegen && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fconlon/Documents/CoreGen/src/CoreGenCodegen/CoreGenCodegen.cpp -o CMakeFiles/CoreGenCodegen.dir/CoreGenCodegen.cpp.s

src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenCodegen.cpp.o.requires:

.PHONY : src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenCodegen.cpp.o.requires

src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenCodegen.cpp.o.provides: src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenCodegen.cpp.o.requires
	$(MAKE) -f src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/build.make src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenCodegen.cpp.o.provides.build
.PHONY : src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenCodegen.cpp.o.provides

src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenCodegen.cpp.o.provides.build: src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenCodegen.cpp.o


src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenChiselCodegen.cpp.o: src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/flags.make
src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenChiselCodegen.cpp.o: ../src/CoreGenCodegen/CoreGenChiselCodegen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fconlon/Documents/CoreGen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenChiselCodegen.cpp.o"
	cd /home/fconlon/Documents/CoreGen/build/src/CoreGenCodegen && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CoreGenCodegen.dir/CoreGenChiselCodegen.cpp.o -c /home/fconlon/Documents/CoreGen/src/CoreGenCodegen/CoreGenChiselCodegen.cpp

src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenChiselCodegen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CoreGenCodegen.dir/CoreGenChiselCodegen.cpp.i"
	cd /home/fconlon/Documents/CoreGen/build/src/CoreGenCodegen && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fconlon/Documents/CoreGen/src/CoreGenCodegen/CoreGenChiselCodegen.cpp > CMakeFiles/CoreGenCodegen.dir/CoreGenChiselCodegen.cpp.i

src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenChiselCodegen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CoreGenCodegen.dir/CoreGenChiselCodegen.cpp.s"
	cd /home/fconlon/Documents/CoreGen/build/src/CoreGenCodegen && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fconlon/Documents/CoreGen/src/CoreGenCodegen/CoreGenChiselCodegen.cpp -o CMakeFiles/CoreGenCodegen.dir/CoreGenChiselCodegen.cpp.s

src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenChiselCodegen.cpp.o.requires:

.PHONY : src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenChiselCodegen.cpp.o.requires

src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenChiselCodegen.cpp.o.provides: src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenChiselCodegen.cpp.o.requires
	$(MAKE) -f src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/build.make src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenChiselCodegen.cpp.o.provides.build
.PHONY : src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenChiselCodegen.cpp.o.provides

src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenChiselCodegen.cpp.o.provides.build: src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenChiselCodegen.cpp.o


src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenLLVMCodegen.cpp.o: src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/flags.make
src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenLLVMCodegen.cpp.o: ../src/CoreGenCodegen/CoreGenLLVMCodegen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fconlon/Documents/CoreGen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenLLVMCodegen.cpp.o"
	cd /home/fconlon/Documents/CoreGen/build/src/CoreGenCodegen && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CoreGenCodegen.dir/CoreGenLLVMCodegen.cpp.o -c /home/fconlon/Documents/CoreGen/src/CoreGenCodegen/CoreGenLLVMCodegen.cpp

src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenLLVMCodegen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CoreGenCodegen.dir/CoreGenLLVMCodegen.cpp.i"
	cd /home/fconlon/Documents/CoreGen/build/src/CoreGenCodegen && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fconlon/Documents/CoreGen/src/CoreGenCodegen/CoreGenLLVMCodegen.cpp > CMakeFiles/CoreGenCodegen.dir/CoreGenLLVMCodegen.cpp.i

src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenLLVMCodegen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CoreGenCodegen.dir/CoreGenLLVMCodegen.cpp.s"
	cd /home/fconlon/Documents/CoreGen/build/src/CoreGenCodegen && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fconlon/Documents/CoreGen/src/CoreGenCodegen/CoreGenLLVMCodegen.cpp -o CMakeFiles/CoreGenCodegen.dir/CoreGenLLVMCodegen.cpp.s

src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenLLVMCodegen.cpp.o.requires:

.PHONY : src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenLLVMCodegen.cpp.o.requires

src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenLLVMCodegen.cpp.o.provides: src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenLLVMCodegen.cpp.o.requires
	$(MAKE) -f src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/build.make src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenLLVMCodegen.cpp.o.provides.build
.PHONY : src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenLLVMCodegen.cpp.o.provides

src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenLLVMCodegen.cpp.o.provides.build: src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenLLVMCodegen.cpp.o


src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenNodeCodegen.cpp.o: src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/flags.make
src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenNodeCodegen.cpp.o: ../src/CoreGenCodegen/CoreGenNodeCodegen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fconlon/Documents/CoreGen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenNodeCodegen.cpp.o"
	cd /home/fconlon/Documents/CoreGen/build/src/CoreGenCodegen && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CoreGenCodegen.dir/CoreGenNodeCodegen.cpp.o -c /home/fconlon/Documents/CoreGen/src/CoreGenCodegen/CoreGenNodeCodegen.cpp

src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenNodeCodegen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CoreGenCodegen.dir/CoreGenNodeCodegen.cpp.i"
	cd /home/fconlon/Documents/CoreGen/build/src/CoreGenCodegen && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fconlon/Documents/CoreGen/src/CoreGenCodegen/CoreGenNodeCodegen.cpp > CMakeFiles/CoreGenCodegen.dir/CoreGenNodeCodegen.cpp.i

src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenNodeCodegen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CoreGenCodegen.dir/CoreGenNodeCodegen.cpp.s"
	cd /home/fconlon/Documents/CoreGen/build/src/CoreGenCodegen && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fconlon/Documents/CoreGen/src/CoreGenCodegen/CoreGenNodeCodegen.cpp -o CMakeFiles/CoreGenCodegen.dir/CoreGenNodeCodegen.cpp.s

src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenNodeCodegen.cpp.o.requires:

.PHONY : src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenNodeCodegen.cpp.o.requires

src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenNodeCodegen.cpp.o.provides: src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenNodeCodegen.cpp.o.requires
	$(MAKE) -f src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/build.make src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenNodeCodegen.cpp.o.provides.build
.PHONY : src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenNodeCodegen.cpp.o.provides

src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenNodeCodegen.cpp.o.provides.build: src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenNodeCodegen.cpp.o


# Object files for target CoreGenCodegen
CoreGenCodegen_OBJECTS = \
"CMakeFiles/CoreGenCodegen.dir/CoreGenCodegen.cpp.o" \
"CMakeFiles/CoreGenCodegen.dir/CoreGenChiselCodegen.cpp.o" \
"CMakeFiles/CoreGenCodegen.dir/CoreGenLLVMCodegen.cpp.o" \
"CMakeFiles/CoreGenCodegen.dir/CoreGenNodeCodegen.cpp.o"

# External object files for target CoreGenCodegen
CoreGenCodegen_EXTERNAL_OBJECTS = \
"/home/fconlon/Documents/CoreGen/build/src/CoreGenCodegen/NodeCodegen/CMakeFiles/NodeCodegenObjs.dir/RegClassCG.cpp.o" \
"/home/fconlon/Documents/CoreGen/build/src/CoreGenCodegen/NodeCodegen/CMakeFiles/NodeCodegenObjs.dir/SpadCG.cpp.o" \
"/home/fconlon/Documents/CoreGen/build/src/CoreGenCodegen/NodeCodegen/CMakeFiles/NodeCodegenObjs.dir/SocCG.cpp.o" \
"/home/fconlon/Documents/CoreGen/build/src/CoreGenCodegen/NodeCodegen/CMakeFiles/NodeCodegenObjs.dir/ISACG.cpp.o"

src/CoreGenCodegen/libCoreGenCodegen.a: src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenCodegen.cpp.o
src/CoreGenCodegen/libCoreGenCodegen.a: src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenChiselCodegen.cpp.o
src/CoreGenCodegen/libCoreGenCodegen.a: src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenLLVMCodegen.cpp.o
src/CoreGenCodegen/libCoreGenCodegen.a: src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenNodeCodegen.cpp.o
src/CoreGenCodegen/libCoreGenCodegen.a: src/CoreGenCodegen/NodeCodegen/CMakeFiles/NodeCodegenObjs.dir/RegClassCG.cpp.o
src/CoreGenCodegen/libCoreGenCodegen.a: src/CoreGenCodegen/NodeCodegen/CMakeFiles/NodeCodegenObjs.dir/SpadCG.cpp.o
src/CoreGenCodegen/libCoreGenCodegen.a: src/CoreGenCodegen/NodeCodegen/CMakeFiles/NodeCodegenObjs.dir/SocCG.cpp.o
src/CoreGenCodegen/libCoreGenCodegen.a: src/CoreGenCodegen/NodeCodegen/CMakeFiles/NodeCodegenObjs.dir/ISACG.cpp.o
src/CoreGenCodegen/libCoreGenCodegen.a: src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/build.make
src/CoreGenCodegen/libCoreGenCodegen.a: src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fconlon/Documents/CoreGen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libCoreGenCodegen.a"
	cd /home/fconlon/Documents/CoreGen/build/src/CoreGenCodegen && $(CMAKE_COMMAND) -P CMakeFiles/CoreGenCodegen.dir/cmake_clean_target.cmake
	cd /home/fconlon/Documents/CoreGen/build/src/CoreGenCodegen && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CoreGenCodegen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/build: src/CoreGenCodegen/libCoreGenCodegen.a

.PHONY : src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/build

src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/requires: src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenCodegen.cpp.o.requires
src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/requires: src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenChiselCodegen.cpp.o.requires
src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/requires: src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenLLVMCodegen.cpp.o.requires
src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/requires: src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/CoreGenNodeCodegen.cpp.o.requires

.PHONY : src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/requires

src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/clean:
	cd /home/fconlon/Documents/CoreGen/build/src/CoreGenCodegen && $(CMAKE_COMMAND) -P CMakeFiles/CoreGenCodegen.dir/cmake_clean.cmake
.PHONY : src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/clean

src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/depend:
	cd /home/fconlon/Documents/CoreGen/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fconlon/Documents/CoreGen /home/fconlon/Documents/CoreGen/src/CoreGenCodegen /home/fconlon/Documents/CoreGen/build /home/fconlon/Documents/CoreGen/build/src/CoreGenCodegen /home/fconlon/Documents/CoreGen/build/src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CoreGenCodegen/CMakeFiles/CoreGenCodegen.dir/depend

