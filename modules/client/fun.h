#pragma once
#include <imsg_api.h>
#include <thread_pool.h>


#define MAXLINE 512
int sign_up(int sockfd, uint8_t *buffer, SignFlag signflag);

int parse_process(uint8_t *data_recv, int count, int sockfd);

int sign_in(int sockfd, uint8_t *buffer, SignFlag signflag);//注册
/*
* 功能：接受服务器消息的入口函数
* 参数1：参数指针p
*
*/
void *recv_process(void *p);
