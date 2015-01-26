/*
    E sempre bom ter um arquivo fonte separado para lidar com o nucleo do jogo.
    O codigo aqui precisara ficar atento a teclas pressionadas, executar um
    temporizador e, tambem dizer para todas as outras naves, asteroides e tiros
    como se mover pela tela.
*/

#include <stdio.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <string.h>
#include <errno.h>

#include "spaceship.h"
#include "blast.h"
#include "asteroid.h"

const int WIDTH  = 800;
const int HEIGHT = 600;

void error (char *msg);
void initialize (void);
void draw (void);

int main (void)
{
    //test_asteroid();
    //test_blast();
    //test_spaceship();

    ALLEGRO_DISPLAY *display= NULL;
    ALLEGRO_BITMAP *image = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_FONT *font = NULL;

    if (!al_init()) error("Couldn't initialize allegro!");
    if (!al_init_image_addon()) error("Can't initialize image_addon");
    if (!al_init_primitives_addon()) error("Couldn't initialize primitives addon!");
    //al_init_font_addon();
    //if (!al_init_ttf_addon()) error("Can't initializae font addon");

    event_queue = al_create_event_queue();
    if (!event_queue) error ("Can't create event queue");

    image = al_load_bitmap("test.jpg");
    if (!image) error("Can't load image");

    display=al_create_display(WIDTH, HEIGHT);
    if (!display) error("Couldn't create allegro display!");
    
    font = al_load_font("Courier.ttf", 48, 0);
    if (!font) error("Can't loading font");

//=======================================================    
    al_register_event_source(event_queue, al_get_display_event_source(display)); 

    //al_draw_line(100,100,400,400,al_map_rgb(255,0,0),3);
    //Spaceship a;
    //draw_spaceship(&a);

    al_flip_display();
    while (1) {
        ALLEGRO_EVENT event;
        ALLEGRO_TIMEOUT timeout;
        al_init_timeout(&timeout, 0.05);

        int tem_eventos = al_wait_for_event_until(event_queue, &event, &timeout);
        if (tem_eventos && event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) break;
        
        al_clear_to_color(al_map_rgb(0,100,0));
        al_draw_bitmap(image, 0, 0, 0);

        //al_draw_text(font, al_map_rgb(255, 0, 0), 10, 10, ALLEGRO_ALIGN_LEFT, "ESQUERDA");
        

        al_flip_display(); 
    }
    //al_rest(10.0);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    return 0;
}

void errro (char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}
