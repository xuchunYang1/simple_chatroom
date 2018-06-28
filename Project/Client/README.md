客户端开发简介：
1.首先进入Project/Client目录下面；
2.执行命令cmake .，如果提示没有cmake工具，执行sudo apt-get install cmake；
3.执行make编译工程；
4.如果有需要添加的源文件，修改该目录下的CMakeList.txt中的如下几行，可以加入文件的相对路径
add_executable(
				chatroom_client 
				../../modules/client/main.c
				../../modules/net/wrap.c
			  )
5.如果有需要设置路径，修改CMakeList.txt文件中的如下编译参数，路径之间使用空格，使用相对
路径即可：
set(USER_INCLUDES ../../modules/server ../../modules/ ../../modules/net )
