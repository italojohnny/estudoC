/*
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#define MAXLINE 4096

int my_connect (char *server, unsigned int port, int *sockfd);
int my_send(int sockfd, char *out, int debug);
int my_read(int sockfd, char *recvline, int debug);

int main (void)
{
	int sockfd, n, debug;
	char *cmd, *pos;
	char recvline[MAXLINE+1], out[MAXLINE+1];
	char server[] = "23.251.154.162";
	debug = 1;

	if (!my_connect(server, 6667, &sockfd)) {
		printf("Failed to connect to %s.\n", server);
		exit(1);
	}
	my_send(sockfd, "NICK mudpit3\r\n", debug);
	my_send(sockfd, "USER mudpit3 mudpit3 mudpit3 mudpit3\r\n", debug);
	my_send(sockfd, "PRIVMSGnickserv :iNOOPE\r\n", debug);

	while(1) {
		printf("--------------------teste1\n");
		recvline[0] = 0;
		n = my_read(sockfd, recvline, debug);
		if (n > 0) {
			printf("--------------------teste2\n");
			recvline[n] = 0;
			if (strstr(recvline, "PING") != NULL) {
	my_send(sockfd, "JOIN #bilada\n", debug);
	my_send(sockfd, "PRIVMSG #bilada : teste\n", debug);
				printf("--------------------teste3\n");
				out[0] = 0;
				pos = strstr(recvline, " ")+1;
				sprintf(out, "PONG %s\r\n", pos);
				my_send(sockfd, out, debug);
			}
		}
	}
}

int my_connect (char *server, unsigned int port, int *sockfd)
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

int my_send(int sockfd, char *out, int debug)
{
	if (debug)
		printf("OUT: %s", out);
	return send(sockfd, out, strlen(out), 0);
}

int my_read(int sockfd, char *recvline, int debug)
{
	int n = read(sockfd, recvline, MAXLINE);
	if (n > 0 && debug)
		printf("IN: %s", recvline);
	return n;
}
