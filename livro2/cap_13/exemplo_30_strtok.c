#include <stdio.h>
#include <string.h>

void main (void)
{
	char *p;
	char frase[] = "O Soldado de versao, o partido da luz do dia";

	p = strtok(frase, " ");
	printf(p);
	do {
		p = strtok('\0', ", ");
		if (p)
			printf("|%s", p);
	} while(p);
}
