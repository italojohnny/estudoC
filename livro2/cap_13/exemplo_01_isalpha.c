#include <ctype.h>
#include <stdio.h>

void main (void)
{
	char ch;
	for (;;) {
		ch = getchar();
		if (ch == ' ') break;
		if (isalpha(ch)) printf("%c e uma letra\n", ch);
	}
}
