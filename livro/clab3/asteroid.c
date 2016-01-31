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

void draw_asteroid (Asteroid **a)
{
	if (*a != NULL) {
		Asteroid *t = *a;
		while (t != NULL) {

			if (!t->gone) {
			asteroid_anima(t);
			ALLEGRO_TRANSFORM transform;
			al_identity_transform(&transform);
			al_rotate_transform(&transform, t->twist * M_PI/180);
			al_translate_transform(&transform, t->sx, t->sy);
			al_use_transform(&transform);

			//al_draw_circle(0, 0, 12.5 * t->scale, al_map_rgb(255, 255, 255), 0);
			al_draw_line(-10.0*t->scale, 10.0*t->scale,-12.5*t->scale, 02.5*t->scale, t->color, 2.0f);//a
			al_draw_line(-12.5*t->scale, 02.5*t->scale,-12.5*t->scale,-05.0*t->scale, t->color, 2.0f);//b
			al_draw_line(-12.5*t->scale,-05.0*t->scale,-02.5*t->scale,-05.0*t->scale, t->color, 2.0f);//c
			al_draw_line(-02.5*t->scale,-05.0*t->scale,-05.0*t->scale,-10.0*t->scale, t->color, 2.0f);//d
			al_draw_line(-05.0*t->scale,-10.0*t->scale, 02.5*t->scale,-10.0*t->scale, t->color, 2.0f);//e
			al_draw_line( 02.5*t->scale,-10.0*t->scale, 10.0*t->scale,-05.0*t->scale, t->color, 2.0f);//f
			al_draw_line( 10.0*t->scale,-05.0*t->scale, 10.0*t->scale,-02.5*t->scale, t->color, 2.0f);//g
			al_draw_line( 10.0*t->scale,-02.5*t->scale, 00.0*t->scale, 00.0*t->scale, t->color, 2.0f);//h
			al_draw_line( 00.0*t->scale, 00.0*t->scale, 10.0*t->scale, 05.0*t->scale, t->color, 2.0f);//i
			al_draw_line( 10.0*t->scale, 05.0*t->scale, 05.0*t->scale, 10.0*t->scale, t->color, 2.0f);//j
			al_draw_line( 05.0*t->scale, 10.0*t->scale, 00.0*t->scale, 07.5*t->scale, t->color, 2.0f);//k
			al_draw_line( 00.0*t->scale, 07.5*t->scale,-10.0*t->scale, 10.0*t->scale, t->color, 2.0f);//l

			al_identity_transform(&transform);
			al_use_transform(&transform);
			}
			t = t->next;
		}
	}
}

void asteroid_start (Asteroid **a, float size, float heading)
{
	Asteroid *t = asteroid_create(*a, size, heading);
	t->next = *a;
	*a = t;
}

Asteroid *asteroid_create (Asteroid *p, float size, float heading)
{
	printf("%p\n", &p->sx);
	printf("%f\n\n", heading);

	Asteroid *newAsteroid = malloc(sizeof(Asteroid));
	newAsteroid->sx = rand()%WIDTH;
	newAsteroid->sy = rand()%HEIGHT;
	newAsteroid->heading = heading;//rand()%359;
	newAsteroid->twist = rand()%359;
	newAsteroid->speed = (rand()%10)+0.1;
	newAsteroid->scale = size;
	newAsteroid->gone = 0;
	newAsteroid->color = al_map_rgb(0, 255, 0);

	return newAsteroid;
}
