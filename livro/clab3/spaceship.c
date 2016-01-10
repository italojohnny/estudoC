/*
    O heroi do jogo, a pequena, porem corajosa, nave espacial. Diferentemente
    dos asteroides, voce deve apenas ter de lidar com uma de cada vez.
*/

#include "spaceship.h"
#define BOOST_MAX 10.0

void ship_spin (Spaceship *s, float  orient)
{
    orient *= s->speed;
    if (s->heading > 360)
            s->heading = 0;
    if (s->heading < 0)
            s->heading = 360;
    s->heading += orient;
}

void ship_advance (Spaceship *s)
{
	if (s->gone == 0) {
		if (s->sx < 0) s->sx = 0;
		if (s->sy < 0) s->sy = 0;
		if (s->sx > WIDTH) s->sx = WIDTH;
		if (s->sy > HEIGHT)s->sy = HEIGHT;
		s->sx += (s->boost * s->speed) * sin(s->heading *M_PI/180);
		s->sy -= (s->boost * s->speed) * cos(s->heading *M_PI/180);
	}
}

void ship_start (Spaceship *s)
{
    s->sx = 640/2;
    s->sy = 480/2;
    s->heading = 0.0;
    s->speed = 3.0;
    s->boost = 0.0;
	s->gone = 1;
    s->color = al_map_rgb(255, 0, 0);
}

void ship_draw (Spaceship* s)
{
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_rotate_transform(&transform, s->heading * M_PI/180);
    al_translate_transform(&transform, s->sx, s->sy);
    al_use_transform(&transform);

	if (s->gone == 0) {
		//al_draw_filled_circle(0, 0, 11, s->color);

		al_draw_line(-8,  9, 0,-11, s->color, 3.0);
		al_draw_line( 0,-11, 8,  9, s->color, 3.0);
		al_draw_line(-6,  4,-1,  4, s->color, 3.0);
		al_draw_line( 6,  4, 1,  4, s->color, 3.0);

	} else if (s->gone == 1) { s->gone++; al_draw_circle(0, 0, 10, s->color, 0);
	} else if (s->gone == 2) { s->gone++; al_draw_circle(0, 0, 9, s->color, 1);
	} else if (s->gone == 3) { s->gone++; al_draw_circle(0, 0, 8, s->color, 2);
	} else if (s->gone == 4) { s->gone++; al_draw_circle(0, 0, 7, s->color, 3);
	} else if (s->gone == 5) { s->gone++; al_draw_circle(0, 0, 6, s->color, 4);
	} else if (s->gone == 6) { s->gone++; al_draw_circle(0, 0, 5, s->color, 5);
	} else if (s->gone == 7) { s->gone++; al_draw_circle(0, 0, 10, s->color, 6);
	} else if (s->gone == 8) { s->gone++; al_draw_circle(0, 0, 15, s->color, 7);
	} else if (s->gone == 9) { s->gone++; al_draw_circle(0, 0, 20, s->color, 8);
	} else if (s->gone == 10) { s->gone++; al_draw_filled_circle(0, 0, 20, al_map_rgb(255, 255, 255));
	} else if (s->gone == 11) { s->gone++; al_draw_circle(0, 0, 20, s->color, 4);
	} else if (s->gone == 12) { s->gone++; al_draw_filled_circle(0, 0, 20, al_map_rgb(255, 255, 255));
	} else if (s->gone == 13) { s->gone++; al_draw_circle(0, 0, 20, s->color, 2);
	} else if (s->gone == 14) { s->gone++; al_draw_filled_circle(0, 0, 20, al_map_rgb(255, 255, 255));
	} else if (s->gone == 15) { s->gone++; al_draw_circle(0, 0, 20, s->color, 1);
		s->gone = 0;
	}

    al_identity_transform(&transform);
    al_use_transform(&transform);
}

void ship_collision (Asteroid *a)
{
	printf("%p", a);
}
