# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/xutiancheng/test/startdust/sd_libevent/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xutiancheng/test/startdust/sd_libevent/test/build

# Include any dependencies generated for this target.
include service/CMakeFiles/service.dir/depend.make

# Include the progress variables for this target.
include service/CMakeFiles/service.dir/progress.make

# Include the compile flags for this target's objects.
include service/CMakeFiles/service.dir/flags.make

service/CMakeFiles/service.dir/service.cpp.o: service/CMakeFiles/service.dir/flags.make
service/CMakeFiles/service.dir/service.cpp.o: ../service/service.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xutiancheng/test/startdust/sd_libevent/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object service/CMakeFiles/service.dir/service.cpp.o"
	cd /home/xutiancheng/test/startdust/sd_libevent/test/build/service && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/service.dir/service.cpp.o -c /home/xutiancheng/test/startdust/sd_libevent/test/service/service.cpp

service/CMakeFiles/service.dir/service.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/service.dir/service.cpp.i"
	cd /home/xutiancheng/test/startdust/sd_libevent/test/build/service && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xutiancheng/test/startdust/sd_libevent/test/service/service.cpp > CMakeFiles/service.dir/service.cpp.i

service/CMakeFiles/service.dir/service.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/service.dir/service.cpp.s"
	cd /home/xutiancheng/test/startdust/sd_libevent/test/build/service && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xutiancheng/test/startdust/sd_libevent/test/service/service.cpp -o CMakeFiles/service.dir/service.cpp.s

# Object files for target service
service_OBJECTS = \
"CMakeFiles/service.dir/service.cpp.o"

# External object files for target service
service_EXTERNAL_OBJECTS =

bin/service: service/CMakeFiles/service.dir/service.cpp.o
bin/service: service/CMakeFiles/service.dir/build.make
bin/service: /usr/local/lib/liblog4cxx.so.15.1.0
bin/service: service/CMakeFiles/service.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xutiancheng/test/startdust/sd_libevent/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/service"
	cd /home/xutiancheng/test/startdust/sd_libevent/test/build/service && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/service.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
service/CMakeFiles/service.dir/build: bin/service

.PHONY : service/CMakeFiles/service.dir/build

service/CMakeFiles/service.dir/clean:
	cd /home/xutiancheng/test/startdust/sd_libevent/test/build/service && $(CMAKE_COMMAND) -P CMakeFiles/service.dir/cmake_clean.cmake
.PHONY : service/CMakeFiles/service.dir/clean

service/CMakeFiles/service.dir/depend:
	cd /home/xutiancheng/test/startdust/sd_libevent/test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xutiancheng/test/startdust/sd_libevent/test /home/xutiancheng/test/startdust/sd_libevent/test/service /home/xutiancheng/test/startdust/sd_libevent/test/build /home/xutiancheng/test/startdust/sd_libevent/test/build/service /home/xutiancheng/test/startdust/sd_libevent/test/build/service/CMakeFiles/service.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : service/CMakeFiles/service.dir/depend

