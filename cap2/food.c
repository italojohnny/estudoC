#include <stdio.h>

int main (void)
{
	char food[5];
	printf("Enter favorite food: ");
	scanf("%s", food);//Segmentation fault, caso o que o usuario escrever exceda a capacidade da array
	printf("Favorite food: %s\n", food);

	return 0;
}