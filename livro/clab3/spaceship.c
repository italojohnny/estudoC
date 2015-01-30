/*
    O heroi do jogo, a pequena, porem corajosa, nave espacial. Diferentemente
    dos asteroides, voce deve apenas ter de lidar com uma de cada vez.
*/

#include "spaceship.h"

void draw_ship (Spaceship* s)
{
    s->color = al_map_rgb(0, 255, 0);
    s->sx = 640 / 2;
    s->sy = 480 /2;
    s->heading = 0.0;

    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_rotate_transform(&transform, s->heading);
    al_translate_transform(&transform, s->sx, s->sy);
    al_use_transform(&transform);
    al_draw_line(-8,  9, 0,-11, s->color, 3.0);
    al_draw_line( 0,-11, 8,  9, s->color, 3.0);
    al_draw_line(-6,  4,-1,  4, s->color, 3.0);
    al_draw_line( 6,  4, 1,  4, s->color, 3.0);
}

void test_spaceship (void)
{
    al_draw_line(20.0, 40.0, 40.0, 60.0, al_map_rgb(255, 0, 0), 30.0);
}
