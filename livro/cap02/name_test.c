/*
	Usando ponteiros para entrada de dados

*/
#include <stdio.h>

int main (void)
{
	char name[40];
	printf("Enter your nick: ");
	scanf("%39s", name);//nao e necessario usar & pois e uma array

	int age;
	printf("Enter your age: ");
	scanf("%d", &age);//e necessario informar o endereco da variavel usando &

	char first_name[20];
	char last_name[20];
	printf("Enter first and last name: ");
	scanf("%19s %19s", first_name, last_name);

	printf("yours informations\n");
	printf("Nick: %s\n", name);
	printf("Age: %i\n", age);
	printf("First name: %s\n", first_name);
	printf("Last name: %s\n", last_name);
}
