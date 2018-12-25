#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main (void) {
	int sock;
	struct sockaddr_in server;
	char message[1000], server_reply[2000];

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1)
		puts("Nao foi possivel criar o socket");
	puts("Socket criado");

	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(8888);

	if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
		perror("Erro. Falha ao conectar");
		return 1;
	}
	puts("Conectado");

	while (1) {
		printf("mensagem: ");
		scanf("%s", message);

		if (send(sock, message, strlen(message), 0) < 0) {
			puts("Falha ao enviar");
			return 1;
		}

		if (recv(sock, server_reply, 2000, 0) < 0) {
			puts("Falha ao receber");
			break;
		}
		printf("Resposta do servidor: %s", server_reply);
		
	}
	close(sock);

	return 0;
}
