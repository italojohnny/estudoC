#include <stdio.h>

int digito (char c);
int letra (char c);
char maiuscula (char c);

int main (void)
{
	int c;
	printf("Entre com um digito: ");
	scanf("%c", &c);
	
	//printf("%c, %d", c, c);
	
	if (digito(c))
		printf("e um digito\n");
	else
		printf("nao e um digito\n");
	
	if (letra(c)) {
		printf("e uma letra\n");
		printf("Maiuscula: %c\n", maiuscula(c));
	}
	else
		printf("nao e uma letra\n");

	return 0;	
}

int digito (char c)
{
	if ((c>='0') && (c<='9'))
		return 1;
	else
		return 0;
}

int letra (char c)
{
	if (((c>='A') && (c<='Z')) || ((c>='a') && (c<='z')))
		return 1;
	else
		return 0;
}

char maiuscula (char c)
{
	if (letra(c))
		return c-32;
	else
		return 0;
}
