#include <stdio.h>
#include <string.h>

void main (void)
{
	int len = strcspn("isto e um teste", "uz");
	printf("%d\n", len);
}
