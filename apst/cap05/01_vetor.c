/* Calculo da media e da variancia de 10 numeros reais */
#include <stdio.h>

int main (void)
{
	float v[10];
	float med = 0.0, var = 0.0;
	int i;
	
	printf("Entre com 10 valores reais\n");
	for (i = 0; i < 10; i++) {
		printf("valor[%d]: ", i);
		scanf("%f", &v[i]);
		med += v[i];
		var += (v[i] - med) * (v[i]-med);
	}
	printf("Media = %f\nVariante = %f\n", med, var);

	return 0;

}
