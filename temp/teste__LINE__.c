#include <stdio.h>
int main (void)
{
	printf("Cheguei com sucesso a linha %d\n", __LINE__);

	//outros comandos aqui...

	printf("Cheguei com sucesso a linha %d\n", __LINE__);
	return 0;
}