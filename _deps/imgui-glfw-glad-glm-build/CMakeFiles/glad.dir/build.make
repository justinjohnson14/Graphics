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
CMAKE_SOURCE_DIR = /home/justin/Documents/graphics

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/justin/Documents/graphics

# Include any dependencies generated for this target.
include _deps/imgui-glfw-glad-glm-build/CMakeFiles/glad.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/imgui-glfw-glad-glm-build/CMakeFiles/glad.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/imgui-glfw-glad-glm-build/CMakeFiles/glad.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/imgui-glfw-glad-glm-build/CMakeFiles/glad.dir/flags.make

_deps/imgui-glfw-glad-glm-build/CMakeFiles/glad.dir/__/glad-src/src/gl.c.o: _deps/imgui-glfw-glad-glm-build/CMakeFiles/glad.dir/flags.make
_deps/imgui-glfw-glad-glm-build/CMakeFiles/glad.dir/__/glad-src/src/gl.c.o: _deps/glad-src/src/gl.c
_deps/imgui-glfw-glad-glm-build/CMakeFiles/glad.dir/__/glad-src/src/gl.c.o: _deps/imgui-glfw-glad-glm-build/CMakeFiles/glad.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/justin/Documents/graphics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object _deps/imgui-glfw-glad-glm-build/CMakeFiles/glad.dir/__/glad-src/src/gl.c.o"
	cd /home/justin/Documents/graphics/_deps/imgui-glfw-glad-glm-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/imgui-glfw-glad-glm-build/CMakeFiles/glad.dir/__/glad-src/src/gl.c.o -MF CMakeFiles/glad.dir/__/glad-src/src/gl.c.o.d -o CMakeFiles/glad.dir/__/glad-src/src/gl.c.o -c /home/justin/Documents/graphics/_deps/glad-src/src/gl.c

_deps/imgui-glfw-glad-glm-build/CMakeFiles/glad.dir/__/glad-src/src/gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/glad.dir/__/glad-src/src/gl.c.i"
	cd /home/justin/Documents/graphics/_deps/imgui-glfw-glad-glm-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/justin/Documents/graphics/_deps/glad-src/src/gl.c > CMakeFiles/glad.dir/__/glad-src/src/gl.c.i

_deps/imgui-glfw-glad-glm-build/CMakeFiles/glad.dir/__/glad-src/src/gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/glad.dir/__/glad-src/src/gl.c.s"
	cd /home/justin/Documents/graphics/_deps/imgui-glfw-glad-glm-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/justin/Documents/graphics/_deps/glad-src/src/gl.c -o CMakeFiles/glad.dir/__/glad-src/src/gl.c.s

# Object files for target glad
glad_OBJECTS = \
"CMakeFiles/glad.dir/__/glad-src/src/gl.c.o"

# External object files for target glad
glad_EXTERNAL_OBJECTS =

_deps/imgui-glfw-glad-glm-build/libglad.a: _deps/imgui-glfw-glad-glm-build/CMakeFiles/glad.dir/__/glad-src/src/gl.c.o
_deps/imgui-glfw-glad-glm-build/libglad.a: _deps/imgui-glfw-glad-glm-build/CMakeFiles/glad.dir/build.make
_deps/imgui-glfw-glad-glm-build/libglad.a: _deps/imgui-glfw-glad-glm-build/CMakeFiles/glad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/justin/Documents/graphics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libglad.a"
	cd /home/justin/Documents/graphics/_deps/imgui-glfw-glad-glm-build && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean_target.cmake
	cd /home/justin/Documents/graphics/_deps/imgui-glfw-glad-glm-build && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glad.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/imgui-glfw-glad-glm-build/CMakeFiles/glad.dir/build: _deps/imgui-glfw-glad-glm-build/libglad.a
.PHONY : _deps/imgui-glfw-glad-glm-build/CMakeFiles/glad.dir/build

_deps/imgui-glfw-glad-glm-build/CMakeFiles/glad.dir/clean:
	cd /home/justin/Documents/graphics/_deps/imgui-glfw-glad-glm-build && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean.cmake
.PHONY : _deps/imgui-glfw-glad-glm-build/CMakeFiles/glad.dir/clean

_deps/imgui-glfw-glad-glm-build/CMakeFiles/glad.dir/depend:
	cd /home/justin/Documents/graphics && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/justin/Documents/graphics /home/justin/Documents/graphics/_deps/imgui-glfw-glad-glm-src /home/justin/Documents/graphics /home/justin/Documents/graphics/_deps/imgui-glfw-glad-glm-build /home/justin/Documents/graphics/_deps/imgui-glfw-glad-glm-build/CMakeFiles/glad.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _deps/imgui-glfw-glad-glm-build/CMakeFiles/glad.dir/depend

