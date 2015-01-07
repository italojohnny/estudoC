#include <stdio.h>

int y = 1;

int main (void)
{
	int x = 4;

	printf("y is stored at %p\n", &y);
	printf("x is stored at %p\n", &x);

	return 0;
}