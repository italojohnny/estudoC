/*
    gcc -lallegro main.c -o main && ./main
    gcc main.c -o main -lallegro-5.0.10-mt
*/

#include <allegro5/allegro.h>

int main (void)
{
    ALLEGRO_DISPLAY *janela = NULL;

    al_init();
    janela = al_create_display(640, 480);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();
    al_rest(10.0);
    al_destroy_display(janela);

    return 0;
}
