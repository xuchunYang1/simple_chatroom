#pragma once
#include <stdio.h>
#include <stdint.h>

//消息ID号
#define IMSG_CMD 3

#define NICKNAMELEN 64
#define PASSWORDLEN 64
#ifdef __cplusplus
extern "C" {
#endif

typedef struct _imsg_cmd
{
	uint8_t cmd;
}imsg_cmd;

static inline uint16_t imsg_cmd_pack(imsg_t *msg,uint8_t cmd)
{
	if(!msg)
		return 0;
	imsg_cmd temp;
	temp.cmd = cmd;
	memcpy(msg->payload,&temp,sizeof(imsg_cmd));
	msg->msgid = IMSG_CMD;
	msg->len = sizeof(imsg_cmd);
	return msg->len;
}
static inline uint16_t imsg_cmd_unpack(imsg_t *msg,imsg_cmd *out)
{
	if(!msg || !out)
		return 0;
	if(msg->len != sizeof(imsg_cmd))
	{
		return 0;
	}
	memcpy(out,msg->payload,msg->len);
	return msg->len;
}
#ifdef __cplusplus
}
#endif
