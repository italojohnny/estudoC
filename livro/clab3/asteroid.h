#ifndef ASTEROID_H
#define ASTEROID_H

#include "defines.h"

typedef struct {
    float sx;
    float sy;
    float heading;//em que direcao esta indo
    float twist;//rotacao atual
    float speed;//velocidade
    float rot_velocity;//velocidade de rotacao
    float scale;//escala
    int  gone;//ele foi destruido?
    ALLEGRO_COLOR color;
} Asteroid;

void asteroid_anima (Asteroid *a);
void asteroid_start (Asteroid *a);
void draw_asteroid (Asteroid *a);
void test_asteroid (void);

#endif
