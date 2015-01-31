#ifndef DEFINES_H
#define DEFINES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#define WIDTH 640
#define HEIGHT 480

void inicialize (void);
void finalize (void);
void error (char *msg);

void loop (void);
void keyboard (ALLEGRO_EVENT key_event);
void timer (void);
void draw (void);

#endif
