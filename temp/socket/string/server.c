#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main (void) {
	int socket_desc, client_sock, c, read_size;
	struct sockaddr_in server, client;
	char client_message[2000];

	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_desc == -1)
		puts("Nao foi possivel criar o socket");
	puts("")
}
