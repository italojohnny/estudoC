/* programa que le um numero e imprime seu fatorial */

#include <stdio.h>

int fat (int n);

/* Funcao principal */
int main (void)
{
	int n, r;
	printf("entre com um numero inteiro: ");
	scanf("%d", &n);
	r = fat(n);
	printf("Fatoria = %d\n", r);
	return 0;
}

/* Funcao para imprimir o valor do fatorial */
int fat (int n)
{
	
	int f = 1;
	while (n != 0) {
		f *= n;
		n--;
	}
	return f; //printf("Fatorial = %d\n", f);
}
