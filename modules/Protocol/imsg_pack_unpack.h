#pragma once
#include <string.h>

#define IMSG_HEADER_LEN 7
#define IMSG_STX1 0xfe
#define IMSG_STX2 0xfd

#ifdef __cplusplus
extern "C" {
#endif
static inline uint16_t UpdateCRC16(uint16_t crcIn,uint8_t byte)
{
	uint32_t crc = crcIn;
	uint32_t in = byte|0x100;
	do
	{
		crc <<= 1;
		in <<= 1;
		if(in&0x100)
			++crc;
		if(crc&0x10000)
			crc ^= 0x1021;
	}while(!(in&0x10000));
	return crc&0xffffu;
}
static inline uint16_t crc16(const uint8_t* data,uint32_t size)
{
	uint32_t crc = 0;
	const uint8_t* dataEnd = data+size;
	while(data<dataEnd)
		crc = UpdateCRC16(crc,*data++);
	crc = UpdateCRC16(crc,0);
	crc = UpdateCRC16(crc,0);
	return crc&0xffffu;
}

static inline uint16_t imsg_to_send_buffer(uint8_t *buf,imsg_t *msg)
{
	uint16_t crc = 0x0000;
	if(!buf || !msg)
		return 0;
	buf[0] = IMSG_STX1;
	buf[1] = IMSG_STX2;
	buf[2] = msg->msgid;
	buf[3] = (uint8_t)(msg->len & 0xFF);
	buf[4] = (uint8_t)(msg->len >> 8);
	
	crc = crc16(msg->payload,msg->len);
	buf[5] = (uint8_t)(crc & 0xFF);
	buf[6] =  (uint8_t)(crc >> 8);
	
	memcpy(&buf[7],msg->payload,msg->len);
	return IMSG_HEADER_LEN+msg->len;
}

static inline int imsg_parse_char(imsg_t* out_msg,imsg_parse_state_t *status,uint8_t c)
{
	static imsg_t rxmsg;
	static int payload_index = 0;
	if(!out_msg || !status)
		return -1;
	switch(*status)
	{
		case IMSG_PARSE_STATE_UNINIT:
		case IMSG_PARSE_STATE_IDLE:
			if(c == IMSG_STX1)
			{
				*status = IMSG_PARSE_STATE_GOT_STX1;
				memset(out_msg,0,sizeof(imsg_t));
				payload_index = 0;
			}
		break;
		case IMSG_PARSE_STATE_GOT_STX1:
			if(c == IMSG_STX2)
			{
				*status = IMSG_PARSE_STATE_GOT_STX2;
			}
		break;
		case IMSG_PARSE_STATE_GOT_STX2:
			*status = IMSG_PARSE_STATE_GOT_MSGID;
			out_msg->msgid = c;
		break;
		case IMSG_PARSE_STATE_GOT_MSGID:
			*status = IMSG_PARSE_STATE_GOT_LEN_L;
			out_msg->len = c;
		break;
		case IMSG_PARSE_STATE_GOT_LEN_L:
			*status = IMSG_PARSE_STATE_GOT_LEN_H;
			out_msg->len += c << 8;
		break;
		case IMSG_PARSE_STATE_GOT_LEN_H:
			*status = IMSG_PARSE_STATE_GOT_CRC_L;
			out_msg->checksum = c;
		break;
		case IMSG_PARSE_STATE_GOT_CRC_L:
			*status = IMSG_PARSE_STATE_GOT_CRC_H;
			out_msg->checksum += c << 8;
		break;
		case IMSG_PARSE_STATE_GOT_CRC_H:
			*status = IMSG_PARSE_STATE_GOT_PAYLOAD;
			out_msg->payload[payload_index++] = c;
			if(out_msg->len == payload_index)
			{
				if(out_msg->checksum == crc16(out_msg->payload,out_msg->len))
				{
					*status = IMSG_PARSE_STATE_GOT_COMPLETE;
				}
				else
				{
					*status = IMSG_PARSE_STATE_GOT_BAD_CRC;
				}
			}
		break;
		case IMSG_PARSE_STATE_GOT_PAYLOAD:
			if(payload_index >= out_msg->len - 1)
			{
				if(c == IMSG_STX1)
				{
					*status = IMSG_PARSE_STATE_GOT_STX1;
					memset(out_msg,0,sizeof(imsg_t));
					payload_index = 0;
				}
				else
				{
					out_msg->payload[payload_index++] = c;
				}
				if(out_msg->checksum == crc16(out_msg->payload,out_msg->len))
				{
					*status = IMSG_PARSE_STATE_GOT_COMPLETE;
				}
				else
				{
					*status = IMSG_PARSE_STATE_GOT_BAD_CRC;
				}
			}
			else
			{
				out_msg->payload[payload_index++] = c;
			}
		break;
	}
	if(*status == IMSG_PARSE_STATE_GOT_COMPLETE)
	{
		*status = IMSG_PARSE_STATE_IDLE;
		return 0;
	}
	else
	{
		return -1;
	}
}	
#ifdef __cplusplus
}
#endif
