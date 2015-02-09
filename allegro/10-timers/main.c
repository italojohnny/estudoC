/*
    gcc -lallegro -lallegro_font -lallegro_ttf main.c -o main && ./main
    gcc main.c -o main -lallegro-5.0.10-mt -lallegro_ttf-5.0.10-mt -lallegro_font-5.0.10-mt
*/
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

const int LARGURA_TELA = 640;
const int ALTURA_TELA = 480;

ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *fila_eventos = NULL, *fila_contador = NULL;
ALLEGRO_TIMER *timer = NULL, *contador = 0;
ALLEGRO_FONT *fonte = NULL;


void inicializar (void);
void finalizar (void);
void error (char *msg);

int main (void)
{
    int sair = 0;
    int r = 0, g = 0, b = 0;
    int min = 0, seg = 0;
    
    inicializar();
    
    al_start_timer(timer);
    al_start_timer(contador);
    while (!sair) {
        if (!al_is_event_queue_empty(fila_eventos)) {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);
            if (evento.type == ALLEGRO_EVENT_TIMER) {
                /*
                if (++r >= 255) r = 0;
                if (++g >= 255) g = 0;
                if (++b >= 255) b = 0;
                */
                r = (int)rand() % 255;
                g = (int)rand() % 255;
                b = (int)rand() % 255;
            } else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            sair = 1;
        }
        if (!al_is_event_queue_empty(fila_contador)) {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_contador, &evento);
            if (evento.type == ALLEGRO_EVENT_TIMER) {
                seg++;
                if (seg == 60) {
                    min++;
                    seg = 0;
                }
            }
        }
        al_clear_to_color(al_map_rgb(r, g, b));
        al_draw_textf(fonte, al_map_rgb(255, 0, 0), LARGURA_TELA / 2, 200, ALLEGRO_ALIGN_CENTRE, "%d:%d", min, seg);
        al_draw_textf(fonte, al_map_rgb(0, 255, 0), LARGURA_TELA / 2, 300, ALLEGRO_ALIGN_CENTRE, "%d, %d, %d", r, g, b );
        al_flip_display();
    }

    finalizar();
    return 0;
}

void inicializar (void)
{
    if (!al_init())
        error("Falha ao iniciar allegro");
    
    al_init_font_addon();
    if (!al_init_ttf_addon())
        error("Falha ao inicializar allegro_ttf");
    
    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela)
        error("Falha ao criar janela");
    al_set_window_title(janela, "testando timers...");
    
    fila_eventos = al_create_event_queue();
    if (!fila_eventos)
        error("Falha ao criar fila de eventos");
    
    timer = al_create_timer(0.1);
    if (!timer) 
        error("Falha ao criar timer");
    
    //fonte = al_load_font("2Dumb.ttf", 120, 0);
    fonte = al_load_font("test.ttf", 40, 0);
    if (!fonte)
        error("Falha ao carregar fonte");
    
    contador = al_create_timer(1.0);
    if (!contador)
        error("Falha ao criar timer");
    
    fila_contador = al_create_event_queue();
    if (!fila_contador)
        error("Falha ao criar fila do contador");


    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_eventos, al_get_timer_event_source(timer));
    al_register_event_source(fila_contador, al_get_timer_event_source(contador));
}

void finalizar (void)
{
    al_destroy_timer(timer);
    al_destroy_event_queue(fila_eventos);
    al_destroy_display(janela);
}

void error (char *msg)
{
    fprintf(stderr, "%s: %s", msg, strerror(errno));
    finalizar();
    exit(1);
}
