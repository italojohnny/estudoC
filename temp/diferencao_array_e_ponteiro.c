/*
	este programa exemplifica a diferença entre array e ponteiro
*/

#include <stdio.h>

int main (void)
{
	char s[] = "How big is it?";

	char *t = s;//apesar de você poder usar s sem &, pela propriedade 
				//que array possue, s nao pode apontar para outra 
				//coisa alem da primeira possicao dela

	//&s == s
	//&t != t

	printf("s: %i\n", sizeof(s));
	printf("t: %i\n", sizeof(t));


	//================================

	int drinks[] = {4, 2, 3};

	//essas linhas de codigo sao equivalentes.
	printf("1st order: %i drinks\n", drinks[0]);
	printf("1st order: %i drinks\n", *drinks);

	//um endereco e apenas um numero, e por isso pode se fazer matematica com ponteiro
	printf("3rd order: %i drinks\n", drinks[2]);
	printf("3rd order: %i drinks\n", *(drinks+2));


	return 0;
}