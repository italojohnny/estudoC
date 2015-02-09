/*
    gcc main.c -o main -lallegro-5.0.10-mt -lallegro_image-5.0.10-mt
*/
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

const int LARGURA_TELA = 640;
const int ALTURA_TELA = 480;

ALLEGRO_BITMAP *imagem = NULL;
ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *fila_eventos;
ALLEGRO_THREAD *thread = NULL;
int sair = 0;

void inicializar (void);
void finalizar (void);
void carregar_arquivos (void);
void error (char *msg);
void *minha_thread(ALLEGRO_THREAD *thr, void *dados);

int main (void)
{
    inicializar();
    carregar_arquivos();
    
    thread = al_create_thread(minha_thread, NULL);
    al_start_thread(thread);
    al_draw_bitmap(imagem, 0, 0, 0);
    al_flip_display();
    
    while (!sair) {
        while (!al_is_event_queue_empty(fila_eventos)) {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);
            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                sair = 1;
        }
    }
    finalizar();
    return 0;
}

void inicializar (void)
{
    if (!al_init()) error("Falha ao iniciar allegro");
    if (!al_init_image_addon()) error("Falha ao inicializar add-on allegro_image");

    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela) error("Falha ao criar janela");
    al_set_window_title(janela, "testando threads");
    al_set_window_position(janela, 200, 200);

    fila_eventos = al_create_event_queue();
    if (!fila_eventos) error("Falha ao criar fila de eventos");
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
}

void finalizar (void)
{
    al_destroy_thread(thread);
    al_destroy_event_queue(fila_eventos);
    al_destroy_bitmap(imagem);
    al_destroy_display(janela);
}

void carregar_arquivos (void) 
{
    imagem = al_load_bitmap("test.jpg");
    if (!imagem) error("Falha ao carregar imagem");
}

void error (char *msg)
{
    fprintf(stderr, "%s: %s", msg, strerror(errno));
    finalizar();
    exit(1);
}

void *minha_thread(ALLEGRO_THREAD *thr, void *dados)
{
    while (!sair) {
        al_set_window_title(janela, "Thread disparada");
        al_rest(0.20);
        al_set_window_title(janela, "Thread disparada.");
        al_rest(0.20);
        al_set_window_title(janela, "Thread disparada..");
        al_rest(0.20);
        al_set_window_title(janela, "Thread disparada...");
        al_rest(0.20);
    }
    return NULL;
}
