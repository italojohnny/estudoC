/*
    O heroi do jogo, a pequena, porem corajosa, nave espacial. Diferentemente
    dos asteroides, voce deve apenas ter de lidar com uma de cada vez.
*/

#include <stdio.h>
#include <allegro5/allegro.h>
#include "spaceship.h"

void draw_spaceship (Spaceship *s)
{
/*    
    s->color = al_map_rgb(0, 255, 0);
    al_draw_line(-8.0,  9.0, 0.0,-11.0, s->color, 1.0);
    al_draw_line( 0.0,-11.0, 8.0,  9.0, s->color, 3.0);
    al_draw_line(-6.0,  4.0,-1.0,  4.0, s->color, 3.0);
    al_draw_line( 6.0,  4.0, 4.0,  4.0, s->color, 3.0);
*/
    al_draw_line(20.0, 40.0, 40.0, 60.0, al_map_rgb(255,0,0), 1.0);
}

void test_spaceship (void)
{
    puts("spaceship");
}
