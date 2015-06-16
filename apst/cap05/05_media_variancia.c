/* Calculo da media e da variancia de n reais */
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int i, n;
	float *v;
	float med, var;
	
	scanf("%d", &n);
	v = (float*)malloc(sizeof(float));
	if (v == NULL) {
		printf("memoria insuficiente");
		return 1;
	}
	for (i = 0; i < n; i++)
		scanf("%d",)
}
