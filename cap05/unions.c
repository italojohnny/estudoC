#include <stdio.h>

/*
    Existem formas diferentes de atribuicao para unions:

    quantity q = {4};//isso significa que a quantidade e uma contagem de valor 4
    
    quantity q = {.weight = 1.5};//isso vai atribuir um valor de ponto flutuante de peso ao union
    
    quantity q;
    q.volume = 3.7;
*/

typedef union {
    short count;
    float weight;
    float volume;
} quantity;

typedef struct {
    const char *name;
    const char *country;
    quantity amount;
} fruit_order;

int main (void)
{
    fruit_order apples = {"apples", "England", .amount.weight=4.2};

    printf("This order contains %2.2f lbs of %s\n", apples.amount.weight,
    apples.name);

    return 0;
}


