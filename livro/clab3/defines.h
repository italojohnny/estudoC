#ifndef DEFINES_H
#define DEFINES_H

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#define  PI 3.1415

void inicialize (void);
void finalize (void);
void error (char *msg);

void loop (void);
void keyboard (void);
void timer (void);
void draw (void);

#endif
