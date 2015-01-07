/*
 * Este programa serve para demonstrar todas as formas de manipulacao de ponteiros
 *
 */

#include <stdio.h>

int main (void)
{
	int variavel = 10;
	int* ponteiro1;
	int *ponteiro2 = &variavel;

	printf(" variavel: %i\n", variavel);
	printf("&variavel: %p\n", &variavel);
	//printf("*variavel: %i\n", *variavel); //ERRO, NÃO É UM PONTEIRO, POR ISSO NÃO PODE USAR O OPERADOR *

	printf(" ponteiro1: %p\n", ponteiro1);
	printf("&ponteiro1: %p\n", &ponteiro1);
	printf("*ponteiro1: %i\n", *ponteiro1);

	printf(" ponteiro2: %p\n", ponteiro2);
	printf("&ponteiro2: %p\n", &ponteiro2);
	printf("*ponteiro2: %i\n", *ponteiro2);

	return 0;
}