# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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
CMAKE_SOURCE_DIR = /home/matt/Documents/phys2d

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/matt/Documents/phys2d/build

# Include any dependencies generated for this target.
include CMakeFiles/phys2d.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/phys2d.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/phys2d.dir/flags.make

CMakeFiles/phys2d.dir/source/main.cpp.o: CMakeFiles/phys2d.dir/flags.make
CMakeFiles/phys2d.dir/source/main.cpp.o: ../source/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/matt/Documents/phys2d/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/phys2d.dir/source/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/phys2d.dir/source/main.cpp.o -c /home/matt/Documents/phys2d/source/main.cpp

CMakeFiles/phys2d.dir/source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/phys2d.dir/source/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/matt/Documents/phys2d/source/main.cpp > CMakeFiles/phys2d.dir/source/main.cpp.i

CMakeFiles/phys2d.dir/source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/phys2d.dir/source/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/matt/Documents/phys2d/source/main.cpp -o CMakeFiles/phys2d.dir/source/main.cpp.s

CMakeFiles/phys2d.dir/source/main.cpp.o.requires:
.PHONY : CMakeFiles/phys2d.dir/source/main.cpp.o.requires

CMakeFiles/phys2d.dir/source/main.cpp.o.provides: CMakeFiles/phys2d.dir/source/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/phys2d.dir/build.make CMakeFiles/phys2d.dir/source/main.cpp.o.provides.build
.PHONY : CMakeFiles/phys2d.dir/source/main.cpp.o.provides

CMakeFiles/phys2d.dir/source/main.cpp.o.provides.build: CMakeFiles/phys2d.dir/source/main.cpp.o

CMakeFiles/phys2d.dir/source/world.cpp.o: CMakeFiles/phys2d.dir/flags.make
CMakeFiles/phys2d.dir/source/world.cpp.o: ../source/world.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/matt/Documents/phys2d/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/phys2d.dir/source/world.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/phys2d.dir/source/world.cpp.o -c /home/matt/Documents/phys2d/source/world.cpp

CMakeFiles/phys2d.dir/source/world.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/phys2d.dir/source/world.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/matt/Documents/phys2d/source/world.cpp > CMakeFiles/phys2d.dir/source/world.cpp.i

CMakeFiles/phys2d.dir/source/world.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/phys2d.dir/source/world.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/matt/Documents/phys2d/source/world.cpp -o CMakeFiles/phys2d.dir/source/world.cpp.s

CMakeFiles/phys2d.dir/source/world.cpp.o.requires:
.PHONY : CMakeFiles/phys2d.dir/source/world.cpp.o.requires

CMakeFiles/phys2d.dir/source/world.cpp.o.provides: CMakeFiles/phys2d.dir/source/world.cpp.o.requires
	$(MAKE) -f CMakeFiles/phys2d.dir/build.make CMakeFiles/phys2d.dir/source/world.cpp.o.provides.build
.PHONY : CMakeFiles/phys2d.dir/source/world.cpp.o.provides

CMakeFiles/phys2d.dir/source/world.cpp.o.provides.build: CMakeFiles/phys2d.dir/source/world.cpp.o

CMakeFiles/phys2d.dir/source/screen.cpp.o: CMakeFiles/phys2d.dir/flags.make
CMakeFiles/phys2d.dir/source/screen.cpp.o: ../source/screen.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/matt/Documents/phys2d/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/phys2d.dir/source/screen.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/phys2d.dir/source/screen.cpp.o -c /home/matt/Documents/phys2d/source/screen.cpp

CMakeFiles/phys2d.dir/source/screen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/phys2d.dir/source/screen.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/matt/Documents/phys2d/source/screen.cpp > CMakeFiles/phys2d.dir/source/screen.cpp.i

CMakeFiles/phys2d.dir/source/screen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/phys2d.dir/source/screen.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/matt/Documents/phys2d/source/screen.cpp -o CMakeFiles/phys2d.dir/source/screen.cpp.s

CMakeFiles/phys2d.dir/source/screen.cpp.o.requires:
.PHONY : CMakeFiles/phys2d.dir/source/screen.cpp.o.requires

CMakeFiles/phys2d.dir/source/screen.cpp.o.provides: CMakeFiles/phys2d.dir/source/screen.cpp.o.requires
	$(MAKE) -f CMakeFiles/phys2d.dir/build.make CMakeFiles/phys2d.dir/source/screen.cpp.o.provides.build
.PHONY : CMakeFiles/phys2d.dir/source/screen.cpp.o.provides

CMakeFiles/phys2d.dir/source/screen.cpp.o.provides.build: CMakeFiles/phys2d.dir/source/screen.cpp.o

CMakeFiles/phys2d.dir/source/entity.cpp.o: CMakeFiles/phys2d.dir/flags.make
CMakeFiles/phys2d.dir/source/entity.cpp.o: ../source/entity.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/matt/Documents/phys2d/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/phys2d.dir/source/entity.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/phys2d.dir/source/entity.cpp.o -c /home/matt/Documents/phys2d/source/entity.cpp

