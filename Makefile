# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.17.0_1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.17.0_1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/thomasduvinage/Documents/GitHub/StudentAnalyser

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/thomasduvinage/Documents/GitHub/StudentAnalyser

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.17.0_1/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.17.0_1/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/thomasduvinage/Documents/GitHub/StudentAnalyser/CMakeFiles /Users/thomasduvinage/Documents/GitHub/StudentAnalyser/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/thomasduvinage/Documents/GitHub/StudentAnalyser/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named StudentAnalyser

# Build rule for target.
StudentAnalyser: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 StudentAnalyser
.PHONY : StudentAnalyser

# fast build rule for target.
StudentAnalyser/fast:
	$(MAKE) -f CMakeFiles/StudentAnalyser.dir/build.make CMakeFiles/StudentAnalyser.dir/build
.PHONY : StudentAnalyser/fast

#=============================================================================
# Target rules for targets named StudentAnalyser_autogen

# Build rule for target.
StudentAnalyser_autogen: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 StudentAnalyser_autogen
.PHONY : StudentAnalyser_autogen

# fast build rule for target.
StudentAnalyser_autogen/fast:
	$(MAKE) -f CMakeFiles/StudentAnalyser_autogen.dir/build.make CMakeFiles/StudentAnalyser_autogen.dir/build
.PHONY : StudentAnalyser_autogen/fast

#=============================================================================
# Target rules for targets named Scanner

# Build rule for target.
Scanner: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Scanner
.PHONY : Scanner

# fast build rule for target.
Scanner/fast:
	$(MAKE) -f libs/scanner/CMakeFiles/Scanner.dir/build.make libs/scanner/CMakeFiles/Scanner.dir/build
.PHONY : Scanner/fast

#=============================================================================
# Target rules for targets named Scanner_autogen

# Build rule for target.
Scanner_autogen: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Scanner_autogen
.PHONY : Scanner_autogen

# fast build rule for target.
Scanner_autogen/fast:
	$(MAKE) -f libs/scanner/CMakeFiles/Scanner_autogen.dir/build.make libs/scanner/CMakeFiles/Scanner_autogen.dir/build
.PHONY : Scanner_autogen/fast

#=============================================================================
# Target rules for targets named Analyser

# Build rule for target.
Analyser: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Analyser
.PHONY : Analyser

# fast build rule for target.
Analyser/fast:
	$(MAKE) -f libs/analyser/CMakeFiles/Analyser.dir/build.make libs/analyser/CMakeFiles/Analyser.dir/build
.PHONY : Analyser/fast

#=============================================================================
# Target rules for targets named Analyser_autogen

# Build rule for target.
Analyser_autogen: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Analyser_autogen
.PHONY : Analyser_autogen

# fast build rule for target.
Analyser_autogen/fast:
	$(MAKE) -f libs/analyser/CMakeFiles/Analyser_autogen.dir/build.make libs/analyser/CMakeFiles/Analyser_autogen.dir/build
.PHONY : Analyser_autogen/fast

#=============================================================================
# Target rules for targets named SerialLib

# Build rule for target.
SerialLib: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 SerialLib
.PHONY : SerialLib

# fast build rule for target.
SerialLib/fast:
	$(MAKE) -f libs/SerialLib/CMakeFiles/SerialLib.dir/build.make libs/SerialLib/CMakeFiles/SerialLib.dir/build
.PHONY : SerialLib/fast

#=============================================================================
# Target rules for targets named SerialLib_autogen

# Build rule for target.
SerialLib_autogen: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 SerialLib_autogen
.PHONY : SerialLib_autogen

# fast build rule for target.
SerialLib_autogen/fast:
	$(MAKE) -f libs/SerialLib/CMakeFiles/SerialLib_autogen.dir/build.make libs/SerialLib/CMakeFiles/SerialLib_autogen.dir/build
.PHONY : SerialLib_autogen/fast

#=============================================================================
# Target rules for targets named FileManager

# Build rule for target.
FileManager: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 FileManager
.PHONY : FileManager

# fast build rule for target.
FileManager/fast:
	$(MAKE) -f libs/FileManager/CMakeFiles/FileManager.dir/build.make libs/FileManager/CMakeFiles/FileManager.dir/build
.PHONY : FileManager/fast

#=============================================================================
# Target rules for targets named FileManager_autogen

# Build rule for target.
FileManager_autogen: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 FileManager_autogen
.PHONY : FileManager_autogen

# fast build rule for target.
FileManager_autogen/fast:
	$(MAKE) -f libs/FileManager/CMakeFiles/FileManager_autogen.dir/build.make libs/FileManager/CMakeFiles/FileManager_autogen.dir/build
.PHONY : FileManager_autogen/fast

#=============================================================================
# Target rules for targets named Logger

# Build rule for target.
Logger: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Logger
.PHONY : Logger

# fast build rule for target.
Logger/fast:
	$(MAKE) -f libs/Logger/CMakeFiles/Logger.dir/build.make libs/Logger/CMakeFiles/Logger.dir/build
.PHONY : Logger/fast

#=============================================================================
# Target rules for targets named Logger_autogen

# Build rule for target.
Logger_autogen: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Logger_autogen
.PHONY : Logger_autogen

