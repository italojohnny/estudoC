/* casa2.c */
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int main (int argc, char **argv) {
	int start, error;

	/* Aloca e compila */
	regex_t er;
	regmatch_t match;
	regcomp(&er, argv[1], REG_EXTENDED);

	start = 0;
	/* Tenta casar a ER no inicio da linha.
	 * Se achou, entra no loop, mostra os dados e tenta novamente
	 * desta vez indicando que nao esta mais no inicio da linha
	 * REG_NOTBOL - Not Beginig Of Line
	 */
	error = regexec(&er, argv[2], 1, &match, 0);
	while (error == 0) {
		printf("Texto de pesquisa: %s\n", argv[2]+start);
		printf("Casou de %d a %d\n", match.rm_so, match.rm_eo);
		start += match.rm_eo; /* Move o "cursor" adiante */
		error = regexec(&er, argv[2]+start, 1, &match, REG_NOTBOL);
	}
	return 0;
}