CMakeFiles/phys2d.dir/source/entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/phys2d.dir/source/entity.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/matt/Documents/phys2d/source/entity.cpp > CMakeFiles/phys2d.dir/source/entity.cpp.i

CMakeFiles/phys2d.dir/source/entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/phys2d.dir/source/entity.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/matt/Documents/phys2d/source/entity.cpp -o CMakeFiles/phys2d.dir/source/entity.cpp.s

CMakeFiles/phys2d.dir/source/entity.cpp.o.requires:
.PHONY : CMakeFiles/phys2d.dir/source/entity.cpp.o.requires

CMakeFiles/phys2d.dir/source/entity.cpp.o.provides: CMakeFiles/phys2d.dir/source/entity.cpp.o.requires
	$(MAKE) -f CMakeFiles/phys2d.dir/build.make CMakeFiles/phys2d.dir/source/entity.cpp.o.provides.build
.PHONY : CMakeFiles/phys2d.dir/source/entity.cpp.o.provides

CMakeFiles/phys2d.dir/source/entity.cpp.o.provides.build: CMakeFiles/phys2d.dir/source/entity.cpp.o

CMakeFiles/phys2d.dir/source/grid.cpp.o: CMakeFiles/phys2d.dir/flags.make
CMakeFiles/phys2d.dir/source/grid.cpp.o: ../source/grid.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/matt/Documents/phys2d/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/phys2d.dir/source/grid.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/phys2d.dir/source/grid.cpp.o -c /home/matt/Documents/phys2d/source/grid.cpp

CMakeFiles/phys2d.dir/source/grid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/phys2d.dir/source/grid.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/matt/Documents/phys2d/source/grid.cpp > CMakeFiles/phys2d.dir/source/grid.cpp.i

CMakeFiles/phys2d.dir/source/grid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/phys2d.dir/source/grid.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/matt/Documents/phys2d/source/grid.cpp -o CMakeFiles/phys2d.dir/source/grid.cpp.s

CMakeFiles/phys2d.dir/source/grid.cpp.o.requires:
.PHONY : CMakeFiles/phys2d.dir/source/grid.cpp.o.requires

CMakeFiles/phys2d.dir/source/grid.cpp.o.provides: CMakeFiles/phys2d.dir/source/grid.cpp.o.requires
	$(MAKE) -f CMakeFiles/phys2d.dir/build.make CMakeFiles/phys2d.dir/source/grid.cpp.o.provides.build
.PHONY : CMakeFiles/phys2d.dir/source/grid.cpp.o.provides

CMakeFiles/phys2d.dir/source/grid.cpp.o.provides.build: CMakeFiles/phys2d.dir/source/grid.cpp.o

# Object files for target phys2d
phys2d_OBJECTS = \
"CMakeFiles/phys2d.dir/source/main.cpp.o" \
"CMakeFiles/phys2d.dir/source/world.cpp.o" \
"CMakeFiles/phys2d.dir/source/screen.cpp.o" \
"CMakeFiles/phys2d.dir/source/entity.cpp.o" \
"CMakeFiles/phys2d.dir/source/grid.cpp.o"

# External object files for target phys2d
phys2d_EXTERNAL_OBJECTS =

phys2d: CMakeFiles/phys2d.dir/source/main.cpp.o
phys2d: CMakeFiles/phys2d.dir/source/world.cpp.o
phys2d: CMakeFiles/phys2d.dir/source/screen.cpp.o
phys2d: CMakeFiles/phys2d.dir/source/entity.cpp.o
phys2d: CMakeFiles/phys2d.dir/source/grid.cpp.o
phys2d: CMakeFiles/phys2d.dir/build.make
phys2d: /usr/lib/x86_64-linux-gnu/libSDL2main.a
phys2d: /usr/lib/x86_64-linux-gnu/libSDL2.so
phys2d: CMakeFiles/phys2d.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable phys2d"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/phys2d.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/phys2d.dir/build: phys2d
.PHONY : CMakeFiles/phys2d.dir/build

CMakeFiles/phys2d.dir/requires: CMakeFiles/phys2d.dir/source/main.cpp.o.requires
CMakeFiles/phys2d.dir/requires: CMakeFiles/phys2d.dir/source/world.cpp.o.requires
CMakeFiles/phys2d.dir/requires: CMakeFiles/phys2d.dir/source/screen.cpp.o.requires
CMakeFiles/phys2d.dir/requires: CMakeFiles/phys2d.dir/source/entity.cpp.o.requires
CMakeFiles/phys2d.dir/requires: CMakeFiles/phys2d.dir/source/grid.cpp.o.requires
.PHONY : CMakeFiles/phys2d.dir/requires

CMakeFiles/phys2d.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/phys2d.dir/cmake_clean.cmake
.PHONY : CMakeFiles/phys2d.dir/clean

CMakeFiles/phys2d.dir/depend:
	cd /home/matt/Documents/phys2d/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/matt/Documents/phys2d /home/matt/Documents/phys2d /home/matt/Documents/phys2d/build /home/matt/Documents/phys2d/build /home/matt/Documents/phys2d/build/CMakeFiles/phys2d.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/phys2d.dir/depend
