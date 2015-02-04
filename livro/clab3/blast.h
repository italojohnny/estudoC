#ifndef BLAST_H
#define BLAST_H

#include "defines.h"

typedef struct Blast{
    float sx;
    float sy;
    float heading;
    float speed;
    int gone;
    ALLEGRO_COLOR color;
    struct Blast *next;
} Blast;

void blast_destroy ();
void blast_create ();
//void blast_anime (Blast *b);
void blast_draw (Blast *b);

#endif
