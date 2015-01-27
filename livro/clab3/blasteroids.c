/*
    E sempre bom ter um arquivo fonte separado para lidar com o nucleo do jogo.
    O codigo aqui precisara ficar atento a teclas pressionadas, executar um
    temporizador e, tambem dizer para todas as outras naves, asteroides e tiros
    como se mover pela tela.
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
//#include <allegro5/allegro_image.h>
//#include <allegro5/allegro_font.h>
//#include <allegro5/allegro_ttf.h>

#include "spaceship.h"
#include "blast.h"
#include "asteroid.h"

const int WIDTH  = 800;
const int HEIGHT = 600;

ALLEGRO_DISPLAY *my_display = NULL;

Spaceship *a;

void error (char *msg);
void initialize (void);
void finalize (void);
void draw (void);

int main (void)
{
    initialize();
    while (1) {
        
        draw();

    }
    finalize();
    return 0;
}

void draw (void)
{

    al_clear_to_color(al_map_rgb(0, 0, 0));
/*    al_draw_line(20.0, 40.0, 40.0, 60.0, al_map_rgb(255, 0, 0), 1.0);
    al_draw_triangle(70.0, 30.0, 20.0, 55.0, 110.0, 250.0, al_map_rgb(255, 255, 255), 5.0);
    al_draw_filled_triangle(40.0, 90.0, 120.0, 246.0, 400.0, 23.0, al_map_rgb(255, 255, 0));
    al_draw_rectangle(70.0, 30.0, 110.0, 250.0, al_map_rgb(255, 0, 255), 6.0);
    al_draw_filled_rectangle(88.0, 10.0, 340.0, 77.0, al_map_rgb(0, 255, 255));
    al_draw_ellipse(70.0, 90.0, 20.0, 55.0, al_map_rgb(255, 255, 255), 5.0);
    al_draw_filled_ellipse(98.0, 145.0, 25.0, 15.0, al_map_rgb(128, 255, 128));
    al_draw_circle(250.0, 300.0, 70.0, al_map_rgb(128, 0, 0), 2.0);
    al_draw_filled_circle(350.0, 50.0, 43.0, al_map_rgb(0, 0, 255));
*/
    draw_spaceship(&a);
    al_flip_display();
}

void initialize (void)
{
    if (!al_init()) error("");
    if (!al_init_primitives_addon()) error("");
    my_display = al_create_display(WIDTH, HEIGHT);
    if (!my_display) error("");
    al_set_window_title(my_display, "Blasteroids");
}

void finalize (void)
{
    al_destroy_display(my_display);
}

void errro (char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}
