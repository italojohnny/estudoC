#include <stdio.h>

void troca_errada (int x, int y);
void troca_certa (int *x, int *y);

int main (void)
{
	int a = 5, b = 7;
	
	troca_errada(a, b);
	printf(" %d %d \n", a, b);

	troca_certa(&a, &b);
	printf(" %d %d \n", a, b);

	return 0;
}

void troca_errada (int x, int y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void troca_certa (int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
