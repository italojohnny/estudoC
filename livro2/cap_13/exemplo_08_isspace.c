#include <ctype.h>
#include <stdio.h>

void main (void)
{
	char ch;
	for (;;) {
		ch = getchar();
		if (isspace(ch)) printf("%c e um espaco em branco\n", ch);
		if (ch == ' ') break;
	}
}
