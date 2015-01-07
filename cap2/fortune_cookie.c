/*
 * Como passar uma string para uma funcao?
 */

#include <stdio.h>

void fortune_cookie (char msg[])// a funcao recebera um array de char
//entao o que realemente acontece é a passagem da referencia
//em outras palavras, a funcao recebeu um ponteiro
{
	printf("Message reads: %s\n", msg);
	printf("msg occupies %i bytes\n", sizeof(msg));//isso impreme que a variavel ocupa 8 bytes, pois array sao como ponteiros
}

int main (void)
{
	char quote[] = "Cookies make you fat";
	
	fortune_cookie(quote);
	
	printf("The quote string is stored at: %p\n", quote);
	
	return 0;
}