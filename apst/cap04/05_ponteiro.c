#include <stdio.h>

int main (void)
{
	int a, b, *p;
	a = 2;
	*p = 3;
	b = a + (*p);
	printf(" %d ", b);
	return 0;
}

