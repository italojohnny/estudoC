/*
    gcc -lallegro_imagem -allegro main.c -o main
*/
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include <stdio.h>
#include <string.h>
#include <errno.h>

const int LARGURA_TELA = 640;
const int ALTURA_TELA = 480;

void error (char *msg);

int main (void)
{
    ALLEGRO_DISPLAY *janela = NULL;
    ALLEGRO_BITMAP *imagem = NULL;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;

    if (!al_init()) error("Falha ao iniciar a Allegro");
    if (!al_init_image_addon()) error("Falha ao iniciar add-on allegro_image");

    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela) error("Falha ao criar janela");
//=========================    
    imagem = al_load_bitmap("/home/zak/Documents/estudo_c/allegro/03-evento/test.jpg");
    if (!imagem) error("Falha ao carregar o arquivo de imagem");
//=========================
    fila_eventos = al_create_event_queue();
    if (!fila_eventos) error("Falha ao criar fila de eventos");
    
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_draw_bitmap(imagem, 0, 0, 0);
    al_flip_display();
    while (1) {
        ALLEGRO_EVENT evento;
        ALLEGRO_TIMEOUT timeout;
        al_init_timeout(&timeout, 0.05);
        int tem_eventos = al_wait_for_event_until(fila_eventos, &evento, &timeout);
        if (tem_eventos && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }
        al_draw_bitmap(imagem, 0, 0, 0);
        al_flip_display();
    }
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
    return 0;
}

void error (char *msg)
{
    fprintf(stderr, "%s - %s\n", msg, strerror(errno));
    exit(1);
}
