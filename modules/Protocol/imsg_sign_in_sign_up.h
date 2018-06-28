#pragma once
#include <stdio.h>
#include <stdint.h>

//消息ID号
#define IMSG_SIGN_IN_SIGN_UP_ID 1

#define NICKNAMELEN 64
#define PASSWORDLEN 64
#ifdef __cplusplus
extern "C" {
#endif
typedef enum
{
	SIGN_IN = 0x01,
	SIGN_UP = 0x02,
	LOGOUT = 0x03,
}SignFlag;
typedef struct _imsg_sign_in_sign_up
{
	SignFlag sign_flag;//注册或者登录标志
	char nickname[NICKNAMELEN];
	char password[PASSWORDLEN];
}imsg_sign_in_sign_up_t;

static inline uint16_t imsg_sign_in_sign_up_pack(imsg_t *msg,SignFlag signFlag,char *nickname,char *password)
{
	if(!msg || !nickname || !password)
		return 0;
	imsg_sign_in_sign_up_t temp;

	memset(&temp,0,sizeof(imsg_sign_in_sign_up_t));
	temp.sign_flag = signFlag;
	memcpy(temp.nickname,nickname,strlen(nickname));
	memcpy(temp.password,password,strlen(password));
		
	memcpy(msg->payload,&temp,sizeof(imsg_sign_in_sign_up_t));
	msg->msgid = IMSG_SIGN_IN_SIGN_UP_ID;
	msg->len = sizeof(imsg_sign_in_sign_up_t);
	return msg->len;
}
static inline uint16_t imsg_sign_in_sign_up_unpack(imsg_t *msg,imsg_sign_in_sign_up_t *out)
{
	if(!msg || !out)
		return 0;
	if(msg->len != sizeof(imsg_sign_in_sign_up_t))
	{
		return 0;
	}
	memcpy(out,msg->payload,msg->len);
	return msg->len;
}
#ifdef __cplusplus
}
#endif
