#include <stdio.h>

int main (void) {
	char cpf[13] = "12.123.123-12";
	printf("Validador de CPF\n");
	printf("Digite: ");
	scanf("%13s", &cpf);

	printf("O CPF %s, nao e valido\n", cpf);
	return 0;
}
