# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gdoge/philosophers/philo_one

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gdoge/philosophers/philo_one/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/philo_one.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/philo_one.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/philo_one.dir/flags.make

CMakeFiles/philo_one.dir/main.c.o: CMakeFiles/philo_one.dir/flags.make
CMakeFiles/philo_one.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gdoge/philosophers/philo_one/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/philo_one.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one.dir/main.c.o   -c /Users/gdoge/philosophers/philo_one/main.c

CMakeFiles/philo_one.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gdoge/philosophers/philo_one/main.c > CMakeFiles/philo_one.dir/main.c.i

CMakeFiles/philo_one.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gdoge/philosophers/philo_one/main.c -o CMakeFiles/philo_one.dir/main.c.s

CMakeFiles/philo_one.dir/get_and_validate_input_data.c.o: CMakeFiles/philo_one.dir/flags.make
CMakeFiles/philo_one.dir/get_and_validate_input_data.c.o: ../get_and_validate_input_data.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gdoge/philosophers/philo_one/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/philo_one.dir/get_and_validate_input_data.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one.dir/get_and_validate_input_data.c.o   -c /Users/gdoge/philosophers/philo_one/get_and_validate_input_data.c

CMakeFiles/philo_one.dir/get_and_validate_input_data.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one.dir/get_and_validate_input_data.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gdoge/philosophers/philo_one/get_and_validate_input_data.c > CMakeFiles/philo_one.dir/get_and_validate_input_data.c.i

CMakeFiles/philo_one.dir/get_and_validate_input_data.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one.dir/get_and_validate_input_data.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gdoge/philosophers/philo_one/get_and_validate_input_data.c -o CMakeFiles/philo_one.dir/get_and_validate_input_data.c.s

CMakeFiles/philo_one.dir/initial_mutex_creation.c.o: CMakeFiles/philo_one.dir/flags.make
CMakeFiles/philo_one.dir/initial_mutex_creation.c.o: ../initial_mutex_creation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gdoge/philosophers/philo_one/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/philo_one.dir/initial_mutex_creation.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one.dir/initial_mutex_creation.c.o   -c /Users/gdoge/philosophers/philo_one/initial_mutex_creation.c

CMakeFiles/philo_one.dir/initial_mutex_creation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one.dir/initial_mutex_creation.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gdoge/philosophers/philo_one/initial_mutex_creation.c > CMakeFiles/philo_one.dir/initial_mutex_creation.c.i

CMakeFiles/philo_one.dir/initial_mutex_creation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one.dir/initial_mutex_creation.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gdoge/philosophers/philo_one/initial_mutex_creation.c -o CMakeFiles/philo_one.dir/initial_mutex_creation.c.s

CMakeFiles/philo_one.dir/passing_time_mutex_creation.c.o: CMakeFiles/philo_one.dir/flags.make
CMakeFiles/philo_one.dir/passing_time_mutex_creation.c.o: ../passing_time_mutex_creation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gdoge/philosophers/philo_one/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/philo_one.dir/passing_time_mutex_creation.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one.dir/passing_time_mutex_creation.c.o   -c /Users/gdoge/philosophers/philo_one/passing_time_mutex_creation.c

CMakeFiles/philo_one.dir/passing_time_mutex_creation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one.dir/passing_time_mutex_creation.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gdoge/philosophers/philo_one/passing_time_mutex_creation.c > CMakeFiles/philo_one.dir/passing_time_mutex_creation.c.i

CMakeFiles/philo_one.dir/passing_time_mutex_creation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one.dir/passing_time_mutex_creation.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gdoge/philosophers/philo_one/passing_time_mutex_creation.c -o CMakeFiles/philo_one.dir/passing_time_mutex_creation.c.s

CMakeFiles/philo_one.dir/time_handling.c.o: CMakeFiles/philo_one.dir/flags.make
CMakeFiles/philo_one.dir/time_handling.c.o: ../time_handling.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gdoge/philosophers/philo_one/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/philo_one.dir/time_handling.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one.dir/time_handling.c.o   -c /Users/gdoge/philosophers/philo_one/time_handling.c

CMakeFiles/philo_one.dir/time_handling.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one.dir/time_handling.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gdoge/philosophers/philo_one/time_handling.c > CMakeFiles/philo_one.dir/time_handling.c.i

CMakeFiles/philo_one.dir/time_handling.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one.dir/time_handling.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gdoge/philosophers/philo_one/time_handling.c -o CMakeFiles/philo_one.dir/time_handling.c.s

# Object files for target philo_one
philo_one_OBJECTS = \
"CMakeFiles/philo_one.dir/main.c.o" \
"CMakeFiles/philo_one.dir/get_and_validate_input_data.c.o" \
"CMakeFiles/philo_one.dir/initial_mutex_creation.c.o" \
"CMakeFiles/philo_one.dir/passing_time_mutex_creation.c.o" \
"CMakeFiles/philo_one.dir/time_handling.c.o"

# External object files for target philo_one
philo_one_EXTERNAL_OBJECTS =

philo_one: CMakeFiles/philo_one.dir/main.c.o
philo_one: CMakeFiles/philo_one.dir/get_and_validate_input_data.c.o
philo_one: CMakeFiles/philo_one.dir/initial_mutex_creation.c.o
philo_one: CMakeFiles/philo_one.dir/passing_time_mutex_creation.c.o
philo_one: CMakeFiles/philo_one.dir/time_handling.c.o
philo_one: CMakeFiles/philo_one.dir/build.make
philo_one: CMakeFiles/philo_one.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gdoge/philosophers/philo_one/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable philo_one"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/philo_one.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/philo_one.dir/build: philo_one

.PHONY : CMakeFiles/philo_one.dir/build

CMakeFiles/philo_one.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/philo_one.dir/cmake_clean.cmake
.PHONY : CMakeFiles/philo_one.dir/clean

CMakeFiles/philo_one.dir/depend:
	cd /Users/gdoge/philosophers/philo_one/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gdoge/philosophers/philo_one /Users/gdoge/philosophers/philo_one /Users/gdoge/philosophers/philo_one/cmake-build-debug /Users/gdoge/philosophers/philo_one/cmake-build-debug /Users/gdoge/philosophers/philo_one/cmake-build-debug/CMakeFiles/philo_one.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/philo_one.dir/depend

