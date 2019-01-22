#include <stdio.h>
#include <string.h>
#include <errno.h>

int main (void)
{
	FILE * pFile;
	pFile = fopen ("unexist.ent","r");

	if (pFile == NULL)
		printf ("Error opening file unexist.ent: %s\n",strerror(errno));
	return 0;
}
