/*
    Arquivo contendo todo o codigo-fonte para manter o controle e exibir a
    ultima posicao de um asteroide.
*/

#include "asteroid.h"
void asteroid_anima (Asteroid *a)
{
   if (a->sx < 0) a->sx = WIDTH;
   if (a->sy < 0) a->sy = HEIGHT;
   if (a->sx > WIDTH) a->sx = 0;
   if (a->sy > HEIGHT)a->sy = 0;
   if (a->twist > 360) a->twist = 0;
   if (a->twist < 0) a->twist = 360;
   a->sx += a->speed * sin(a->heading * M_PI/180);
   a->sy += a->speed * cos(a->heading * M_PI/180);
   a->twist += a->rot_velocity;

}

void asteroid_start (Asteroid *a)
{
    a->sx = rand()%WIDTH;//sortear de 0 a WIDTH
    a->sy = rand()%HEIGHT;//sortear de 0 a HEIGHT
    a->heading = rand()%359;//sortiar de 0 a 359;
    a->twist = 0;
    a->speed = 0.5;
    a->rot_velocity = -1.5;//sortear de -1.5 a 1.5
    a->scale = 1;
    a->gone = 0;
    a->color = al_map_rgb(0, 255, 0);
}

void draw_asteroid (Asteroid *a)
{
    asteroid_anima(a);
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_rotate_transform(&transform, a->twist * M_PI/180);
    al_translate_transform(&transform, a->sx, a->sy);
    al_use_transform(&transform);
    
    al_draw_line(-20, 20,-25,  5, a->color, 2.0f);
    al_draw_line(-25,  5,-25,-10, a->color, 2.0f);
    al_draw_line(-25,-10, -5,-10, a->color, 2.0f);
    al_draw_line( -5,-10,-10,-20, a->color, 2.0f);
    al_draw_line(-10,-20,  5,-20, a->color, 2.0f);
    al_draw_line(  5,-20, 20,-10, a->color, 2.0f);
    al_draw_line( 20,-10, 20, -5, a->color, 2.0f);
    al_draw_line( 20, -5,  0,  0, a->color, 2.0f);
    al_draw_line(  0,  0, 20, 10, a->color, 2.0f);
    al_draw_line( 20, 10, 10, 20, a->color, 2.0f);
    al_draw_line( 10, 20,  0, 15, a->color, 2.0f);
    al_draw_line(  0, 15,-20, 20, a->color, 2.0f);

    al_identity_transform(&transform);
    al_use_transform(&transform);
}

void test_asteroid (void)
{
    puts("asteroid");
}
