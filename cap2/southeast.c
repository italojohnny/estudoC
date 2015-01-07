/*
 * Aprendendo sobre ponteiros
 * 
 */

#include <stdio.h>

void go_south_east (int lat, int lon)//essas sao outras variaveis que receberão cópias dos valores das variaveis originais
{
	lat = lat - 1;//quando modificadas, apenas os valores das copias serao modificados, e nao os valores das variaveis originais
	lon = lon + 1;
}

int main (void)
{
	int latitude = 32;//essas são as variaveis originais
	int longitude = -64;

	go_south_east(latitude, longitude);//passando copias dos valores das variaveis originais

	printf("Avast! Now at: [%i, %i]\n", latitude, longitude);

	return 0;
}