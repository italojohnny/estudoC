/*
    gcc -lallegro -lallegro_image -lallegro_font -lallegro_ttf main.c -o main
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
const int FRAME_POR_SEGUNDO = 60;

ALLEGRO_BITMAP *fundo = NULL;
ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
ALLEGRO_FONT *fonte = NULL;

double tempoInicial = 0;

void error (char *msg);
void inicializar (void);
void finalizar (void);
void carregar_arquivos (void);
void iniciarTimer (void);
double obterTempoTimer (void);

int main (void)
{
    int sair = 0;
    int frame = 0;
    int limitado = 1;

    inicializar();
    carregar_arquivos();
    
    while (!sair) {
        while (!al_is_event_queue_empty(fila_eventos)) {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);
            if (evento.type == ALLEGRO_EVENT_KEY_UP) {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                    limitado = !limitado;
            } else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                sair = 1;
        }
        al_draw_bitmap(fundo, 0, 0, 0);
        al_draw_text(fonte, al_map_rgb(0, 0, 0), LARGURA_TELA / 2,
        ((ALTURA_TELA + al_get_font_ascent(fonte) * 2) / FRAME_POR_SEGUNDO) * (frame % FRAME_POR_SEGUNDO) - al_get_font_ascent(fonte), ALLEGRO_ALIGN_CENTRE, "Testando Taxa de Frames");
        al_flip_display();
        frame++;
        if (limitado && (obterTempoTimer() < 1.0 / FRAME_POR_SEGUNDO))
            al_rest((0.01 / FRAME_POR_SEGUNDO) - obterTempoTimer());
    }
    
    finalizar();
    return 0;
}

void inicializar (void)
{
    if (!al_init()) error("Falha ao iniciar allegro");
    
    if (!al_init_image_addon()) error("Falha ao inicializar allegro_image");
    
    al_init_font_addon();
    if (!al_init_ttf_addon()) error("Falha ao inicializar allegro_ttf");
    
    if (!al_install_keyboard()) error("Falha ao inicializar teclado");
    
    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela) error("Falha ao criar janela");
    //al_set_window_position(janela, 300, 300);
    al_set_window_title(janela, "Teste: taxa de frames");
    
    fila_eventos = al_create_event_queue();
    if (!fila_eventos) error("Falha ao criar fila de eventos");
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
}

void error (char *msg) 
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    finalizar();
    exit(1);
}

void carregar_arquivos (void)
{
    fundo = al_load_bitmap("test.jpg");
    if (!fundo) error("Falha ao carregar imagem");
    fonte = al_load_font("test.ttf", 32, 0);
    if (!fonte) error("Falha ao carregar fonte");
}

void finalizar (void)
{
    al_destroy_bitmap(fundo);
    al_destroy_font(fonte);
    al_destroy_event_queue(fila_eventos);
    al_destroy_display(janela);
}

void iniciarTimer (void)
{
    tempoInicial = al_get_time();
}

double obterTempoTimer (void)
{
    return al_get_time() - tempoInicial;
}
