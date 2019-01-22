#include <ctype.h>
#include <stdio.h>

void main (void)
{
	char ch;
	for (;;) {
		ch = getchar();
		if (ch == ' ') break;
		if (isupper(ch)) printf("%c e maiusculo\n", ch);
	}
}
