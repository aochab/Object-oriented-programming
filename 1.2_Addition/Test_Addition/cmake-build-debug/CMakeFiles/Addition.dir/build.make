# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /opt/clion-2019.2.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.2.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/student/OOP/1.2_Addition/Test_Addition

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/student/OOP/1.2_Addition/Test_Addition/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Addition.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Addition.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Addition.dir/flags.make

CMakeFiles/Addition.dir/test.cpp.o: CMakeFiles/Addition.dir/flags.make
CMakeFiles/Addition.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/OOP/1.2_Addition/Test_Addition/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Addition.dir/test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Addition.dir/test.cpp.o -c /home/student/OOP/1.2_Addition/Test_Addition/test.cpp

CMakeFiles/Addition.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Addition.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/OOP/1.2_Addition/Test_Addition/test.cpp > CMakeFiles/Addition.dir/test.cpp.i

CMakeFiles/Addition.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Addition.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/OOP/1.2_Addition/Test_Addition/test.cpp -o CMakeFiles/Addition.dir/test.cpp.s

# Object files for target Addition
Addition_OBJECTS = \
"CMakeFiles/Addition.dir/test.cpp.o"

# External object files for target Addition
Addition_EXTERNAL_OBJECTS =

Addition: CMakeFiles/Addition.dir/test.cpp.o
Addition: CMakeFiles/Addition.dir/build.make
Addition: CMakeFiles/Addition.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/student/OOP/1.2_Addition/Test_Addition/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Addition"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Addition.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Addition.dir/build: Addition

.PHONY : CMakeFiles/Addition.dir/build

CMakeFiles/Addition.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Addition.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Addition.dir/clean

CMakeFiles/Addition.dir/depend:
	cd /home/student/OOP/1.2_Addition/Test_Addition/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student/OOP/1.2_Addition/Test_Addition /home/student/OOP/1.2_Addition/Test_Addition /home/student/OOP/1.2_Addition/Test_Addition/cmake-build-debug /home/student/OOP/1.2_Addition/Test_Addition/cmake-build-debug /home/student/OOP/1.2_Addition/Test_Addition/cmake-build-debug/CMakeFiles/Addition.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Addition.dir/depend
