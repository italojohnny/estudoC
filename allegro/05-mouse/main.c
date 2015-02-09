/*
    gcc -lallegro main.c -o main && ./main
    gcc main.c -o main -lallegro-5.0.10-mt
*/
#include <allegro5/allegro.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

const int LARGURA_TELA = 640;
const int ALTURA_TELA = 480;

void error(char *msg);

int main (void)
{
    ALLEGRO_DISPLAY *janela = NULL;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_BITMAP *botao_sair = NULL, *area_central = 0;

    int sair = 0;

    if (!al_init()) error("");
    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela) error("");

    al_set_window_title(janela, "Rotinas mouse");
    
    if (!al_install_mouse()) error("");
    if (!al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT)) error("");
    
    area_central = al_create_bitmap(LARGURA_TELA/2, ALTURA_TELA/2);
    if (!area_central) error("");
    
    botao_sair = al_create_bitmap(100, 50);
    if (!botao_sair) error("");

    fila_eventos = al_create_event_queue();
    if (!fila_eventos) error("");

    al_register_event_source(fila_eventos, al_get_mouse_event_source());
    
    int na_area_central = 0;
    
    while (!sair) {
        while (!al_is_event_queue_empty(fila_eventos)) {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);
            if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
                if (evento.mouse.x >= LARGURA_TELA / 2 - al_get_bitmap_width(area_central) / 2 &&
                    evento.mouse.x <= LARGURA_TELA / 2 + al_get_bitmap_width(area_central) / 2 &&
                    evento.mouse.y >= ALTURA_TELA  / 2 - al_get_bitmap_height(area_central)/ 2 &&
                    evento.mouse.y <= ALTURA_TELA  / 2 + al_get_bitmap_height(area_central)/ 2) {
                        na_area_central = 1;
                    } else {
                        na_area_central = 0;
                    }
            } else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
                if (evento.mouse.x >= LARGURA_TELA - al_get_bitmap_width(botao_sair) - 10 && evento.mouse.x <= LARGURA_TELA - 10 && evento.mouse.y <= ALTURA_TELA - 10 && evento.mouse.y >= ALTURA_TELA - al_get_bitmap_height(botao_sair) - 10) {
                    sair = 1;
                }
            }
        }
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_set_target_bitmap(area_central);
        if (!na_area_central) {
            al_clear_to_color(al_map_rgb(255, 255, 255));
        } else {
            al_clear_to_color(al_map_rgb(0, 255, 0));
        }
        al_set_target_bitmap(botao_sair);
        al_clear_to_color(al_map_rgb(255, 0, 0));
        al_set_target_bitmap(al_get_backbuffer(janela));
        al_draw_bitmap(area_central, LARGURA_TELA / 2 - al_get_bitmap_width(area_central) / 2, ALTURA_TELA / 2 - al_get_bitmap_height(area_central) /2, 0);
        al_draw_bitmap(botao_sair, LARGURA_TELA - al_get_bitmap_width(botao_sair) - 10, ALTURA_TELA - al_get_bitmap_height(botao_sair) - 10, 0);
        al_flip_display();
    }
    al_destroy_bitmap(botao_sair);
    al_destroy_bitmap(area_central);
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);


}

void error (char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}
