#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main (int argc, char *argv[])
{
	if (argc != 3) {
		printf("Numero incorreto de parametros.\n");
		exit(1);
	}

	if (!strncmp(argv[1], argv[2], 8))
		printf("Os nomes de arquivos sao iguais.\n");
}
