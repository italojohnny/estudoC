#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include <stdio.h>
#include <string.h>
#include <errno.h>

const int LARGURA_TELA = 640;
const int ALTURA_TELA = 480;

ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;

void inicializar (void);
void finalizar (void);
void error (char *msg);

int main (void)
{
    int sair = 0;
    inicializar();
    
    float raio = 30.0f;
    float x = raio;
    float y = raio;
    int dir_x = 1;
    int dir_y = 1;

    while (!sair) {
        if (!al_is_event_queue_empty(fila_eventos)) {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);
            
            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) sair =1;
        }
        al_draw_filled_circle(x, y, raio, al_map_rgb(0, 255, 0));
        al_flip_display();
        al_clear_to_color(al_map_rgb(0, 0, 0));
        x += 1.0f * dir_x;
        y += 1.0f * dir_y;

        if (x >= LARGURA_TELA - raio) {
            dir_x = -1;
            x = LARGURA_TELA - raio;
        } else if (x <= raio) {
            dir_x = 1;
            x = raio;
        }

        if (y >= ALTURA_TELA - raio) {
            dir_y = -1;
            y = ALTURA_TELA - raio;
        } else if (y <= raio) {
            dir_y = 1;
            y = raio;
        }
        al_rest (0.005);
    }

    finalizar();
    return 0;
}

void inicializar (void) 
{
    if (!al_init()) error("Falha ao iniciar allegro");
    if (!al_init_primitives_addon()) error("Falha ao iniciar add-on allegro_primitives");
    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela) error("Falha ao criar janela");
    al_set_window_title(janela, "Animacao");
    fila_eventos = al_create_event_queue();
    if (!fila_eventos) error("Falha ao criar fila de eventos");
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
}

void finalizar (void) 
{
    al_destroy_event_queue(fila_eventos);
    al_destroy_display(janela);
}

void error (char *msg) 
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}
