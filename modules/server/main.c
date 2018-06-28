#include <stdio.h>

#include <imsg_api.h>
#include <wrap.h>
#include <thread_pool.h>
#include <link.h>
#define MAXLINE 512
#define SERV_PORT 8000


imsg_parse_state_t status = 0;
imsg_t msg_out;
imsg_sign_in_sign_up_t data;
imsg_conversation_t data_send;
imsg_cmd cmd_struct;


int parse_process(uint8_t *data_recv, int count, int sockfd);

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
			printf("解析一个包成功 msg_id %d \n",msg_out.msgid);
			switch(msg_out.msgid)
			{
				case IMSG_SIGN_IN_SIGN_UP_ID:
					imsg_sign_in_sign_up_unpack(&msg_out,&data);//分析flag
					printf("SIGN message %s %s \n",data.nickname,data.password);
					//printf("SIGN_IN %x\n", data.sign_flag);
					if (data.sign_flag == SIGN_IN)
					{	
						if (find_name(data.nickname) == 0)
						{
							link_node_t *p = mk_node(data.nickname, data.password);
							insert_node(p);
							send_cmd(sockfd,buffer,CMD_SIGN_IN_SUCCESS);
						}
						else
						{
							send_cmd(sockfd,buffer,CMD_SIGN_IN_FAILED);
						}
						
					}
					else if (data.sign_flag == SIGN_UP)
					{
						if (find_name_pswd(data.nickname, data.password) == 0)
						{
							send_cmd(sockfd,buffer,CMD_SIGN_UP_SUCCESS);
							online_list_update(data.nickname, sockfd);							
						}
						else
						{
							send_cmd(sockfd,buffer,CMD_SIGN_UP_FAILED);
						}
					}
					
				break;
				case IMSG_CONVERSATION:
					imsg_conversation_unpack(&msg_out,&data_send);//分析flag
					printf("谈话数据包 name:%s data:%s \n",data_send.target_name,data_send.data);
					
					send_msg_someboby(data_send.target_name, sockfd, data_send.data);
					
				break;
				case IMSG_CMD:
					imsg_cmd_unpack(&msg_out,&cmd_struct);//分析flag
					printf("cmd %d \n",cmd_struct.cmd);
				break;
			}
		}
	}
	printf("\n");
}


void *func2(void *argv)
{
	while(1)
	{
		printf("func2\n");
		sleep(1);
	}
}
//这是一个线程池测试的main
int main2(int argc,char **argv)
{
	pool_init(5);

	pool_add_worker(func2,NULL);
	while(1);
	return 0;
}
//这是一个消息发送解析的main
int main(int argc,char **argv)
{
	imsg_t msg_send;
	imsg_parse_state_t status;
	//摘自例程
	int i, maxi, maxfd, listenfd, connfd, sockfd;
	int nready, client[FD_SETSIZE];
	ssize_t n;
	fd_set rset, allset;
	uint8_t buf[MAXLINE];
	char str[INET_ADDRSTRLEN];
	socklen_t cliaddr_len;
	struct sockaddr_in	cliaddr, servaddr;
	int reuse = 1; 
	
	listenfd = Socket(AF_INET, SOCK_STREAM, 0);

	if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0)
	{
		perror("setsockopet error\n");
		return -1;
	}
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family      = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port        = htons(SERV_PORT);

	Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	Listen(listenfd, 20);

	maxfd = listenfd;		/* initialize */
	maxi = -1;			/* index into client[] array */
	for (i = 0; i < FD_SETSIZE; i++)
		client[i] = -1;	/* -1 indicates available entry */
	FD_ZERO(&allset);
	FD_SET(listenfd, &allset);
	
	
	add_user_to_list(); //建立用户链表
	
	
	printf("This is server proess \n");
	for ( ; ; ) 
	{
		rset = allset;	/* structure assignment */
		nready = select(maxfd+1, &rset, NULL, NULL, NULL);
		
		if (nready < 0)
			perr_exit("select error");

		if (FD_ISSET(listenfd, &rset)) 
		{ /* new client connection */
			cliaddr_len = sizeof(cliaddr);
			connfd = Accept(listenfd, (struct sockaddr *)&cliaddr, &cliaddr_len);
			
			
			printf("connected fd = %d \n",connfd);
			printf("received from %s at PORT %d\n",
			       inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),
			       ntohs(cliaddr.sin_port));

			for (i = 0; i < FD_SETSIZE; i++)
			{
				if (client[i] < 0) 
				{
					client[i] = connfd; /* save descriptor */
					break;
				}
			}
			if (i == FD_SETSIZE) 
			{
				fputs("too many clients\n", stderr);
				exit(1);
			}

			FD_SET(connfd, &allset);	/* add new descriptor to set */
			if (connfd > maxfd)
				maxfd = connfd; /* for select */
			if (i > maxi)
				maxi = i;	/* max index in client[] array */

			if (--nready == 0)
				continue;	/* no more readable descriptors */
		}

		for (i = 0; i <= maxi; i++) 
		{	/* check all clients for data */
			if ( (sockfd = client[i]) < 0)
				continue;
			if (FD_ISSET(sockfd, &rset)) 
			{
				if ( (n = Read(sockfd, buf, MAXLINE)) == 0) 
				{
					printf("come to close\n");
					/* connection closed by client */
					Close(sockfd);
					FD_CLR(sockfd, &allset);
					client[i] = -1;
				}
				else 
				{
					//开始解析客户端发送的数据包：
					parse_process(buf, n, sockfd);
				}

				if (--nready == 0)
					break;	/* no more readable descriptors */
			}
		}
	}
	return 0;
}
