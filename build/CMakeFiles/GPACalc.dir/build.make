# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/dev/gpa_calc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/dev/gpa_calc/build

# Include any dependencies generated for this target.
include CMakeFiles/GPACalc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/GPACalc.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GPACalc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GPACalc.dir/flags.make

CMakeFiles/GPACalc.dir/src/main.cpp.o: CMakeFiles/GPACalc.dir/flags.make
CMakeFiles/GPACalc.dir/src/main.cpp.o: /root/dev/gpa_calc/src/main.cpp
CMakeFiles/GPACalc.dir/src/main.cpp.o: CMakeFiles/GPACalc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/root/dev/gpa_calc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GPACalc.dir/src/main.cpp.o"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GPACalc.dir/src/main.cpp.o -MF CMakeFiles/GPACalc.dir/src/main.cpp.o.d -o CMakeFiles/GPACalc.dir/src/main.cpp.o -c /root/dev/gpa_calc/src/main.cpp

CMakeFiles/GPACalc.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GPACalc.dir/src/main.cpp.i"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/dev/gpa_calc/src/main.cpp > CMakeFiles/GPACalc.dir/src/main.cpp.i

CMakeFiles/GPACalc.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GPACalc.dir/src/main.cpp.s"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/dev/gpa_calc/src/main.cpp -o CMakeFiles/GPACalc.dir/src/main.cpp.s

# Object files for target GPACalc
GPACalc_OBJECTS = \
"CMakeFiles/GPACalc.dir/src/main.cpp.o"

# External object files for target GPACalc
GPACalc_EXTERNAL_OBJECTS =

GPACalc: CMakeFiles/GPACalc.dir/src/main.cpp.o
GPACalc: CMakeFiles/GPACalc.dir/build.make
GPACalc: CMakeFiles/GPACalc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/root/dev/gpa_calc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GPACalc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GPACalc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GPACalc.dir/build: GPACalc
.PHONY : CMakeFiles/GPACalc.dir/build

CMakeFiles/GPACalc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GPACalc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GPACalc.dir/clean

CMakeFiles/GPACalc.dir/depend:
	cd /root/dev/gpa_calc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/dev/gpa_calc /root/dev/gpa_calc /root/dev/gpa_calc/build /root/dev/gpa_calc/build /root/dev/gpa_calc/build/CMakeFiles/GPACalc.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/GPACalc.dir/depend

