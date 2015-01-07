/*
 * Aprendendo sobre ponteiros
 * Inicialmente era passado para a funcao as copias dos valores das variaveis originais, latitude e longitude
 * mas dessa forma as variaveis originais não tinham seus valores alterados, apenas as variaveis lat e lon
 * para resolver isso, deve ser usado ponteiros.
 * 
 */

#include <stdio.h>

void go_south_east (int* lat, int* lon)//agora a funcao recebe o endereco das variaveis originais
{
	*lat = *lat - 1;//as alterações são feitas nas variaveis originais atraves do enderecos delas
	*lon = *lon + 1;
}

int main (void)
{
	int latitude = 32;//essas são as variaveis originais
	int longitude = -64;

	go_south_east(&latitude, &longitude);//passando os endereco das variaveis originais e possivel alterar de outra funcao, os valores originais

	printf("Avast! Now at: [%i, %i]\n", latitude, longitude);

	return 0;
}