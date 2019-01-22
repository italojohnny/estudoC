#include <stdio.h>
#include <string.h>

void main (void)
{
	char dest[20];
	char src[20];
	int len;

	strcpy(src, "Tutorials Point");
	len = strxfrm(dest, src, 20);

	printf("Length of string |%s| is: |%d|", dest, len);
}
