# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\galla\OneDrive - Queen's University\1. Current Classes\ELEC 278\278_Lab3_Main"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\galla\OneDrive - Queen's University\1. Current Classes\ELEC 278\278_Lab3_Main\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/LAB3_MAIN.c.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/LAB3_MAIN.c.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/LAB3_MAIN.c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LAB3_MAIN.c.dir/flags.make

CMakeFiles/LAB3_MAIN.c.dir/LAB3_BST.c.obj: CMakeFiles/LAB3_MAIN.c.dir/flags.make
CMakeFiles/LAB3_MAIN.c.dir/LAB3_BST.c.obj: ../LAB3_BST.c
CMakeFiles/LAB3_MAIN.c.dir/LAB3_BST.c.obj: CMakeFiles/LAB3_MAIN.c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\galla\OneDrive - Queen's University\1. Current Classes\ELEC 278\278_Lab3_Main\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/LAB3_MAIN.c.dir/LAB3_BST.c.obj"
	"C:\PROGRA~1\JetBrains\CLion 2022.2.1\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/LAB3_MAIN.c.dir/LAB3_BST.c.obj -MF CMakeFiles\LAB3_MAIN.c.dir\LAB3_BST.c.obj.d -o CMakeFiles\LAB3_MAIN.c.dir\LAB3_BST.c.obj -c "C:\Users\galla\OneDrive - Queen's University\1. Current Classes\ELEC 278\278_Lab3_Main\LAB3_BST.c"

CMakeFiles/LAB3_MAIN.c.dir/LAB3_BST.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LAB3_MAIN.c.dir/LAB3_BST.c.i"
	"C:\PROGRA~1\JetBrains\CLion 2022.2.1\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\galla\OneDrive - Queen's University\1. Current Classes\ELEC 278\278_Lab3_Main\LAB3_BST.c" > CMakeFiles\LAB3_MAIN.c.dir\LAB3_BST.c.i

CMakeFiles/LAB3_MAIN.c.dir/LAB3_BST.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LAB3_MAIN.c.dir/LAB3_BST.c.s"
	"C:\PROGRA~1\JetBrains\CLion 2022.2.1\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\galla\OneDrive - Queen's University\1. Current Classes\ELEC 278\278_Lab3_Main\LAB3_BST.c" -o CMakeFiles\LAB3_MAIN.c.dir\LAB3_BST.c.s

CMakeFiles/LAB3_MAIN.c.dir/LAB3_MAIN.c.obj: CMakeFiles/LAB3_MAIN.c.dir/flags.make
CMakeFiles/LAB3_MAIN.c.dir/LAB3_MAIN.c.obj: ../LAB3_MAIN.c
CMakeFiles/LAB3_MAIN.c.dir/LAB3_MAIN.c.obj: CMakeFiles/LAB3_MAIN.c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\galla\OneDrive - Queen's University\1. Current Classes\ELEC 278\278_Lab3_Main\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/LAB3_MAIN.c.dir/LAB3_MAIN.c.obj"
	"C:\PROGRA~1\JetBrains\CLion 2022.2.1\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/LAB3_MAIN.c.dir/LAB3_MAIN.c.obj -MF CMakeFiles\LAB3_MAIN.c.dir\LAB3_MAIN.c.obj.d -o CMakeFiles\LAB3_MAIN.c.dir\LAB3_MAIN.c.obj -c "C:\Users\galla\OneDrive - Queen's University\1. Current Classes\ELEC 278\278_Lab3_Main\LAB3_MAIN.c"

CMakeFiles/LAB3_MAIN.c.dir/LAB3_MAIN.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LAB3_MAIN.c.dir/LAB3_MAIN.c.i"
	"C:\PROGRA~1\JetBrains\CLion 2022.2.1\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\galla\OneDrive - Queen's University\1. Current Classes\ELEC 278\278_Lab3_Main\LAB3_MAIN.c" > CMakeFiles\LAB3_MAIN.c.dir\LAB3_MAIN.c.i

CMakeFiles/LAB3_MAIN.c.dir/LAB3_MAIN.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LAB3_MAIN.c.dir/LAB3_MAIN.c.s"
	"C:\PROGRA~1\JetBrains\CLion 2022.2.1\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\galla\OneDrive - Queen's University\1. Current Classes\ELEC 278\278_Lab3_Main\LAB3_MAIN.c" -o CMakeFiles\LAB3_MAIN.c.dir\LAB3_MAIN.c.s

# Object files for target LAB3_MAIN.c
LAB3_MAIN_c_OBJECTS = \
"CMakeFiles/LAB3_MAIN.c.dir/LAB3_BST.c.obj" \
"CMakeFiles/LAB3_MAIN.c.dir/LAB3_MAIN.c.obj"

# External object files for target LAB3_MAIN.c
LAB3_MAIN_c_EXTERNAL_OBJECTS =

LAB3_MAIN.c.exe: CMakeFiles/LAB3_MAIN.c.dir/LAB3_BST.c.obj
LAB3_MAIN.c.exe: CMakeFiles/LAB3_MAIN.c.dir/LAB3_MAIN.c.obj
LAB3_MAIN.c.exe: CMakeFiles/LAB3_MAIN.c.dir/build.make
LAB3_MAIN.c.exe: CMakeFiles/LAB3_MAIN.c.dir/linklibs.rsp
LAB3_MAIN.c.exe: CMakeFiles/LAB3_MAIN.c.dir/objects1.rsp
LAB3_MAIN.c.exe: CMakeFiles/LAB3_MAIN.c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\galla\OneDrive - Queen's University\1. Current Classes\ELEC 278\278_Lab3_Main\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable LAB3_MAIN.c.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\LAB3_MAIN.c.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LAB3_MAIN.c.dir/build: LAB3_MAIN.c.exe
.PHONY : CMakeFiles/LAB3_MAIN.c.dir/build

CMakeFiles/LAB3_MAIN.c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\LAB3_MAIN.c.dir\cmake_clean.cmake
.PHONY : CMakeFiles/LAB3_MAIN.c.dir/clean

CMakeFiles/LAB3_MAIN.c.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\galla\OneDrive - Queen's University\1. Current Classes\ELEC 278\278_Lab3_Main" "C:\Users\galla\OneDrive - Queen's University\1. Current Classes\ELEC 278\278_Lab3_Main" "C:\Users\galla\OneDrive - Queen's University\1. Current Classes\ELEC 278\278_Lab3_Main\cmake-build-debug" "C:\Users\galla\OneDrive - Queen's University\1. Current Classes\ELEC 278\278_Lab3_Main\cmake-build-debug" "C:\Users\galla\OneDrive - Queen's University\1. Current Classes\ELEC 278\278_Lab3_Main\cmake-build-debug\CMakeFiles\LAB3_MAIN.c.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/LAB3_MAIN.c.dir/depend

