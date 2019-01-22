#include <stdio.h>
#include <string.h>

void main (void)
{
	char *p;

	p = strrchr("isto e um teste", 'o');
	printf(p);
}
