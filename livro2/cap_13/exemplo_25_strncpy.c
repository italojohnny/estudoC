#include <stdio.h>
#include <string.h>

void main (void)
{
	char str1[128], str2[128];

	gets(str1);
	strncpy(str2, str1, 79);

	printf("%s\n", str2);
}
