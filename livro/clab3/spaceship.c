/*
    O heroi do jogo, a pequena, porem corajosa, nave espacial. Diferentemente
    dos asteroides, voce deve apenas ter de lidar com uma de cada vez.
*/

#include <stdio.h>
#include <allegro5/allegro.h>
#include "spaceship.h"

void draw_spaceship (Spaceship *s)
{
    al_draw_line(-8,  9, 0,-11, s->color, 3.0f);
    al_draw_line( 0,-11, 8,  9, s->color, 3.0f);
    al_draw_line(-6,  4,-1,  4, s->color, 3.0f);
    al_draw_line( 6,  4, 4,  4, s->color, 3.0f);

}

void test_spaceship (void)
{
    puts("spaceship");
}
