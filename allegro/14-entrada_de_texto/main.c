/*
    gcc main.c -o main -lallegro-5.0.10-mt -lallegro_image-5.0.10-mt -lallegro_ttf-5.0.10-mt -lallegro_font-5.0.10-mt
*/
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <stdio.h>
#include <string.h>
#include <errno.h>

const int LARGURA_TELA = 640;
const int ALTURA_TELA = 480;

ALLEGRO_BITMAP *fundo = NULL;
ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_FONT *fonte = NULL;
ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;

char str[17];

void manipular_entrada (ALLEGRO_EVENT evento);
void exibir_texto_centralizado (void);
void inicializar (void);
void finalizar (void);
void carregar_arquivos (void);
void error (char *msg);

int main (void)
{
    int sair = 0;
    int concluido = 0;

    inicializar();
    carregar_arquivos();

    strcpy(str, "");

    while (!sair) {
        while (!al_is_event_queue_empty(fila_eventos)) {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);
            if (!concluido) {
                manipular_entrada(evento);
                if (evento.type == ALLEGRO_EVENT_KEY_DOWN && evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                    concluido = 1;
            }
            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                sair = 1;
        }
        al_draw_bitmap(fundo, 0, 0, 0);
        if (!concluido)
            al_draw_text(fonte, al_map_rgb(128, 128, 128), LARGURA_TELA / 2, (ALTURA_TELA / 2 - al_get_font_ascent(fonte)) / 2, ALLEGRO_ALIGN_CENTRE, "Melhor Pontuação! Nome: ");
        else
            al_draw_text(fonte, al_map_rgb(128, 128, 128), LARGURA_TELA / 2, (ALTURA_TELA / 2 - al_get_font_ascent(fonte)) / 2, ALLEGRO_ALIGN_CENTRE, "1º Lugar! ");
        exibir_texto_centralizado();
        al_flip_display();
    }
    finalizar();
    return 0;
}

void inicializar (void)
{
    if (!al_init()) error("1");
    if (!al_install_keyboard()) error("2");
    al_init_font_addon();
    if (!al_init_ttf_addon()) error("3");
    if (!al_init_image_addon()) error("3.5");
    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela) error("4");
    fila_eventos = al_create_event_queue();
    if (!fila_eventos) error("5");
    al_set_window_title(janela, "Entrada de texto");

    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
}

void carregar_arquivos (void)
{
   fundo = al_load_bitmap("test.jpg");
   if (!fundo) error("6");

   fonte = al_load_font("test.ttf", 42, 0);
   if (!fonte) error("7");
}

void finalizar (void)
{
    al_destroy_bitmap(fundo);
    al_destroy_font(fonte);
    al_destroy_event_queue(fila_eventos);
    al_destroy_display(janela);
}

void manipular_entrada (ALLEGRO_EVENT evento)
{
    if (evento.type == ALLEGRO_EVENT_KEY_CHAR) {
        if (strlen(str) < 16) {
            char temp[] = {evento.keyboard.unichar, '\0'};
            if (evento.keyboard.unichar == ' ')
                strcat(str, temp);
            else if (evento.keyboard.unichar >= '0' && evento.keyboard.unichar <= '9')
                strcat(str, temp);
            else if (evento.keyboard.unichar >= 'A' && evento.keyboard.unichar <= 'Z')
                strcat(str, temp);
            else if (evento.keyboard.unichar >= 'a' && evento.keyboard.unichar <= 'z')
                strcat(str, temp);
        }
        if (evento.keyboard.keycode == ALLEGRO_KEY_BACKSPACE && strlen(str) != 0)
            str[strlen(str) - 1] = '\0';
    }
}

void exibir_texto_centralizado (void)
{
    if (strlen(str) > 0)
        al_draw_text(fonte, al_map_rgb(128, 128, 128), LARGURA_TELA / 2, (ALTURA_TELA - al_get_font_ascent(fonte)) / 2, ALLEGRO_ALIGN_CENTRE, str);
}

void error (char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    finalizar();
    exit(1);
}
