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
CMAKE_SOURCE_DIR = /home/luke/Documents/DeversiFi_Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/luke/Documents/DeversiFi_Project/build

# Include any dependencies generated for this target.
include CMakeFiles/TradingBot.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TradingBot.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TradingBot.dir/flags.make

CMakeFiles/TradingBot.dir/src/main.cpp.o: CMakeFiles/TradingBot.dir/flags.make
CMakeFiles/TradingBot.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luke/Documents/DeversiFi_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TradingBot.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TradingBot.dir/src/main.cpp.o -c /home/luke/Documents/DeversiFi_Project/src/main.cpp

CMakeFiles/TradingBot.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TradingBot.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luke/Documents/DeversiFi_Project/src/main.cpp > CMakeFiles/TradingBot.dir/src/main.cpp.i

CMakeFiles/TradingBot.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TradingBot.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luke/Documents/DeversiFi_Project/src/main.cpp -o CMakeFiles/TradingBot.dir/src/main.cpp.s

CMakeFiles/TradingBot.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/TradingBot.dir/src/main.cpp.o.requires

CMakeFiles/TradingBot.dir/src/main.cpp.o.provides: CMakeFiles/TradingBot.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/TradingBot.dir/build.make CMakeFiles/TradingBot.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/TradingBot.dir/src/main.cpp.o.provides

CMakeFiles/TradingBot.dir/src/main.cpp.o.provides.build: CMakeFiles/TradingBot.dir/src/main.cpp.o


# Object files for target TradingBot
TradingBot_OBJECTS = \
"CMakeFiles/TradingBot.dir/src/main.cpp.o"

# External object files for target TradingBot
TradingBot_EXTERNAL_OBJECTS =

../TradingBot: CMakeFiles/TradingBot.dir/src/main.cpp.o
../TradingBot: CMakeFiles/TradingBot.dir/build.make
../TradingBot: CMakeFiles/TradingBot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/luke/Documents/DeversiFi_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../TradingBot"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TradingBot.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TradingBot.dir/build: ../TradingBot

.PHONY : CMakeFiles/TradingBot.dir/build

CMakeFiles/TradingBot.dir/requires: CMakeFiles/TradingBot.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/TradingBot.dir/requires

CMakeFiles/TradingBot.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TradingBot.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TradingBot.dir/clean

CMakeFiles/TradingBot.dir/depend:
	cd /home/luke/Documents/DeversiFi_Project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/luke/Documents/DeversiFi_Project /home/luke/Documents/DeversiFi_Project /home/luke/Documents/DeversiFi_Project/build /home/luke/Documents/DeversiFi_Project/build /home/luke/Documents/DeversiFi_Project/build/CMakeFiles/TradingBot.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TradingBot.dir/depend
