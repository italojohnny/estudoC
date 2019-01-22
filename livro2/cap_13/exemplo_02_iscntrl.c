#include <ctype.h>
#include <stdio.h>

void main (void)
{
	char ch;
	for (;;) {
		ch = getchar();
		if (ch == ' ') break;
		if (iscntrl(ch)) printf("%c e um caractere de controle\n", ch);
	}
}
