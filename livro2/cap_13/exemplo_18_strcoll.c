#include <stdio.h>
#include <string.h>
#include <locale.h>

void main (void)
{
	printf ("Localidade corrente: %s\n", setlocale(LC_ALL, NULL));

	char *str1 = "cachorro", *str2 = "ola";
	int result = strcoll(str1, str2);

	if (!result) printf("Iguais\n");
	else if (result < 0) printf("Primeiro menor que segundo\n");
	else printf("Primeiro mairo que segundo\n");
}
