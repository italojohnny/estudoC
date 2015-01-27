/*
    gcc -lallegro -lallegro_font -lallegro_ttf -lallegro_image main.c -o main
*/
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
#include <string.h>

const int LARGURA_TELA = 640;
const int ALTURA_TELA = 480;

ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
ALLEGRO_BITMAP *fundo = NULL;
ALLEGRO_FONT *fonte = NULL;

void inicializa (void);
void error (char *msg);

int main (void)
{
    int sair = 0;
    int tecla = 0;

    inicializa();
    al_draw_bitmap(fundo, 0, 0, 0);
    while (!sair) {
        while (!al_is_event_queue_empty(fila_eventos)) {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);
            if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
                switch (evento.keyboard.keycode) {
                     case ALLEGRO_KEY_UP:
                        tecla = 1;
                     break;
                     case ALLEGRO_KEY_DOWN:
                        tecla = 2;
                     break;
                     case ALLEGRO_KEY_LEFT:
                        tecla = 3;
                     break;
                     case ALLEGRO_KEY_RIGHT:
                        tecla = 4;
                     break;
                }
            }
            else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                sair = 1;
            }
        }
        if (tecla) {
            al_draw_bitmap(fundo, 0, 0, 0);
            switch (tecla) {
                case 1:
                    al_draw_text(fonte, al_map_rgb(255, 0, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 - al_get_font_ascent(fonte) / 2, ALLEGRO_ALIGN_CENTRE, "Seta para cima");
                break;
                case 2:
                    al_draw_text(fonte, al_map_rgb(0, 255, 0), LARGURA_TELA / 2, ALTURA_TELA / 2 - al_get_font_ascent(fonte) / 2, ALLEGRO_ALIGN_CENTRE, "Seta para baixo");
                break;
                case 3:
                    al_draw_text(fonte, al_map_rgb(0, 0, 255), LARGURA_TELA / 2, ALTURA_TELA / 2 - al_get_font_ascent(fonte) / 2, ALLEGRO_ALIGN_CENTRE, "Seta esquerda");
                break;
                case 4:
                    al_draw_text(fonte, al_map_rgb(0, 255, 255), LARGURA_TELA / 2, ALTURA_TELA / 2 - al_get_font_ascent(fonte) / 2, ALLEGRO_ALIGN_CENTRE, "Seta direita");
                break;
            }
            tecla = 0;
        }
        al_flip_display();
    }
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
}

void inicializa (void)
{
    if (!al_init()) error("Falha ao inicializar Allegro");
    
    al_init_font_addon();
    if (!al_init_ttf_addon()) error("Falha ao inicializar add-on allegro_ttf");
    if (!al_init_image_addon()) error("Falha ao inicializar add-on allegro_image");
    if (!al_install_keyboard()) error("Falha ao inicializar o teclado");
    
    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela) error("Falha ao criar janela");
    
    al_set_window_title(janela, "Utilizando o teclado");
    
    fonte = al_load_font("3Dumb.ttf", 72, 0);
    if (!fonte) error("Falha ao carregar fonte");
    
    fila_eventos = al_create_event_queue();
    if (!fila_eventos) error("Falha ao criar fila de eventos");
    
    fundo = al_load_bitmap("test.jpg");
    if (!fundo) error("Falha ao carregar imagem");
    
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));

}
