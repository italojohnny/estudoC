#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int *v;
	v = (int*)malloc(10*sizeof(int));
	if (v == NULL) {
		printf("Memoria insuficiente.\n");
		exit(1); //aborta o programa e retorna 1 para o SO
	}

	return 0;
}
