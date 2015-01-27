/*
    gcc -lallegro_image -lallegro main.c -o main && ./main
*/

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

int main (void)
{
    ALLEGRO_DISPLAY *janela = NULL;
    ALLEGRO_BITMAP *imagem = NULL;
    al_init();
    al_init_image_addon();
    janela = al_create_display(640, 480);
    imagem = al_load_bitmap("test.jpg");
    al_draw_bitmap(imagem, 0, 0, 0);
    al_flip_display();
    al_rest(10.0);
    al_destroy_display(janela);
    
    return 0;
}
