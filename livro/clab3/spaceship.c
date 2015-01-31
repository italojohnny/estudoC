/*
    O heroi do jogo, a pequena, porem corajosa, nave espacial. Diferentemente
    dos asteroides, voce deve apenas ter de lidar com uma de cada vez.
*/

#include "spaceship.h"

void ship_spin (Spaceship *s, float  orient)
{
    if (s->heading > 360)
            s->heading = 0;
    if (s->heading < 0)
            s->heading = 360;
    s->heading += orient;
}

void ship_advance (Spaceship *s)
{
    s->sx += 1;
}

void start_ship (Spaceship *s)
{
    s->sx = 640/2;
    s->sy = 480/2;
    s->heading = 0.0;
    s->speed = 0.0;
    s->color = al_map_rgb(255, 0, 0);
}

void draw_ship (Spaceship* s)
{
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_rotate_transform(&transform, s->heading * 3.141592/180);
    //al_rotate_transform(&transform, 0);
    al_translate_transform(&transform, s->sx, s->sy);
    al_use_transform(&transform);
   
    al_draw_line(-8,  9, 0,-11, s->color, 3.0);
    al_draw_line( 0,-11, 8,  9, s->color, 3.0);
    al_draw_line(-6,  4,-1,  4, s->color, 3.0);
    al_draw_line( 6,  4, 1,  4, s->color, 3.0);
    
    al_identity_transform(&transform);
    al_use_transform(&transform);
}

void test_spaceship (void)
{
    puts("test Spaceship");
}
