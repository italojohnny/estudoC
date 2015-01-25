/*
    gcc test.c -lallegro -o test
    ./test
*/

#include <stdio.h>
#include <allegro5/allegro.h>
#include <string.h>
#include <errno.h>

void error(char *msg)
{
    fprintf(stderr, "%s: %s", msg, strerror(errno));
    exit(1);
}

int main (int argc, char *argv[])
{
    ALLEGRO_DISPLAY *window = NULL;

    if (!al_init()) error("Can't initializ...");
    window = al_create_display(640, 480);
    if (!window) error("Can't create window...");
    
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_flip_display();
    al_rest(10.0);
    al_destroy_display(window);

    return 0;
}
