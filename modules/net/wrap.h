#pragma once
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#ifdef __cplusplus
extern "C" {
#endif

void perr_exit(const char *s);

int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr);

void Bind(int fd, const struct sockaddr *sa, socklen_t salen);

void Connect(int fd, const struct sockaddr *sa, socklen_t salen);


void Listen(int fd, int backlog);


int Socket(int family, int type, int protocol);


ssize_t Read(int fd, void *ptr, size_t nbytes);

ssize_t Write(int fd, const void *ptr, size_t nbytes);


void Close(int fd);

ssize_t Readn(int fd, void *vptr, size_t n);


ssize_t Writen(int fd, const void *vptr, size_t n);


static ssize_t my_read(int fd, char *ptr);


ssize_t Readline(int fd, void *vptr, size_t maxlen);

#ifdef __cplusplus
}
#endif
