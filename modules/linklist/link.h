#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#define FILENAME "user_info.txt"
#ifdef __cplusplus
extern "C"{
#endif

typedef struct link_node
{
	char nickname[20];
	char password[20];
	int fd;
	bool online;
	struct link_node *next;
}link_node_t;



#ifdef __cplusplus
}
#endif

