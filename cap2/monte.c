/*
	Strings literais nunc apodem ser atualizadas
	Isso se da em razao de como C usa a memoria

	char *cards = "JQK"//e uma string literal

	Strings literais são armazenadas como constantes,
	ou seja ficam na regiao de memoria somente de leitura.

	Se for modificar uma string, faca uma copia.

	char cards[] = "JQK";//cards nao e apenas um ponteiro. Agora cards e um array.

	Isso deve ser explicado melhor. Atenção:
	se a declaracao "char cards[]" estiver dentro de uma funcao ela e um array
	agora, caso estiver como parametro de uma funcao ela e um ponteiro, e usar "char *cards" seria a mesma coisa.

*/
#include <stdio.h>

int main()
{
	char cards[] = "JQK";
	char a_card = cards[2];

	cards[2] = cards[1];
	cards[1] = cards[0];
	cards[0] = cards[2];
	cards[2] = cards[1];
	cards[1] = a_card;

	puts(cards);

	return 0;
}