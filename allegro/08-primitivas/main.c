/*
    gcc -lallegro -lallegro_primitives main.c -o main && ./main
    gcc main.c -o main -lallegro-5.0.10-mt -lallegro_audio-5.0.10-mt -lallegro_acodec-5.0.10-mt
*/
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include <stdio.h>
#include <string.h>
#include <errno.h>

const int LARGURA_TELA = 640;
const int ALTURA_TELA = 480;

ALLEGRO_DISPLAY *janela = NULL;

void inicializar (void);
void finalizar (void);
void error (char *msg);

int main (void)
{
    inicializar();
    // Linha: x1, y1, x2, y2, cor, espessura
    al_draw_line(20.0, 40.0, 40.0, 60.0, al_map_rgb(255, 0, 0), 1.0);
    al_flip_display();
 
    al_rest(2.0);
 
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();
 
    al_rest(0.5);
 
    // Triângulo: x1, y1, x2, y2, x3, y3, cor, espessura
    al_draw_triangle(70.0, 30.0, 20.0, 55.0, 110.0, 250.0, al_map_rgb(255, 255, 255), 5.0);
    al_flip_display();
 
    al_rest(2.0);
 
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();
 
    al_rest(0.5);
 
    // Triângulo preenchido: x1, y1, x2, y2, x3, y3, cor
    al_draw_filled_triangle(40.0, 90.0, 120.0, 246.0, 400.0, 23.0, al_map_rgb(255, 255, 0));
    al_flip_display();
 
    al_rest(2.0);
 
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();
 
    al_rest(0.5);
 
    // Retângulo: x1, y1, x2, y2, cor, espessura
    al_draw_rectangle(70.0, 30.0, 110.0, 250.0, al_map_rgb(255, 0, 255), 6.0);
    al_flip_display();
 
    al_rest(2.0);
 
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();
 
    al_rest(0.5);
 
    // Retângulo preenchido: x1, y1, x2, y2, cor
    al_draw_filled_rectangle(88.0, 10.0, 340.0, 77.0, al_map_rgb(0, 255, 255));
    al_flip_display();
 
    al_rest(2.0);
 
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();
 
    al_rest(0.5);
 
    // Elipse: x1, y1, raio x, raio y, cor, espessura
    al_draw_ellipse(70.0, 90.0, 20.0, 55.0, al_map_rgb(255, 255, 255), 5.0);
    al_flip_display();
 
    al_rest(2.0);
 
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();
 
    al_rest(0.5);
 
    // Elipse preenchido: x1, y1, raio x, raio y, cor
    al_draw_filled_ellipse(98.0, 145.0, 25.0, 15.0, al_map_rgb(128, 255, 128));
    al_flip_display();
 
    al_rest(2.0);
 
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();
 
    al_rest(0.5);
 
    // Círculo: x1, y1, raio, cor, espessura
    al_draw_circle(250.0, 300.0, 70.0, al_map_rgb(128, 0, 0), 2.0);
    al_flip_display();
 
    al_rest(2.0);
 
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();
 
    al_rest(0.5);
 
    // Círculo preenchido: x1, y1, raio, cor
    al_draw_filled_circle(350.0, 50.0, 43.0, al_map_rgb(0, 0, 255));
    al_flip_display();
 
    al_rest(2.0);
 
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();
 
    al_rest(0.5); 	 	
    finalizar();
    return 0;
}

void inicializar (void)
{
    if (!al_init()) error("Falha ao iniciar a biblioteca allegro");
    if (!al_init_primitives_addon()) error("Falha ao iniciar add-on de primitivas");

    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela) error("Falha ao criar janela");
    al_set_window_title(janela, "Testando allegro_primitives");
}

void finalizar (void)
{
    al_destroy_display(janela);
}

void error (char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}
