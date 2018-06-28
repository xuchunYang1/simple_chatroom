# This is a templet of cmake config file
# Author Yang 2017-05-10
# TODO:Auto Detect compile environment
# Brief: (sign '#' )
#		(1) Mutiple thread program need have these configures:
#			1) #find_package(Threads)
#			2) #target_link_libraries(FPGA_camera ${CMAKE_THREAD_LIBS_INIT})
#		(2) Debug your executable 
#			1) if you have no idea about ->gdb<-,learn how to use it
#			2) in this project,if you want active debug mode,Use Macro (IDEBUG) or have following configuretions,
#			..Debug configuretions:
#									#SET(CMAKE_BUILD_TYPE "Debug") 
#									#SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
#									#SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
#
#
#

cmake_minimum_required(VERSION 2.8)


set(CMAKE_SYSTEM_NAME Linux)

# Define project name
project(chatroom_server)

# gdb mode debug
SET(CMAKE_BUILD_TYPE "Debug") 
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# set compile flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

# Set user include directory
set(USER_INCLUDES ../../modules/server ../../modules/ ../../modules/net ../../modules/thread_pool ../../modules/linklist )

#Find libs
find_package(Threads)

# Add headers location to your include paths
include_directories(${USER_INCLUDES})

# Declare the executable target built from your sources
add_executable(
				chatroom_server 
				../../modules/server/main.c
				../../modules/net/wrap.c
				../../modules/net/imsg_api.c
				../../modules/thread_pool/thread_pool.c
				../../modules/linklist/link.c
			  )

#可执行程序链接库文件
target_link_libraries(chatroom_server ${CMAKE_THREAD_LIBS_INIT})

