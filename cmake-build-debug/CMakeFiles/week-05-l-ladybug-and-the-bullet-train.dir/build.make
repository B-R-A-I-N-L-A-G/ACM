# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/ntb/codeforces/ACM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ntb/codeforces/ACM/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/flags.make

CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/week-05/l-ladybug-and-the-bullet-train/main.cpp.o: CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/flags.make
CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/week-05/l-ladybug-and-the-bullet-train/main.cpp.o: ../week-05/l-ladybug-and-the-bullet-train/main.cpp
CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/week-05/l-ladybug-and-the-bullet-train/main.cpp.o: CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ntb/codeforces/ACM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/week-05/l-ladybug-and-the-bullet-train/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/week-05/l-ladybug-and-the-bullet-train/main.cpp.o -MF CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/week-05/l-ladybug-and-the-bullet-train/main.cpp.o.d -o CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/week-05/l-ladybug-and-the-bullet-train/main.cpp.o -c /home/ntb/codeforces/ACM/week-05/l-ladybug-and-the-bullet-train/main.cpp

CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/week-05/l-ladybug-and-the-bullet-train/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/week-05/l-ladybug-and-the-bullet-train/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ntb/codeforces/ACM/week-05/l-ladybug-and-the-bullet-train/main.cpp > CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/week-05/l-ladybug-and-the-bullet-train/main.cpp.i

CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/week-05/l-ladybug-and-the-bullet-train/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/week-05/l-ladybug-and-the-bullet-train/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ntb/codeforces/ACM/week-05/l-ladybug-and-the-bullet-train/main.cpp -o CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/week-05/l-ladybug-and-the-bullet-train/main.cpp.s

# Object files for target week-05-l-ladybug-and-the-bullet-train
week__05__l__ladybug__and__the__bullet__train_OBJECTS = \
"CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/week-05/l-ladybug-and-the-bullet-train/main.cpp.o"

# External object files for target week-05-l-ladybug-and-the-bullet-train
week__05__l__ladybug__and__the__bullet__train_EXTERNAL_OBJECTS =

week-05-l-ladybug-and-the-bullet-train: CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/week-05/l-ladybug-and-the-bullet-train/main.cpp.o
week-05-l-ladybug-and-the-bullet-train: CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/build.make
week-05-l-ladybug-and-the-bullet-train: CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ntb/codeforces/ACM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable week-05-l-ladybug-and-the-bullet-train"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/build: week-05-l-ladybug-and-the-bullet-train
.PHONY : CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/build

CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/cmake_clean.cmake
.PHONY : CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/clean

CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/depend:
	cd /home/ntb/codeforces/ACM/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ntb/codeforces/ACM /home/ntb/codeforces/ACM /home/ntb/codeforces/ACM/cmake-build-debug /home/ntb/codeforces/ACM/cmake-build-debug /home/ntb/codeforces/ACM/cmake-build-debug/CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/week-05-l-ladybug-and-the-bullet-train.dir/depend

