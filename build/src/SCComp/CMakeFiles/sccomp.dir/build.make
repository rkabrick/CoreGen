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
include src/SCComp/CMakeFiles/sccomp.dir/depend.make

# Include the progress variables for this target.
include src/SCComp/CMakeFiles/sccomp.dir/progress.make

# Include the compile flags for this target's objects.
include src/SCComp/CMakeFiles/sccomp.dir/flags.make

src/SCComp/CMakeFiles/sccomp.dir/SCComp.cpp.o: src/SCComp/CMakeFiles/sccomp.dir/flags.make
src/SCComp/CMakeFiles/sccomp.dir/SCComp.cpp.o: ../src/SCComp/SCComp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fconlon/Documents/CoreGen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/SCComp/CMakeFiles/sccomp.dir/SCComp.cpp.o"
	cd /home/fconlon/Documents/CoreGen/build/src/SCComp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sccomp.dir/SCComp.cpp.o -c /home/fconlon/Documents/CoreGen/src/SCComp/SCComp.cpp

src/SCComp/CMakeFiles/sccomp.dir/SCComp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sccomp.dir/SCComp.cpp.i"
	cd /home/fconlon/Documents/CoreGen/build/src/SCComp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fconlon/Documents/CoreGen/src/SCComp/SCComp.cpp > CMakeFiles/sccomp.dir/SCComp.cpp.i

src/SCComp/CMakeFiles/sccomp.dir/SCComp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sccomp.dir/SCComp.cpp.s"
	cd /home/fconlon/Documents/CoreGen/build/src/SCComp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fconlon/Documents/CoreGen/src/SCComp/SCComp.cpp -o CMakeFiles/sccomp.dir/SCComp.cpp.s

src/SCComp/CMakeFiles/sccomp.dir/SCComp.cpp.o.requires:

.PHONY : src/SCComp/CMakeFiles/sccomp.dir/SCComp.cpp.o.requires

src/SCComp/CMakeFiles/sccomp.dir/SCComp.cpp.o.provides: src/SCComp/CMakeFiles/sccomp.dir/SCComp.cpp.o.requires
	$(MAKE) -f src/SCComp/CMakeFiles/sccomp.dir/build.make src/SCComp/CMakeFiles/sccomp.dir/SCComp.cpp.o.provides.build
.PHONY : src/SCComp/CMakeFiles/sccomp.dir/SCComp.cpp.o.provides

src/SCComp/CMakeFiles/sccomp.dir/SCComp.cpp.o.provides.build: src/SCComp/CMakeFiles/sccomp.dir/SCComp.cpp.o


# Object files for target sccomp
sccomp_OBJECTS = \
"CMakeFiles/sccomp.dir/SCComp.cpp.o"

# External object files for target sccomp
sccomp_EXTERNAL_OBJECTS =

src/SCComp/sccomp: src/SCComp/CMakeFiles/sccomp.dir/SCComp.cpp.o
src/SCComp/sccomp: src/SCComp/CMakeFiles/sccomp.dir/build.make
src/SCComp/sccomp: src/StoneCutter/libSCComp.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMMCJIT.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMipo.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMIRReader.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMAsmParser.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMLinker.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMExecutionEngine.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMRuntimeDyld.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMInstrumentation.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMVectorize.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMX86CodeGen.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMAArch64CodeGen.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMARMCodeGen.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMGlobalISel.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMMipsCodeGen.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMPowerPCCodeGen.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMAsmPrinter.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMDebugInfoCodeView.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMDebugInfoMSF.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMSelectionDAG.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMCodeGen.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMScalarOpts.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMInstCombine.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMTransformUtils.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMBitWriter.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMTarget.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMAnalysis.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMProfileData.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMX86AsmParser.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMX86Desc.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMObject.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMBitReader.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMX86AsmPrinter.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMX86Utils.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMCore.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMBinaryFormat.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMX86Info.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMAArch64AsmParser.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMAArch64Desc.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMAArch64AsmPrinter.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMAArch64Info.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMAArch64Utils.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMARMAsmParser.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMARMDesc.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMARMAsmPrinter.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMMCDisassembler.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMARMInfo.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMARMUtils.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMMipsAsmParser.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMMipsDesc.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMMipsAsmPrinter.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMMipsInfo.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMPowerPCAsmParser.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMPowerPCDesc.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMPowerPCAsmPrinter.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMPowerPCInfo.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMMCParser.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMMC.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMSupport.a
src/SCComp/sccomp: /usr/lib/llvm-6.0/lib/libLLVMDemangle.a
src/SCComp/sccomp: src/CoreGenSigMap/libCoreGenSigMap.a
src/SCComp/sccomp: src/thirdparty/yaml/yaml-cpp-0.6.2/libyaml-cpp.a
src/SCComp/sccomp: src/SCComp/CMakeFiles/sccomp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fconlon/Documents/CoreGen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sccomp"
	cd /home/fconlon/Documents/CoreGen/build/src/SCComp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sccomp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/SCComp/CMakeFiles/sccomp.dir/build: src/SCComp/sccomp

.PHONY : src/SCComp/CMakeFiles/sccomp.dir/build

src/SCComp/CMakeFiles/sccomp.dir/requires: src/SCComp/CMakeFiles/sccomp.dir/SCComp.cpp.o.requires

.PHONY : src/SCComp/CMakeFiles/sccomp.dir/requires

src/SCComp/CMakeFiles/sccomp.dir/clean:
	cd /home/fconlon/Documents/CoreGen/build/src/SCComp && $(CMAKE_COMMAND) -P CMakeFiles/sccomp.dir/cmake_clean.cmake
.PHONY : src/SCComp/CMakeFiles/sccomp.dir/clean

src/SCComp/CMakeFiles/sccomp.dir/depend:
	cd /home/fconlon/Documents/CoreGen/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fconlon/Documents/CoreGen /home/fconlon/Documents/CoreGen/src/SCComp /home/fconlon/Documents/CoreGen/build /home/fconlon/Documents/CoreGen/build/src/SCComp /home/fconlon/Documents/CoreGen/build/src/SCComp/CMakeFiles/sccomp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/SCComp/CMakeFiles/sccomp.dir/depend

