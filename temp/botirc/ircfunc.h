#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#define MAXLINE 4096

int conectar_irc (char *server, unsigned int port, int *sockfd)
{
	struct sockaddr_in servadd;
	bzero(&servadd, sizeof(servadd));
	servadd.sin_family = AF_INET;
	servadd.sin_port = htons(port);

	if ((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		return 0;
	if (inet_pton(AF_INET, server, &servadd.sin_addr) <= 0)
		return 0;
	if (connect(*sockfd, (struct sockaddr*)&servadd, sizeof(servadd)) < 0)
		return 0;
	return 1;
}

