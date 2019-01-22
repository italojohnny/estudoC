#include <stdio.h>
#include <string.h>

void main (void)
{
	char *p;

	p = strpbrk("isto e um teste", "obkj");
	printf(p);
}
