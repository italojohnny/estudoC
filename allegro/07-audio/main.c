/*
    gcc -lallegro -lallegro_audio -lallegro_acodec main.c -o main && ./main
*/
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include <stdio.h>
#include <string.h>
#include <errno.h>

const int LARGURA_TELA = 640;
const int ALTURA_TELA = 480;

ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_AUDIO_STREAM *musica = NULL;
ALLEGRO_SAMPLE *sample = NULL;
ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;

void inicializar (void);
void finalizar (void);
void error (char *msg);

int main (void)
{
    int sair = 0;
    inicializar();
    
    al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
    al_set_audio_stream_playing(musica, 1);
    while (!sair) {
        while (!al_is_event_queue_empty(fila_eventos)) {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_UP) {
                if (evento.keyboard.keycode == ALLEGRO_KEY_SPACE) {
                    al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                }
            } else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                sair = 1;
            }
        }
    }

    finalizar();
    return 0;
}

void inicializar (void)
{
    if (!al_init()) error("Falha ao inicializar allegro");
    if (!al_install_audio()) error("Falha ao inicializar audio");
    if (!al_init_acodec_addon()) error("Falha ao inicializar codecs de audio");
    if (!al_reserve_samples(1)) error("Falha ao alocar canais de audio");
    if (!al_install_keyboard()) error("Falha ao iniciar teclado");
    
    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela) error("Falha ao criar janela");

    sample = al_load_sample("bigboom.wav");
    if (!sample) error("Falha ao carregar sample");

    fila_eventos = al_create_event_queue();
    if (!fila_eventos) error("Falha ao criar fila de eventos");

    al_set_window_title(janela, "Testando sons");
    
    musica = al_load_audio_stream("music.ogg", 4, 1024);
    if (!musica) error("Falha ao carregar audio");

    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
}

void finalizar (void)
{
    al_destroy_audio_stream(musica);
    al_destroy_sample(sample);
    al_destroy_event_queue(fila_eventos);
    al_destroy_display(janela);
}

void error (char *msg)
{
    fprintf(stderr, "%s: %s", msg, strerror(errno));
    exit(1);
}
