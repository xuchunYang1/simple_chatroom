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
CMAKE_SOURCE_DIR = /home/yang/xuchun/Pros/chatRoomNew/Project/Server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yang/xuchun/Pros/chatRoomNew/Project/Server

# Include any dependencies generated for this target.
include CMakeFiles/chatroom_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/chatroom_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chatroom_server.dir/flags.make

CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/server/main.c.o: CMakeFiles/chatroom_server.dir/flags.make
CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/server/main.c.o: /home/yang/xuchun/Pros/chatRoomNew/modules/server/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yang/xuchun/Pros/chatRoomNew/Project/Server/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/server/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/server/main.c.o   -c /home/yang/xuchun/Pros/chatRoomNew/modules/server/main.c

CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/server/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/server/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yang/xuchun/Pros/chatRoomNew/modules/server/main.c > CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/server/main.c.i

CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/server/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/server/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yang/xuchun/Pros/chatRoomNew/modules/server/main.c -o CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/server/main.c.s

CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/server/main.c.o.requires:

.PHONY : CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/server/main.c.o.requires

CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/server/main.c.o.provides: CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/server/main.c.o.requires
	$(MAKE) -f CMakeFiles/chatroom_server.dir/build.make CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/server/main.c.o.provides.build
.PHONY : CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/server/main.c.o.provides

CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/server/main.c.o.provides.build: CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/server/main.c.o


CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/wrap.c.o: CMakeFiles/chatroom_server.dir/flags.make
CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/wrap.c.o: /home/yang/xuchun/Pros/chatRoomNew/modules/net/wrap.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yang/xuchun/Pros/chatRoomNew/Project/Server/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/wrap.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/wrap.c.o   -c /home/yang/xuchun/Pros/chatRoomNew/modules/net/wrap.c

CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/wrap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/wrap.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yang/xuchun/Pros/chatRoomNew/modules/net/wrap.c > CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/wrap.c.i

CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/wrap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/wrap.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yang/xuchun/Pros/chatRoomNew/modules/net/wrap.c -o CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/wrap.c.s

CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/wrap.c.o.requires:

.PHONY : CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/wrap.c.o.requires

CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/wrap.c.o.provides: CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/wrap.c.o.requires
	$(MAKE) -f CMakeFiles/chatroom_server.dir/build.make CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/wrap.c.o.provides.build
.PHONY : CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/wrap.c.o.provides

CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/wrap.c.o.provides.build: CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/wrap.c.o


CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/imsg_api.c.o: CMakeFiles/chatroom_server.dir/flags.make
CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/imsg_api.c.o: /home/yang/xuchun/Pros/chatRoomNew/modules/net/imsg_api.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yang/xuchun/Pros/chatRoomNew/Project/Server/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/imsg_api.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/imsg_api.c.o   -c /home/yang/xuchun/Pros/chatRoomNew/modules/net/imsg_api.c

CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/imsg_api.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/imsg_api.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yang/xuchun/Pros/chatRoomNew/modules/net/imsg_api.c > CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/imsg_api.c.i

CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/imsg_api.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/imsg_api.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yang/xuchun/Pros/chatRoomNew/modules/net/imsg_api.c -o CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/imsg_api.c.s

CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/imsg_api.c.o.requires:

.PHONY : CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/imsg_api.c.o.requires

CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/imsg_api.c.o.provides: CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/imsg_api.c.o.requires
	$(MAKE) -f CMakeFiles/chatroom_server.dir/build.make CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/imsg_api.c.o.provides.build
.PHONY : CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/imsg_api.c.o.provides

CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/imsg_api.c.o.provides.build: CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/imsg_api.c.o


CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/thread_pool/thread_pool.c.o: CMakeFiles/chatroom_server.dir/flags.make
CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/thread_pool/thread_pool.c.o: /home/yang/xuchun/Pros/chatRoomNew/modules/thread_pool/thread_pool.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yang/xuchun/Pros/chatRoomNew/Project/Server/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/thread_pool/thread_pool.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/thread_pool/thread_pool.c.o   -c /home/yang/xuchun/Pros/chatRoomNew/modules/thread_pool/thread_pool.c

CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/thread_pool/thread_pool.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/thread_pool/thread_pool.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yang/xuchun/Pros/chatRoomNew/modules/thread_pool/thread_pool.c > CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/thread_pool/thread_pool.c.i

CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/thread_pool/thread_pool.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/thread_pool/thread_pool.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yang/xuchun/Pros/chatRoomNew/modules/thread_pool/thread_pool.c -o CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/thread_pool/thread_pool.c.s

CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/thread_pool/thread_pool.c.o.requires:

.PHONY : CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/thread_pool/thread_pool.c.o.requires

CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/thread_pool/thread_pool.c.o.provides: CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/thread_pool/thread_pool.c.o.requires
	$(MAKE) -f CMakeFiles/chatroom_server.dir/build.make CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/thread_pool/thread_pool.c.o.provides.build
.PHONY : CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/thread_pool/thread_pool.c.o.provides

CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/thread_pool/thread_pool.c.o.provides.build: CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/thread_pool/thread_pool.c.o


CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/linklist/link.c.o: CMakeFiles/chatroom_server.dir/flags.make
CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/linklist/link.c.o: /home/yang/xuchun/Pros/chatRoomNew/modules/linklist/link.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yang/xuchun/Pros/chatRoomNew/Project/Server/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/linklist/link.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/linklist/link.c.o   -c /home/yang/xuchun/Pros/chatRoomNew/modules/linklist/link.c

CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/linklist/link.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/linklist/link.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yang/xuchun/Pros/chatRoomNew/modules/linklist/link.c > CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/linklist/link.c.i

CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/linklist/link.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/linklist/link.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yang/xuchun/Pros/chatRoomNew/modules/linklist/link.c -o CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/linklist/link.c.s

CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/linklist/link.c.o.requires:

.PHONY : CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/linklist/link.c.o.requires

CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/linklist/link.c.o.provides: CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/linklist/link.c.o.requires
	$(MAKE) -f CMakeFiles/chatroom_server.dir/build.make CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/linklist/link.c.o.provides.build
.PHONY : CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/linklist/link.c.o.provides

CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/linklist/link.c.o.provides.build: CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/linklist/link.c.o


# Object files for target chatroom_server
chatroom_server_OBJECTS = \
"CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/server/main.c.o" \
"CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/wrap.c.o" \
"CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/imsg_api.c.o" \
"CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/thread_pool/thread_pool.c.o" \
"CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/linklist/link.c.o"

# External object files for target chatroom_server
chatroom_server_EXTERNAL_OBJECTS =

chatroom_server: CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/server/main.c.o
chatroom_server: CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/wrap.c.o
chatroom_server: CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/imsg_api.c.o
chatroom_server: CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/thread_pool/thread_pool.c.o
chatroom_server: CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/linklist/link.c.o
chatroom_server: CMakeFiles/chatroom_server.dir/build.make
chatroom_server: CMakeFiles/chatroom_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yang/xuchun/Pros/chatRoomNew/Project/Server/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable chatroom_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chatroom_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chatroom_server.dir/build: chatroom_server

.PHONY : CMakeFiles/chatroom_server.dir/build

CMakeFiles/chatroom_server.dir/requires: CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/server/main.c.o.requires
CMakeFiles/chatroom_server.dir/requires: CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/wrap.c.o.requires
CMakeFiles/chatroom_server.dir/requires: CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/net/imsg_api.c.o.requires
CMakeFiles/chatroom_server.dir/requires: CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/thread_pool/thread_pool.c.o.requires
CMakeFiles/chatroom_server.dir/requires: CMakeFiles/chatroom_server.dir/home/yang/xuchun/Pros/chatRoomNew/modules/linklist/link.c.o.requires

.PHONY : CMakeFiles/chatroom_server.dir/requires

CMakeFiles/chatroom_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chatroom_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chatroom_server.dir/clean

CMakeFiles/chatroom_server.dir/depend:
	cd /home/yang/xuchun/Pros/chatRoomNew/Project/Server && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yang/xuchun/Pros/chatRoomNew/Project/Server /home/yang/xuchun/Pros/chatRoomNew/Project/Server /home/yang/xuchun/Pros/chatRoomNew/Project/Server /home/yang/xuchun/Pros/chatRoomNew/Project/Server /home/yang/xuchun/Pros/chatRoomNew/Project/Server/CMakeFiles/chatroom_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/chatroom_server.dir/depend

