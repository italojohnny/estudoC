#include <stdio.h>
int comprimento (char*);
int main (void)
{
	char nome[] = "italo johnny dos anjos";
	printf("comprimento de %s é de %d caracteres\n", nome, comprimento(nome));
	return 0;
}

int comprimento (char *s)
{
	int i = 0;
	while (*(s+i) != '\0')
		i++;
	return i;
}
