# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Apps\CLion-2019.2.win\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Apps\CLion-2019.2.win\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = U:\NTProfile\Desktop\Part3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = U:\NTProfile\Desktop\Part3\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Part3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Part3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Part3.dir/flags.make

CMakeFiles/Part3.dir/part3_test.c.obj: CMakeFiles/Part3.dir/flags.make
CMakeFiles/Part3.dir/part3_test.c.obj: ../part3_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=U:\NTProfile\Desktop\Part3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Part3.dir/part3_test.c.obj"
	C:\Apps\mingw-w64\i686-8.1.0-posix-dwarf\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Part3.dir\part3_test.c.obj   -c U:\NTProfile\Desktop\Part3\part3_test.c

CMakeFiles/Part3.dir/part3_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Part3.dir/part3_test.c.i"
	C:\Apps\mingw-w64\i686-8.1.0-posix-dwarf\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E U:\NTProfile\Desktop\Part3\part3_test.c > CMakeFiles\Part3.dir\part3_test.c.i

CMakeFiles/Part3.dir/part3_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Part3.dir/part3_test.c.s"
	C:\Apps\mingw-w64\i686-8.1.0-posix-dwarf\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S U:\NTProfile\Desktop\Part3\part3_test.c -o CMakeFiles\Part3.dir\part3_test.c.s

CMakeFiles/Part3.dir/part3.c.obj: CMakeFiles/Part3.dir/flags.make
CMakeFiles/Part3.dir/part3.c.obj: ../part3.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=U:\NTProfile\Desktop\Part3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Part3.dir/part3.c.obj"
	C:\Apps\mingw-w64\i686-8.1.0-posix-dwarf\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Part3.dir\part3.c.obj   -c U:\NTProfile\Desktop\Part3\part3.c

CMakeFiles/Part3.dir/part3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Part3.dir/part3.c.i"
	C:\Apps\mingw-w64\i686-8.1.0-posix-dwarf\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E U:\NTProfile\Desktop\Part3\part3.c > CMakeFiles\Part3.dir\part3.c.i

CMakeFiles/Part3.dir/part3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Part3.dir/part3.c.s"
	C:\Apps\mingw-w64\i686-8.1.0-posix-dwarf\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S U:\NTProfile\Desktop\Part3\part3.c -o CMakeFiles\Part3.dir\part3.c.s

# Object files for target Part3
Part3_OBJECTS = \
"CMakeFiles/Part3.dir/part3_test.c.obj" \
"CMakeFiles/Part3.dir/part3.c.obj"

# External object files for target Part3
Part3_EXTERNAL_OBJECTS =

Part3.exe: CMakeFiles/Part3.dir/part3_test.c.obj
Part3.exe: CMakeFiles/Part3.dir/part3.c.obj
Part3.exe: CMakeFiles/Part3.dir/build.make
Part3.exe: CMakeFiles/Part3.dir/linklibs.rsp
Part3.exe: CMakeFiles/Part3.dir/objects1.rsp
Part3.exe: CMakeFiles/Part3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=U:\NTProfile\Desktop\Part3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Part3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Part3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Part3.dir/build: Part3.exe

.PHONY : CMakeFiles/Part3.dir/build

CMakeFiles/Part3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Part3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Part3.dir/clean

CMakeFiles/Part3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" U:\NTProfile\Desktop\Part3 U:\NTProfile\Desktop\Part3 U:\NTProfile\Desktop\Part3\cmake-build-debug U:\NTProfile\Desktop\Part3\cmake-build-debug U:\NTProfile\Desktop\Part3\cmake-build-debug\CMakeFiles\Part3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Part3.dir/depend

