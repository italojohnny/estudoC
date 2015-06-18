#include <stdio.h>

void copia (char*, char*);

int main (void)
{
	char A[30] = "italo johnny dos anjos";
	char B[30];

	copia (A, B);

	printf("A: %s\nB: %s\n", A, B);
	return 0;
}

void copia (char* orig, char* dest)
{
	int i = 0;
	while (*(orig+i) != '\0') {
		*(dest+i) = *(orig+i);
		i++;
		*(dest+i) = '\0';
	}
	printf("terminou\n");
}
