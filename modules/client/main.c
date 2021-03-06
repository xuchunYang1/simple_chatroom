#include <stdio.h>

#include <imsg_api.h>
#include <wrap.h>
#include "fun.h"
#include <thread_pool.h>

#define SERV_PORT 8000
#define REMOTE_IP "192.168.100.120"


int main(int argc,char **argv)
{
	
	int i = 0;
	int ret = 0;
	uint8_t buffer[MAXLINE];
	SignFlag signflag;
	//摘自例程
	struct sockaddr_in servaddr;
	int sockfd;
	//int n;
    int reuse = 1; 
    
	sockfd = Socket(AF_INET, SOCK_STREAM, 0);
	
	if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0)
	{
		perror("setsockopet error\n");
		return -1;
	}
	
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET, REMOTE_IP, &servaddr.sin_addr);
	servaddr.sin_port = htons(SERV_PORT);
    
	Connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	
	pool_init(5);


	//注册登录逻辑		
	while(1)
	{	
		int value;
		printf("*****注册: 1**** 登录: 2*****\n");
		scanf("%d", &value);
		if (1 == value)
		{	
			sign_in(sockfd, buffer, signflag);
						
		}
		else if (2 == value)
		{
			sign_up(sockfd, buffer, signflag);
		}
		else
		{
			printf("输入不合法，重新输入\n");
			continue;			
		}
		
		
		
		//发送注册登录结构体
		//send_sing_in_sign_up_struct(sockfd,buffer,SIGN_IN,"yang","123");

		//发送cmd结构体
		//send_cmd(sockfd,buffer,CMD_SIGN_UP_SUCCESS);
	}

	Close(sockfd);
	return 0;
}
