#include "link.h"

link_node_t *head = NULL;

link_node_t *mk_node(char *name, char *pswd)
{
	link_node_t *p = malloc(sizeof(link_node_t));
	if (p == NULL)
	{
		printf("malloc failed\n");
		exit(1);
	}
	strcpy(p->nickname, name);
	strcpy(p->password, pswd);
	p->fd = -1;
	p->online = false;
	p->next = NULL;
}

void free_node(link_node_t *p)
{
	free(p);
	p = NULL;
}

void insert_node(link_node_t *p)
{
	p->next = head;
	head = p;
}

void traverse()
{
	link_node_t *p = head;
	while (p != NULL)
	{
		printf("%s ", p->nickname);
		p = p->next;
	}
	printf("\n");
}

int find_name(char *name)
{
	link_node_t *p = head;
	while (p != NULL)
	{
		if (strcmp(p->nickname, name) == 0)
		{
			//printf("昵称 %s 已被注册\n");
			return 1;
		}
		p = p->next;
	}
	return 0;
}
int find_name_pswd(char *name, char *pswd)
{
	link_node_t *p = head;
	while (p != NULL)
	{
		if (strcmp(p->nickname, name) == 0 
			&& strcmp(p->password, pswd) == 0)
		{
			
			return 0;
		}
		p = p->next;
	}
	return 1;
}



int find_name_fd(char *name)
{
	link_node_t *p = head;
	while (p != NULL)
	{
		if (strcmp(p->nickname, name) == 0)
		{
			return p->fd;
		}
		p = p->next;
	}
	return -1;
}

char *find_fd(fd)
{
	link_node_t *p = head;
	while (p != NULL)
	{
		if (p->fd == fd)
		{			 
			return p->nickname;
		}
		p = p->next;
	}
	return NULL;
}

int send_msg_someboby(char *name, int fd, char *data)
{
	uint8_t buffer[512];
	int confd = find_name_fd(name);
	char *who_send = find_fd(fd);
	printf("confd %d who_send %s\n", confd, who_send);
	send_conversation_struct(confd, buffer, who_send, data);	
}


int delete_node(char *name)
{
	link_node_t *p = head;
	link_node_t *q = NULL;
	if (head == NULL)
		return 1;
	if (strcmp(p->nickname, name) == 0)
	{
		head = p->next;
		return 0;
	}
	else
	{
		while (p != NULL)
		{	
			q = p;
			p = p->next;
			if (p->next == NULL
				&& strcmp(p->nickname, name) == 0)
			{
				q->next = NULL;
				return 0;
			}
			if (p->next != NULL 
				&& strcmp(p->nickname, name) == 0)
			{
				q->next = p->next;
				return 0;
			}			
		}
	}	
}


void destory(link_node_t *p)
{
	link_node_t *q = NULL;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		free_node(q);
	}
}

int add_user_to_list()
{
	link_node_t data_read;
	FILE *p_data_file = fopen(FILENAME, "r+");
	if (!p_data_file)
	{
		char cmd[50];
		printf("warning %s is not exist,now create it\n",FILENAME);
		sprintf(cmd,"touch %s",FILENAME);
		system(cmd);
	}
	
	while (!feof(p_data_file))
	{
		int ret;
		ret = fscanf(p_data_file, "%s %s", data_read.nickname, data_read.password);
		if (ret == -1)
		{
			break;
		}
		//fprintf(stdout, "%s %s\n", data_read.nickname, data_read.password);
		link_node_t *p = mk_node(data_read.nickname, data_read.password);

		insert_node(p);
	}
	
	//traverse();
	fclose(p_data_file);
}


int update_user_to_file()
{
	link_node_t *p = head;
	FILE *p_data_file = fopen(FILENAME, "r+");
	if (!p_data_file)
	{
		char cmd[50];
		printf("warning %s is not exist,now create it\n",FILENAME);
		sprintf(cmd,"touch %s",FILENAME);
		system(cmd);
	}
	
	while (p != NULL)
	{
		fprintf(p_data_file, "%s %s", p->nickname, p->password);
		p = p->next;
	}
	printf("\n");
}

int online_list_update(char *name, int sockfd)
{
	link_node_t *p = head;
	while (p != NULL)
	{
		if (strcmp(p->nickname, name) == 0)
		{
			p->fd = sockfd;
			p->online = true;
			fprintf(stdout, "p->fd %d  p->online %d\n", p->fd, p->online);
			
			break;
		}
		p = p->next;
	}
}


