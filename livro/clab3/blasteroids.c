/*
    E sempre bom ter um arquivo fonte separado para lidar com o nucleo do jogo.
    O codigo aqui precisara ficar atento a teclas pressionadas, executar um
    temporizador e, tambem dizer para todas as outras naves, asteroides e tiros
    como se mover pela tela.
*/
#include "defines.h"

#include "spaceship.h"
#include "blast.h"
#include "asteroid.h"

const int WIDTH  = 800;
const int HEIGHT = 600;

ALLEGRO_DISPLAY *myDisplay = NULL;
ALLEGRO_EVENT_QUEUE *myEventQueue = NULL;

int statusGame;
Spaceship a;
Asteroid b;

int main (void)
{
    statusGame = 1;
    inicialize();
    
    loop();

    finalize();
    return 0;
}

void loop (void)
{
    /* inicia threas para desenhar, teclado e tempo */
    while (statusGame) {
        if (!al_is_event_queue_empty(myEventQueue)) {
            ALLEGRO_EVENT evento;
            al_wait_for_event(myEventQueue, &evento);
            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE ||(evento.type == ALLEGRO_EVENT_KEY_DOWN && evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE))
                statusGame = 0;
        }
        keyboard();
        timer();
        draw();
    }
}

void keyboard (void)
{
    //seta para cima        //acelara
    //seta para baixo       //freia
    //seta para direita     //vira sentido horario
    //seta para esquerda    //vira sentido anti-horario
    //barra de espaco       //atira
}

void timer (void)
{

}

void draw (void)
{
    al_clear_to_color(al_map_rgb(0, 0, 0));

    draw_ship(&a);
    draw_asteroid(&b);

    al_flip_display(); 
}

void inicialize (void)
{
    if (!al_init())
        error("allegro");

    if (!al_init_primitives_addon())
        error("add-on allegro_primitives");
    
    al_init_font_addon();
    if (!al_init_ttf_addon())
        error("add-on allegro_ttf");

    if (!al_install_keyboard())
        error("keyboard");
    
    myDisplay = al_create_display(WIDTH, HEIGHT);
    if (!myDisplay)
        error("create display");
    al_set_window_title(myDisplay, "Blasteroids");

    myEventQueue = al_create_event_queue();
    if (!myEventQueue)
        error("create event queue");

    al_register_event_source(myEventQueue, al_get_display_event_source(myDisplay));
    al_register_event_source(myEventQueue, al_get_keyboard_event_source());
}

void finalize (void)
{
    al_destroy_event_queue(myEventQueue);
    al_destroy_display(myDisplay);
}

void errro (char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    finalize();
    exit(1);
}
