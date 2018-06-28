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
project(chatroom_client)

#设置编译参数
SET(CMAKE_BUILD_TYPE "Debug") 
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# set compile flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

#设置include路径
set(USER_INCLUDES ../../modules/server ../../modules/ ../../modules/net ../../modules/thread_pool)

#设置编译时依赖的库
find_package(Threads)

# Add headers location to your include paths
include_directories(${USER_INCLUDES})

#设置源文件 .c .cpp，使用相对路径
add_executable(
				chatroom_client 
				../../modules/client/main.c
				../../modules/net/wrap.c
				../../modules/net/imsg_api.c
				../../modules/client/fun.c
				../../modules/thread_pool/thread_pool.c
			  )

# Link your application with OpenCV libraries and other necessary libs(such as :libpthread ... libopengl ... libxxx)
target_link_libraries(chatroom_client ${CMAKE_THREAD_LIBS_INIT})

