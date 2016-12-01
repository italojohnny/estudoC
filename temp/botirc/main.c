#include "ircfunc.h"

int main (void)
{
	int sockfd, n, debug = 1;
	char server[] = "23.251.154.162";

	IRC:
	if (!conectar_irc(server, 6667, &sockfd)) {
		sleep(5);
		goto IRC;
	}




	printf("fim\n");
}
