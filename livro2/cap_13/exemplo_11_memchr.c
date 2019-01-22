#include <stdio.h>
#include <string.h>

void main (void)
{
	char *p;

	p = memchr("isto e um teste", ' ', 14);
	printf(p);
}
