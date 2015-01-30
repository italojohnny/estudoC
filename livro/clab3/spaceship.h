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

void test_spaceship (void);
void draw_ship (Spaceship *s);

#endif
