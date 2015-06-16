#include <stdio.h>

void imprime (float a);

int main (void)
{
	float f;
	printf("Entre com um numero flutuante: ");
	scanf("%f", &f);

	imprime(f);

	return 0;
}

void imprime (float a)
{
	static int n = 1;
	printf(" %f ", a);
	if ((n % 5) == 0)
		printf("\n");
	n++;
}
