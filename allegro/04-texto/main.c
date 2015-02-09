/*
    gcc -lallegro_ttf -lallegro_font -lallegro main.c -o main && ./main
    gcc main.c -o main -lallegro_ttf-5.0.10-mt -lallegro_font-5.0.10-mt -lallegro-5.0.10-mt
*/

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <stdio.h>
#include <string.h>
#include <errno.h>

const int LARGURA_TELA = 640;
const int ALTURA_TELA = 480;

void error (char *msg);

int main (void)
{
    ALLEGRO_DISPLAY *janela = NULL;
    ALLEGRO_FONT *fonte = NULL;

    if (!al_init()) error("1");
    al_init_font_addon();
    if (!al_init_ttf_addon()) error("2");
    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela) error("3");
    fonte = al_load_font("test.ttf", 35, 0);
    if (!fonte) {
        error("4");
        al_destroy_display(janela);
    }

    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_text(fonte, al_map_rgb(255, 0, 0), 10, 10, ALLEGRO_ALIGN_LEFT, "esquerda");
    al_draw_text(fonte, al_map_rgb(0, 255, 0), LARGURA_TELA-10, 50, ALLEGRO_ALIGN_RIGHT, "direita");
    al_draw_text(fonte, al_map_rgb(0, 0, 255), LARGURA_TELA/2, 90, ALLEGRO_ALIGN_CENTRE, "centro");
    
    int i = 2;
    char *texto = "Uma string qualquer";
    al_draw_textf(fonte, al_map_rgb(0, 0, 0), LARGURA_TELA/2, 250, ALLEGRO_ALIGN_CENTRE, "Teste %d - %s", i, texto);
    al_flip_display();
    al_rest(10.0);
    al_destroy_font(fonte);
    al_destroy_display(janela);
    return 0;
}

void error (char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}
