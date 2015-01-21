#include <stdio.h>

int main (void)
{
	char food[5];
	printf("Enter favorite food: ");
	//scanf("%s", food);//Segmentation fault, caso o que o usuario escrever exceda a capacidade da array
	fgets(food, sizeof(food), stdin);//fgets() e uma alternativa para scanf()
	printf("Favorite food: %s\n", food);

	return 0;
}