# fast build rule for target.
Logger_autogen/fast:
	$(MAKE) -f libs/Logger/CMakeFiles/Logger_autogen.dir/build.make libs/Logger/CMakeFiles/Logger_autogen.dir/build
.PHONY : Logger_autogen/fast

#=============================================================================
# Target rules for targets named Dataviewer

# Build rule for target.
Dataviewer: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Dataviewer
.PHONY : Dataviewer

# fast build rule for target.
Dataviewer/fast:
	$(MAKE) -f libs/Dataviewer/CMakeFiles/Dataviewer.dir/build.make libs/Dataviewer/CMakeFiles/Dataviewer.dir/build
.PHONY : Dataviewer/fast

#=============================================================================
# Target rules for targets named Dataviewer_autogen

# Build rule for target.
Dataviewer_autogen: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Dataviewer_autogen
.PHONY : Dataviewer_autogen

# fast build rule for target.
Dataviewer_autogen/fast:
	$(MAKE) -f libs/Dataviewer/CMakeFiles/Dataviewer_autogen.dir/build.make libs/Dataviewer/CMakeFiles/Dataviewer_autogen.dir/build
.PHONY : Dataviewer_autogen/fast

StudentAnalyser_autogen/mocs_compilation.o: StudentAnalyser_autogen/mocs_compilation.cpp.o

.PHONY : StudentAnalyser_autogen/mocs_compilation.o

# target to build an object file
StudentAnalyser_autogen/mocs_compilation.cpp.o:
	$(MAKE) -f CMakeFiles/StudentAnalyser.dir/build.make CMakeFiles/StudentAnalyser.dir/StudentAnalyser_autogen/mocs_compilation.cpp.o
.PHONY : StudentAnalyser_autogen/mocs_compilation.cpp.o

StudentAnalyser_autogen/mocs_compilation.i: StudentAnalyser_autogen/mocs_compilation.cpp.i

.PHONY : StudentAnalyser_autogen/mocs_compilation.i

# target to preprocess a source file
StudentAnalyser_autogen/mocs_compilation.cpp.i:
	$(MAKE) -f CMakeFiles/StudentAnalyser.dir/build.make CMakeFiles/StudentAnalyser.dir/StudentAnalyser_autogen/mocs_compilation.cpp.i
.PHONY : StudentAnalyser_autogen/mocs_compilation.cpp.i

StudentAnalyser_autogen/mocs_compilation.s: StudentAnalyser_autogen/mocs_compilation.cpp.s

.PHONY : StudentAnalyser_autogen/mocs_compilation.s

# target to generate assembly for a file
StudentAnalyser_autogen/mocs_compilation.cpp.s:
	$(MAKE) -f CMakeFiles/StudentAnalyser.dir/build.make CMakeFiles/StudentAnalyser.dir/StudentAnalyser_autogen/mocs_compilation.cpp.s
.PHONY : StudentAnalyser_autogen/mocs_compilation.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/StudentAnalyser.dir/build.make CMakeFiles/StudentAnalyser.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/StudentAnalyser.dir/build.make CMakeFiles/StudentAnalyser.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/StudentAnalyser.dir/build.make CMakeFiles/StudentAnalyser.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/mainwindow.o: src/mainwindow.cpp.o

.PHONY : src/mainwindow.o

# target to build an object file
src/mainwindow.cpp.o:
	$(MAKE) -f CMakeFiles/StudentAnalyser.dir/build.make CMakeFiles/StudentAnalyser.dir/src/mainwindow.cpp.o
.PHONY : src/mainwindow.cpp.o

src/mainwindow.i: src/mainwindow.cpp.i

.PHONY : src/mainwindow.i

# target to preprocess a source file
src/mainwindow.cpp.i:
	$(MAKE) -f CMakeFiles/StudentAnalyser.dir/build.make CMakeFiles/StudentAnalyser.dir/src/mainwindow.cpp.i
.PHONY : src/mainwindow.cpp.i

src/mainwindow.s: src/mainwindow.cpp.s

.PHONY : src/mainwindow.s

# target to generate assembly for a file
src/mainwindow.cpp.s:
	$(MAKE) -f CMakeFiles/StudentAnalyser.dir/build.make CMakeFiles/StudentAnalyser.dir/src/mainwindow.cpp.s
.PHONY : src/mainwindow.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... Analyser_autogen"
	@echo "... Dataviewer_autogen"
	@echo "... FileManager_autogen"
	@echo "... Logger_autogen"
	@echo "... Scanner_autogen"
	@echo "... SerialLib_autogen"
	@echo "... StudentAnalyser_autogen"
	@echo "... Analyser"
	@echo "... Dataviewer"
	@echo "... FileManager"
	@echo "... Logger"
	@echo "... Scanner"
	@echo "... SerialLib"
	@echo "... StudentAnalyser"
	@echo "... StudentAnalyser_autogen/mocs_compilation.o"
	@echo "... StudentAnalyser_autogen/mocs_compilation.i"
	@echo "... StudentAnalyser_autogen/mocs_compilation.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/mainwindow.o"
	@echo "... src/mainwindow.i"
	@echo "... src/mainwindow.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

