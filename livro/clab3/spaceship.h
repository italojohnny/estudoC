#ifndef SPACESHIP_H
#define SPACESHIP_H

typedef struct {
    float sx;
    float sy;
    float heading;
    float speed;
    ALLEGRO_COLOR color;
} Spaceship;


void draw_spaceship (Spaceship *s);
void test_spaceship (void);
void draw_ship (Spaceship *s);

#endif
