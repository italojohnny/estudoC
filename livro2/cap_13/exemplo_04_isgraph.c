#include <ctype.h>
#include <stdio.h>

void main (void)
{
	char ch;
	for (;;) {
		ch = getchar();
		if (ch == ' ') break;
		if (isgraph(ch)) printf("%c pode ser impresso\n", ch);
	}
}
