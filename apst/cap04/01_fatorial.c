/* programa que le um numero e imprime seu fatorial */

#include <stdio.h>

void fat (int n);

/* Funcao principal */
int main (void)
{
	int n;
	printf("entre com um numero inteiro: ");
	scanf("%d", &n);
	fat(n);
	return 0;
}

/* Funcao para imprimir o valor do fatorial */
void fat (int n)
{
	int i;
	int f = 1;
	for (i = 1; i <= n; i++)
		f *= i;
	printf("Fatorial = %d\n", f);
}
