#pragma once
#include <stdio.h>
#include <stdint.h>

#define PAYLOADLEN 1024*2

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _imsg
{
	uint16_t checksum;//校验值 crc16
	uint16_t len;//payload的长度
	uint16_t seq;//消息序列号
	uint8_t msgid;//消息ID号
	uint8_t payload[PAYLOADLEN];//存放数据
}imsg_t;

typedef enum
{
	IMSG_PARSE_STATE_UNINIT = 0,
	IMSG_PARSE_STATE_IDLE,
	IMSG_PARSE_STATE_GOT_STX1,
	IMSG_PARSE_STATE_GOT_STX2,
	IMSG_PARSE_STATE_GOT_LEN_H,
	IMSG_PARSE_STATE_GOT_LEN_L,
	IMSG_PARSE_STATE_GOT_SEQ,
	IMSG_PARSE_STATE_GOT_MSGID,
	IMSG_PARSE_STATE_GOT_PAYLOAD,
	IMSG_PARSE_STATE_GOT_CRC_H,
	IMSG_PARSE_STATE_GOT_CRC_L,
	IMSG_PARSE_STATE_GOT_BAD_CRC,
	IMSG_PARSE_STATE_GOT_COMPLETE,
}imsg_parse_state_t;

typedef enum
{
	CMD_SIGN_IN = 0,
	CMD_SIGN_IN_SUCCESS,
	CMD_SIGN_IN_FAILED,
	CMD_SIGN_UP,
	CMD_SIGN_UP_SUCCESS,
	CMD_SIGN_UP_FAILED,
	CMD_MSG_SEND_SUCCESS,
	CMD_MSG_SEND_FAILED,
}chat_room_cmd;
#ifdef __cplusplus
}
#endif
