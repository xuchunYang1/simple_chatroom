#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <Protocol/common.h>
#include <wrap.h>
/*
* 功能：发送cmd给一个文件描述符
* 参数1：fd文件描述符
* 参数2：一个空的发送缓冲区
* 参数3：要发送的cmd
*
*/
int send_cmd(int fd,uint8_t *buffer,uint8_t cmd);

/*
* 功能：发送sign_in_up数据包
* 参数1：fd文件描述符
* 参数2：一个空的发送缓冲区
* 参数3：登录或注册 类型为 SignFlag ，参考imsg_sing_in_up.h
* 参数4：要发送的姓名或昵称
* 参数5：要发送的密码
*
*/
int send_sing_in_sign_up_struct(int fd,uint8_t *buffer,SignFlag flag,char *name,char *password);

/*
* 功能：发送imsg_conversation数据包
* 参数1：fd文件描述符
* 参数2：一个空的发送缓冲区
* 参数3：要发送给的对象名字
* 参数4：要发送的内容
*
*/
int send_conversation_struct(int fd,uint8_t *buffer,char *name,char *data);
#ifdef __cplusplus
}
#endif
