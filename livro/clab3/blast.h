#ifndef BLAST_H
#define BLAST_H

#include "defines.h"

typedef struct {
    float sx;
    float sy;
    float heading;
    float speed;
    int gone;
    ALLEGRO_COLOR color;
} Blast;

void draw_blast (Blast *b);
void test_blast (void);

#endif
