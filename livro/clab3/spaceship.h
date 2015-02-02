#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "defines.h"

typedef struct {
    float sx;
    float sy;
    float heading;
    float speed;
    ALLEGRO_COLOR color;
} Spaceship;


void ship_shoot (Spaceship *s);
void ship_spin (Spaceship *s, float orient);
void ship_advance (Spaceship *s);
void start_ship (Spaceship *s);
void test_spaceship (void);
void draw_ship (Spaceship *s);

#endif
