#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* duplica (char*);

int main (void)
{
	char A[81] = "Italo Johnny dos Anjos";
	char *B;

	B = duplica(A);

	printf("A: %s\nB: %s\n", A, B);
	return 0;
}

char* duplica (char* s)
{
	int n = strlen(s);
	char* d = (char*)malloc((n+1)*sizeof(char));
	strcpy(d, s);

	return d;
}
