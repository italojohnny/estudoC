#include <stdio.h>
#include <stdlib.h>

typedef struct Blast {
    int var1;
    int var2;
    struct Blast *next;
} Blast;

Blast *create (void)
{
    Blast *new = malloc(sizeof(Blast*));
    new->var1 = 10;
    new->var2 = 20;

    return new;
}
void ligar (Blast *p)
{
    Blast *aux = p;
    Blast *i = NULL;
    Blast *prox = NULL;
    
    for (; aux != NULL; i = prox) {
        prox = create();
        if (aux == NULL)
            aux = prox;
        if (i != NULL)
            i->next = prox;
    }
    p = aux;
    puts("Deu certo");
}

int main (void)
{
    puts("compilou");

    Blast *pt = NULL;
    ligar(pt);

    return 0;
}
