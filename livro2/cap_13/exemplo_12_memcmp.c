#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main (int argc, char *argv[])
{
	int outcome, len, l1, l2;

	if (argc != 3) {
		printf("Numero incorreto de paramentros.\n");
		exit(1);
	}

	/* encontra o comprimento da menor string */
	l1 = strlen(argv[1]);
	l2 = strlen(argv[2]);
	len = l1 < l2 ? l1 : l2;

	outcome = memcmp(argv[1], argv[2], len);
	if (!outcome) printf("Iguais\n");
	else if (outcome < 0) printf("Primeiro menor que segundo\n");
	else printf("Primeiro maior que segundo\n");
}
