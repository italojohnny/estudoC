#include <stdio.h>
#define PI 3.141592

float area (float r);

int main (void)
{
	float r;
	printf("Entre com o raio do circulo: ");
	scanf("%f", &r);

	printf("Area: %f\n", area(r));

	return 0;
}

float area (float r)
{
	return PI * r * r;
}
