# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /home/hussein/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/211.7142.21/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/hussein/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/211.7142.21/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/CLionProjects/round-robin-scheduling

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/CLionProjects/round-robin-scheduling/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/round_robin_scheduling.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/round_robin_scheduling.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/round_robin_scheduling.dir/flags.make

CMakeFiles/round_robin_scheduling.dir/Queue.c.o: CMakeFiles/round_robin_scheduling.dir/flags.make
CMakeFiles/round_robin_scheduling.dir/Queue.c.o: ../Queue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/CLionProjects/round-robin-scheduling/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/round_robin_scheduling.dir/Queue.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/round_robin_scheduling.dir/Queue.c.o -c /mnt/d/CLionProjects/round-robin-scheduling/Queue.c

CMakeFiles/round_robin_scheduling.dir/Queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/round_robin_scheduling.dir/Queue.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/CLionProjects/round-robin-scheduling/Queue.c > CMakeFiles/round_robin_scheduling.dir/Queue.c.i

CMakeFiles/round_robin_scheduling.dir/Queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/round_robin_scheduling.dir/Queue.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/CLionProjects/round-robin-scheduling/Queue.c -o CMakeFiles/round_robin_scheduling.dir/Queue.c.s

# Object files for target round_robin_scheduling
round_robin_scheduling_OBJECTS = \
"CMakeFiles/round_robin_scheduling.dir/Queue.c.o"

# External object files for target round_robin_scheduling
round_robin_scheduling_EXTERNAL_OBJECTS =

round_robin_scheduling: CMakeFiles/round_robin_scheduling.dir/Queue.c.o
round_robin_scheduling: CMakeFiles/round_robin_scheduling.dir/build.make
round_robin_scheduling: CMakeFiles/round_robin_scheduling.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/CLionProjects/round-robin-scheduling/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable round_robin_scheduling"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/round_robin_scheduling.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/round_robin_scheduling.dir/build: round_robin_scheduling

.PHONY : CMakeFiles/round_robin_scheduling.dir/build

CMakeFiles/round_robin_scheduling.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/round_robin_scheduling.dir/cmake_clean.cmake
.PHONY : CMakeFiles/round_robin_scheduling.dir/clean

CMakeFiles/round_robin_scheduling.dir/depend:
	cd /mnt/d/CLionProjects/round-robin-scheduling/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/CLionProjects/round-robin-scheduling /mnt/d/CLionProjects/round-robin-scheduling /mnt/d/CLionProjects/round-robin-scheduling/cmake-build-debug /mnt/d/CLionProjects/round-robin-scheduling/cmake-build-debug /mnt/d/CLionProjects/round-robin-scheduling/cmake-build-debug/CMakeFiles/round_robin_scheduling.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/round_robin_scheduling.dir/depend

