#include <stdio.h>

int main (void)
{

	char cidade[4];
	cidade[0] = 'R';
	cidade[1] = 'i';
	cidade[2] = 'o';
	cidade[3] = '\0';
	printf("%s\n", cidade);
	
	char cidadeAntiga[] = {'G','u','a','r','u','l','h','o','s','\0'};
	printf("%s\n", cidadeAntiga);

	char cidadeNova[] = "Sao Paulo";
	printf("%s\n", cidadeNova);
	
	return 0;
}
