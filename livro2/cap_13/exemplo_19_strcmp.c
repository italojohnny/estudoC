#include <stdio.h>
#include <string.h>

void main (void)
{
	char s[80];
	printf("digite a senha: ");
	gets(s);

	if (strcmp(s, "pass")) printf("senha invalida\n");
	else printf("senha valida\n");
}
