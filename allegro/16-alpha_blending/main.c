/*
    gcc -lallegro -lallegro_image main.c -o main && ./main
*/
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

const int LARGURA_TELA = 640;
const int ALTURA_TELA = 480;

ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_BITMAP *fundo = NULL;

void inicializar (void);
void finalizar (void);
void carregar_arquivos (void);
void fadeout (int velocidade);
void fadein (ALLEGRO_BITMAP *imagem, int velocidade);
void error (char *msg);

int main (void)
{
    inicializar();
    carregar_arquivos();
    
    fadein(fundo, 1);
    al_rest(3.0);
    
    finalizar();
    return 0;
}

void fadeout (int velocidade)
{
    ALLEGRO_BITMAP *buffer = NULL;
    buffer = al_create_bitmap(LARGURA_TELA, ALTURA_TELA);
    al_set_target_bitmap(buffer);
    al_draw_bitmap(al_get_backbuffer(janela), 0, 0, 0);
    al_set_target_bitmap(al_get_backbuffer(janela));

    if (velocidade <= 0)
        velocidade = 1;
    else if (velocidade > 15)
        velocidade = 15;

    int alfa;
    for (alfa = 0; alfa <= 255; alfa++) {
        al_clear_to_color(al_map_rgba(0, 0, 0, 0));
        al_draw_tinted_bitmap(buffer, al_map_rgba(255 - alfa, 255 - alfa, 255 - alfa,  alfa), 0, 0, 0);
        al_flip_display();
        al_rest(0.005);
    }
    al_destroy_bitmap(buffer);
}

void fadein (ALLEGRO_BITMAP *imagem, int velocidade) 
{
    if (velocidade < 0)
        velocidade = 1;
    else if (velocidade > 15)
        velocidade = 15;
    int alfa;
    for (alfa = 0; alfa <= 255; alfa += velocidade) {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_tinted_bitmap(imagem, al_map_rgba(alfa, alfa, alfa, alfa), 0, 0, 0);
        al_flip_display();
        al_rest(0.005);
    }
}

void inicializar (void)
{
    if (!al_init()) error("");
    if (!al_init_image_addon()) error("");
    
    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela) error("");
}

void carregar_arquivos (void)
{
    fundo = al_load_bitmap("test.jpg");
    if (!fundo) error("");

}

void finalizar (void)
{
    al_destroy_bitmap(fundo);
    al_destroy_display(janela);

}

void error (char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    finalizar();
    exit(1);
}
