#pragma once
#include <stdio.h>
#include <stdint.h>

//消息ID号
#define IMSG_CONVERSATION 2

#define MESSAGELEN 128
//要发送给的人或组的名字
#define TARGETNAMELEN 64

#ifdef __cplusplus
extern "C" {
#endif
//这个枚举主要目的是：定义消息发送给个人还是群组
typedef enum 
{
	TARGET_IS_PEOPLE = 0x01,
	TARGET_IS_GROUP = 0x02,
}TargetFlag;

typedef struct _imsg_conversation
{
	TargetFlag target_flag;//定义消息发送给个人还是群组
	char target_name[TARGETNAMELEN];
	char data[MESSAGELEN];
}imsg_conversation_t;

static inline uint16_t imsg_conversation_pack(imsg_t *msg,char *target_name,char *data_send)
{
	if(!msg || !target_name || !data_send)
		return 0;
	imsg_conversation_t temp;
	memset(&temp,0,sizeof(imsg_conversation_t));
	memcpy(temp.target_name,target_name,strlen(target_name));
	memcpy(temp.data,data_send,strlen(data_send));
	memcpy(msg->payload,&temp,sizeof(imsg_conversation_t));
	msg->msgid = IMSG_CONVERSATION;
	msg->len = sizeof(imsg_conversation_t);
	return msg->len;
}
static inline uint16_t imsg_conversation_unpack(imsg_t *msg,imsg_conversation_t *out)
{
	if(!msg || !out)
		return 0;
	if(msg->len != sizeof(imsg_conversation_t))
	{
		return 0;
	}
	memcpy(out,msg->payload,msg->len);
	return msg->len;
}
#ifdef __cplusplus
}
#endif
