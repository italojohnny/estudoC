/* Calculo da media e da variancia de n reais */
#include <stdio.h>
#include <stdlib.h>

float media (int n, float *p);
float variancia (int n, float *p, float m);

int main (void)
{
	int i, n;
	float *v;
	float med, var;
	
	printf("Entre com um inteiro: ");	
	scanf("%d", &n);
	
	v = (float*)malloc(n*sizeof(float));
	if (v == NULL) {
		printf("memoria insuficiente");
		return 1;
	}
	
	for (i = 0; i < n; i++) {
		printf("valor[%d]: ", i);
		scanf("%f", &v[i]);
	}
	med = media(n,v);
	var = variancia(n, v, med);

	printf("media = %f\nVariancia = %f\n", med, var);

	free(v);
	return 0;
}

float media (int n, float *p)
{
	int i;
	float temp = 0.0;
	for (i = 0; i < n; i++)
		temp += *(p+i);

	return temp/n;
}

float variancia (int n, float *p, float m)
{
	int i;
	float temp = 0.0;
	for (i = 0; i < n; i++) 
		temp += (*(p+i) - m) * (*(p+i) - m);
	return temp/n;
}
