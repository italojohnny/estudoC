#ifndef BLAST_H
#define BLAST_H

#include "defines.h"
#include "spaceship.h"

typedef struct Blast{
    float sx;
    float sy;
    float heading;
    float speed;
    int gone;
    ALLEGRO_COLOR color;
    struct Blast *next;
} Blast;

void blast_anime (Blast *b);
void blast_draw (Blast *b);
void blast_shoot (Blast **b, Spaceship *s);
Blast *blast_create (Spaceship *s);

#endif
