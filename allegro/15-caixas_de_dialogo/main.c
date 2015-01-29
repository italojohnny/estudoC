#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>

int main (void)
{
    if (al_show_native_message_box(NULL, "titulo1", "sub-titulo", "pergunta", NULL, ALLEGRO_MESSAGEBOX_YES_NO))
        al_show_native_message_box(NULL, "titulo2", "sub-titulo", "pergunta", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    else
        al_show_native_message_box(NULL, "titulo3", "sub-titulo", "pergunta", NULL, ALLEGRO_MESSAGEBOX_QUESTION);

    if (al_show_native_message_box(NULL, "titulo4", "sub-titulo", "pergunta", NULL, ALLEGRO_MESSAGEBOX_OK_CANCEL))
        al_show_native_message_box(NULL, "titulo5", "sub-titulo", "pergunta", NULL, ALLEGRO_MESSAGEBOX_WARN);
}
