/*
    A nave podera atirar em um asteroid com seu canhao, entao voce vai precisar
    de codigo para desenhar e mover um tiro de canhao pela tela.
*/
#include "blast.h"

void draw_blast (Blast *b)
{
    b->color = al_map_rgb(0, 255, 0);
    al_draw_line(0, 0, 100, 100, b->color, 1);
}

void test_blast (void)
{
    puts("blast");
}
