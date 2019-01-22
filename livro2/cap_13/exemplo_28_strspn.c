#include <stdio.h>
#include <string.h>

void main (void)
{
	int len;

	len = strspn("isto e um teste", "otsi ");
	printf("%d\n", len);
}
