/*
 * Como passar uma string para uma funcao?
 */

#include <stdio.h>

void fortune_cookie (char msg[])// a funcao recebera um array de char
{
	printf("Message reads: %s\n", msg);

}

int main (void)
{
	char quote[] = "Cookies make you fat";
	
	fortune_cookie(quote);

	return 0;
}