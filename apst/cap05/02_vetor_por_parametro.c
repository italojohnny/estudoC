/* Calculo da media e da variancia de 10 numeros reais */
#include <stdio.h>

float media (int n, float* v);
float variante (int n, float* v, float m);

int main (void)
{
	float v[10];
	float med = 0.0, var = 0.0;
	int i;
	
	printf("Entre com 10 valores reais\n");
	for (i = 0; i < 10; i++) {
		printf("valor[%d]: ", i);
		scanf("%f", &v[i]);
	}
	med = media(10, v);
	var = variante(10, v, med);

	printf("Media = %f\nVariante = %f\n", med, var);

	return 0;
}

float media (int n, float* v)
{
	int i;
	float s = 0.0;
	for (i = 0; i < n; i++)
		s += v[i];
	return s/n;
}

float variante (int n, float* v, float m)
{	
	int i;
	float s = 0.0;
	for (i = 0; i < n; i++)
		s += (v[i] - m) * (v[i] - m);
	return s/n;
}
