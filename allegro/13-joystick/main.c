#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

const int LARGURA_TELA = 640;
const int ALTURA_TELA = 480;
ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *fila_evento = NULL;
ALLEGRO_JOYSTICK *joystick = NULL;

void inicializar (void);
void finalizar (void);
void error (char *msg);

int main (void)
{
    int sair = 0;
    inicializar();
    const int raio = 25;
    int x = raio;
    int y = raio;
    int inc_x = 0, inc_y = 0;
    ALLEGRO_COLOR cor = al_map_rgb(128, 128, 128);
    while (!sair) {
        while (!al_is_event_queue_empty(fila_evento)) {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_evento, &evento);
            if (evento.type == ALLEGRO_EVENT_JOYSTICK_AXIS) {
                if (evento.joystick.axis == 0)
                    inc_x = evento.joystick.pos;
                else if (evento.joystick.axis == 1)
                    inc_y = evento.joystick.pos;
            } else if (evento.type == ALLEGRO_EVENT_JOYSTICK_BUTTON_DOWN) {
                switch (evento.joystick.button) {
                    case 1:     cor = al_map_rgb(255, 0, 0);
                                break;
                    case 2:     cor = al_map_rgb(0, 255, 0);
                                break;
                    case 3:     cor = al_map_rgb(0, 0, 255);
                                break;
                    default:    cor = al_map_rgb(128, 128, 128);
                                break;
                }
            } else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                sair = 1;
        }
        x += inc_x;
        if (x > LARGURA_TELA - raio)
            x = LARGURA_TELA - raio;
        else if (x < raio)
            x = raio;
        y += inc_y;
        if (y > ALTURA_TELA - raio)
            y = ALTURA_TELA - raio;
        else if (y < raio)
            y = raio;
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_filled_circle(x, y, raio, cor);
        al_flip_display();
    }
    finalizar();
    return 0;
}

void inicializar (void)
{
    if (!al_init()) error("Falha ao iniciar allegro");
    if (!al_init_primitives_addon()) error("Falha ao iniciar primitives");
    if (!al_install_joystick()) error("Falha ao iniciar teclado");
    al_reconfigure_joysticks();
    if (al_get_num_joysticks() == 0) error("Nenhum joystic encontrado");
    joystick = al_get_joystick(al_get_num_joysticks() - 1);

    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela) error("Falha ao criar janela");
    al_set_window_title(janela, "joystick");
    
    fila_evento = al_create_event_queue();
    if (!fila_evento) error("Falha ao criar fila de evento");

    al_register_event_source(fila_evento, al_get_display_event_source(janela));
    al_register_event_source(fila_evento, al_get_joystick_event_source());
}

void finalizar (void)
{
    al_destroy_event_queue(fila_evento);
    al_destroy_display(janela);
}

void error (char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    finalizar();
    exit(1);
}
