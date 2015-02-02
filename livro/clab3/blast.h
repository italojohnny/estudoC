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
void blast_destroy ();
void blast_create ();
void blast_anime ();
void blast_draw (Blast *b);

#endif
