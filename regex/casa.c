/* casa.c */
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int main (int argc, char **argv) {
	/* Aloca e compila */
	regex_t er;
	regcomp(&er, argv[1], REG_EXTENDED|REG_NOSUB);

	/* Casou ou nao? */
	if ((regexec(&er, argv[2], 0, NULL, 0)) == 0)
		printf("Casou\n");
	else
		printf("Nao casou\n");
	return 0;
}
