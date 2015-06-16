#include <stdio.h>

int fat (int n);

int main (void)
{
	int n, r;
	printf("Entre com um numero inteiro: ");
	scanf("%d", &n);
	
	r = fat(n);
	printf("Fatoria %d ", r);
	
	return 0;
}

int fat (int n)
{
	if (n == 0)
		return 1;
	else
		return n*fat(n-1);
}
