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
CMAKE_SOURCE_DIR = /home/lexseal/Documents/sudoku

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lexseal/Documents/sudoku

# Include any dependencies generated for this target.
include CMakeFiles/sudoku.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sudoku.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sudoku.dir/flags.make

CMakeFiles/sudoku.dir/main.cpp.o: CMakeFiles/sudoku.dir/flags.make
CMakeFiles/sudoku.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lexseal/Documents/sudoku/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sudoku.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sudoku.dir/main.cpp.o -c /home/lexseal/Documents/sudoku/main.cpp

CMakeFiles/sudoku.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sudoku.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lexseal/Documents/sudoku/main.cpp > CMakeFiles/sudoku.dir/main.cpp.i

CMakeFiles/sudoku.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sudoku.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lexseal/Documents/sudoku/main.cpp -o CMakeFiles/sudoku.dir/main.cpp.s

CMakeFiles/sudoku.dir/solver.cpp.o: CMakeFiles/sudoku.dir/flags.make
CMakeFiles/sudoku.dir/solver.cpp.o: solver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lexseal/Documents/sudoku/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sudoku.dir/solver.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sudoku.dir/solver.cpp.o -c /home/lexseal/Documents/sudoku/solver.cpp

CMakeFiles/sudoku.dir/solver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sudoku.dir/solver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lexseal/Documents/sudoku/solver.cpp > CMakeFiles/sudoku.dir/solver.cpp.i

CMakeFiles/sudoku.dir/solver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sudoku.dir/solver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lexseal/Documents/sudoku/solver.cpp -o CMakeFiles/sudoku.dir/solver.cpp.s

CMakeFiles/sudoku.dir/sudokuBoard.cpp.o: CMakeFiles/sudoku.dir/flags.make
CMakeFiles/sudoku.dir/sudokuBoard.cpp.o: sudokuBoard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lexseal/Documents/sudoku/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sudoku.dir/sudokuBoard.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sudoku.dir/sudokuBoard.cpp.o -c /home/lexseal/Documents/sudoku/sudokuBoard.cpp

CMakeFiles/sudoku.dir/sudokuBoard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sudoku.dir/sudokuBoard.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lexseal/Documents/sudoku/sudokuBoard.cpp > CMakeFiles/sudoku.dir/sudokuBoard.cpp.i

CMakeFiles/sudoku.dir/sudokuBoard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sudoku.dir/sudokuBoard.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lexseal/Documents/sudoku/sudokuBoard.cpp -o CMakeFiles/sudoku.dir/sudokuBoard.cpp.s

CMakeFiles/sudoku.dir/imgToNum.cpp.o: CMakeFiles/sudoku.dir/flags.make
CMakeFiles/sudoku.dir/imgToNum.cpp.o: imgToNum.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lexseal/Documents/sudoku/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sudoku.dir/imgToNum.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sudoku.dir/imgToNum.cpp.o -c /home/lexseal/Documents/sudoku/imgToNum.cpp

CMakeFiles/sudoku.dir/imgToNum.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sudoku.dir/imgToNum.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lexseal/Documents/sudoku/imgToNum.cpp > CMakeFiles/sudoku.dir/imgToNum.cpp.i

CMakeFiles/sudoku.dir/imgToNum.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sudoku.dir/imgToNum.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lexseal/Documents/sudoku/imgToNum.cpp -o CMakeFiles/sudoku.dir/imgToNum.cpp.s

# Object files for target sudoku
sudoku_OBJECTS = \
"CMakeFiles/sudoku.dir/main.cpp.o" \
"CMakeFiles/sudoku.dir/solver.cpp.o" \
"CMakeFiles/sudoku.dir/sudokuBoard.cpp.o" \
"CMakeFiles/sudoku.dir/imgToNum.cpp.o"

# External object files for target sudoku
sudoku_EXTERNAL_OBJECTS =

sudoku: CMakeFiles/sudoku.dir/main.cpp.o
sudoku: CMakeFiles/sudoku.dir/solver.cpp.o
sudoku: CMakeFiles/sudoku.dir/sudokuBoard.cpp.o
sudoku: CMakeFiles/sudoku.dir/imgToNum.cpp.o
sudoku: CMakeFiles/sudoku.dir/build.make
sudoku: /usr/local/lib/libopencv_dnn.so.4.5.0
sudoku: /usr/local/lib/libopencv_gapi.so.4.5.0
sudoku: /usr/local/lib/libopencv_highgui.so.4.5.0
sudoku: /usr/local/lib/libopencv_ml.so.4.5.0
sudoku: /usr/local/lib/libopencv_objdetect.so.4.5.0
sudoku: /usr/local/lib/libopencv_photo.so.4.5.0
sudoku: /usr/local/lib/libopencv_stitching.so.4.5.0
sudoku: /usr/local/lib/libopencv_video.so.4.5.0
sudoku: /usr/local/lib/libopencv_videoio.so.4.5.0
sudoku: /usr/local/lib/libopencv_imgcodecs.so.4.5.0
sudoku: /usr/local/lib/libopencv_calib3d.so.4.5.0
sudoku: /usr/local/lib/libopencv_features2d.so.4.5.0
sudoku: /usr/local/lib/libopencv_flann.so.4.5.0
sudoku: /usr/local/lib/libopencv_imgproc.so.4.5.0
sudoku: /usr/local/lib/libopencv_core.so.4.5.0
sudoku: CMakeFiles/sudoku.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lexseal/Documents/sudoku/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable sudoku"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sudoku.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sudoku.dir/build: sudoku

.PHONY : CMakeFiles/sudoku.dir/build

CMakeFiles/sudoku.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sudoku.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sudoku.dir/clean

CMakeFiles/sudoku.dir/depend:
	cd /home/lexseal/Documents/sudoku && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lexseal/Documents/sudoku /home/lexseal/Documents/sudoku /home/lexseal/Documents/sudoku /home/lexseal/Documents/sudoku /home/lexseal/Documents/sudoku/CMakeFiles/sudoku.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sudoku.dir/depend
