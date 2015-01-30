#ifndef ASTEROID_H
#define ASTEROID_H

#include "defines.h"

typedef struct {
    float sx;
    float sy;
    float heading;
    float twist;
    float speed;
    float rot_velocity;
    float scale;
    float gone;
    ALLEGRO_COLOR color;
} Asteroid;


void draw_asteroid (Asteroid *s);
void test_asteroid (void);

#endif
