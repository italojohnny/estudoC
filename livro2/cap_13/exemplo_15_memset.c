#include <stdio.h>
#include <string.h>



void main (void)
{
	char buf[100];

	memset(buf, '\0', 100);
	memset(buf, 'X', 10);
	printf(buf);
}
