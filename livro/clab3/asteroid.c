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
   a->sy -= a->speed * cos(a->heading * M_PI/180);
   a->twist += a->rot_velocity;

}

void asteroid_start (Asteroid *a)
{
    a->sx = rand()%WIDTH;//sortear de 0 a WIDTH
    a->sy = rand()%HEIGHT;//sortear de 0 a HEIGHT
    a->heading = rand()%359;//sortiar de 0 a 359;
    a->twist = rand()%359;
    a->speed = (rand()%10)+0.1;
    a->rot_velocity = (rand()%6)-3;//sortear de -1.5 a 1.5
    a->scale = (rand()%3)+1;
    a->gone = 0;
    a->color = al_map_rgb(0, 255, 0);
	printf("%f\n", a->speed);
}

void draw_asteroid (Asteroid *a)
{
    asteroid_anima(a);
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_rotate_transform(&transform, a->twist * M_PI/180);
    al_translate_transform(&transform, a->sx, a->sy);
    al_use_transform(&transform);

	al_draw_circle(0, 0, 12.5*a->scale, al_map_rgb(255, 255, 255), 0);
    al_draw_line(-10.0*a->scale, 10.0*a->scale,-12.5*a->scale, 02.5*a->scale, a->color, 2.0f);//a
    al_draw_line(-12.5*a->scale, 02.5*a->scale,-12.5*a->scale,-05.0*a->scale, a->color, 2.0f);//b
    al_draw_line(-12.5*a->scale,-05.0*a->scale,-02.5*a->scale,-05.0*a->scale, a->color, 2.0f);//c
    al_draw_line(-02.5*a->scale,-05.0*a->scale,-05.0*a->scale,-10.0*a->scale, a->color, 2.0f);//d
    al_draw_line(-05.0*a->scale,-10.0*a->scale, 02.5*a->scale,-10.0*a->scale, a->color, 2.0f);//e
    al_draw_line( 02.5*a->scale,-10.0*a->scale, 10.0*a->scale,-05.0*a->scale, a->color, 2.0f);//f
    al_draw_line( 10.0*a->scale,-05.0*a->scale, 10.0*a->scale,-02.5*a->scale, a->color, 2.0f);//g
    al_draw_line( 10.0*a->scale,-02.5*a->scale, 00.0*a->scale, 00.0*a->scale, a->color, 2.0f);//h
    al_draw_line( 00.0*a->scale, 00.0*a->scale, 10.0*a->scale, 05.0*a->scale, a->color, 2.0f);//i
    al_draw_line( 10.0*a->scale, 05.0*a->scale, 05.0*a->scale, 10.0*a->scale, a->color, 2.0f);//j
    al_draw_line( 05.0*a->scale, 10.0*a->scale, 00.0*a->scale, 07.5*a->scale, a->color, 2.0f);//k
    al_draw_line( 00.0*a->scale, 07.5*a->scale,-10.0*a->scale, 10.0*a->scale, a->color, 2.0f);//l

    al_identity_transform(&transform);
    al_use_transform(&transform);
}

Asteroid *asteroid_create ()
{
	Asteroid *newAsteroid = malloc(sizeof(Asteroid));

	return newAsteroid;
}
