#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "defines.h"
#include "blast.h"
typedef struct {
    float sx;
    float sy;
    float heading;
    float speed;
    ALLEGRO_COLOR color;
} Spaceship;


void ship_shoot (Spaceship *s, Blast *b);
void ship_spin (Spaceship *s, float orient);
void ship_advance (Spaceship *s);
void ship_start (Spaceship *s);
void ship_draw (Spaceship *s);

#endif
