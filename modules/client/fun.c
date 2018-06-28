#include "fun.h"
#include <stdbool.h>

char nickname[NICKNAMELEN];
char password[PASSWORDLEN];
imsg_parse_state_t status = 0;
imsg_t msg_out;
imsg_sign_in_sign_up_t data;
imsg_conversation_t data_send;
imsg_cmd cmd_struct;
int sign_in(int sockfd, uint8_t *buffer, SignFlag signflag) //注册
{
	int n;	
	while (1)
	{
		printf("********开始注册********\n");
		signflag = SIGN_IN;
		printf("请输入用户名：");
		scanf("%s", nickname);
		printf("请输入密码：");
		scanf("%s", password);
		send_sing_in_sign_up_struct(sockfd, buffer, signflag, nickname, password);
		n = Read(sockfd, buffer, MAXLINE);
		parse_process(buffer, n, sockfd);
		if (cmd_struct.cmd == CMD_SIGN_IN_SUCCESS)
		{
			printf("注册成功，请开始登录\n");
			break;
		}
		else if (cmd_struct.cmd == CMD_SIGN_IN_FAILED)
		{
			printf("已被注册过，请重新注册\n");
			continue;
		}
	}	
}

int sign_up(int sockfd, uint8_t *buffer, SignFlag signflag)
{
	int n;
	uint8_t buf[128];
	uint8_t buffer_send[512];
	char target_name[20];
	while (1)
	{
		printf("********开始登录********\n");
		signflag = SIGN_UP;
		printf("请输入用户名：");
		scanf("%s", nickname);
		printf("请输入密码：");
		scanf("%s", password);
		send_sing_in_sign_up_struct(sockfd, buffer, signflag, nickname, password);
		n = Read(sockfd, buffer, MAXLINE);
		parse_process(buffer, n, sockfd);
		if (cmd_struct.cmd == CMD_SIGN_UP_SUCCESS)
		{
			printf("登录成功，请开始聊天\n");
			pool_add_worker(recv_process,&sockfd);
			while (1)
			{	
				
				printf("输入要发送的消息：");
				
				scanf("%s %s", target_name, buf);
				send_conversation_struct(sockfd,buffer_send,target_name,buf);
			}
		}
		else if (cmd_struct.cmd == CMD_SIGN_UP_FAILED)
		{
			printf("用户名和密码不匹配，请重新登录\n");
		}
	}	
}


int parse_process(uint8_t *data_recv, int count, int sockfd)
{	
	uint8_t buffer[MAXLINE];
	int i,ret = -1;
	if(!data_recv || count < 0)
		return -1;
	
	for(i=0;i<count;i++)
	{
		ret = imsg_parse_char(&msg_out,&status,data_recv[i]);
		if(ret == 0)
		{
			switch(msg_out.msgid)
			{
				case IMSG_CONVERSATION:
					imsg_conversation_unpack(&msg_out,&data_send);//分析flag
					printf("%s 说: %s \n",data_send.target_name,data_send.data);
				break;
				
				case IMSG_CMD:
					imsg_cmd_unpack(&msg_out,&cmd_struct);//分析flag
					printf("cmd %d \n",cmd_struct.cmd);
					
				break;
			}
		}
	}
}
/*
* 功能：接受服务器消息的入口函数
* 参数1：参数指针p
*
*/
void *recv_process(void *p)
{
	bool exit_flag = false;
	int sockfd = *((int *)p);
	int n;
	uint8_t buf[128];
	uint8_t buffer_read[MAXLINE];
	while(!exit_flag)
	{
		n = Read(sockfd, buffer_read, MAXLINE);
		parse_process(buffer_read, n, sockfd);
	}
}
