/*
    E sempre bom ter um arquivo fonte separado para lidar com o nucleo do jogo.
    O codigo aqui precisara ficar atento a teclas pressionadas, executar um
    temporizador e, tambem dizer para todas as outras naves, asteroides e tiros
    como se mover pela tela.
*/
#include "defines.h"
#include "spaceship.h"
#include "blast.h"
#include "asteroid.h"

ALLEGRO_DISPLAY *myDisplay = NULL;
ALLEGRO_EVENT_QUEUE *myEventQueue = NULL;
ALLEGRO_FONT *myFont = NULL;
ALLEGRO_FONT *myFontTitle = NULL;
ALLEGRO_FONT *myFontEmail = NULL;

int statusGame;
int scoreGame;

Spaceship ship;
//Asteroid a, b, d, e;
Asteroid *asteroid_origin, *A;
Blast *blast_origin, *Q;

bool btn_up, btn_down, btn_left, btn_right, btn_fire, btn_start;

int main (void)
{
    tmp = 0;
    srand(time(NULL));
    statusGame = 1;
    scoreGame = 0;
    inicialize();

    ship_start(&ship);
    //asteroid_start(&a);
    //asteroid_start(&b);
    //asteroid_start(&d);
    //asteroid_start(&e);
    loop();

    finalize();
    return 0;
}

void loop (void)
{
    /* inicia threas para desenhar, teclado e tempo */
    while (statusGame) {
        ALLEGRO_EVENT evento;

        if (!al_is_event_queue_empty(myEventQueue)) {
            //ALLEGRO_EVENT evento;
            al_wait_for_event(myEventQueue, &evento);
            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE ||(evento.type == ALLEGRO_EVENT_KEY_DOWN && evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE))
                statusGame = 0;
        }
        keyboard(evento);
        timer();
        draw();
    }
}

void keyboard (ALLEGRO_EVENT key_event)
{
    if (key_event.type == ALLEGRO_EVENT_KEY_UP) {
		switch (statusGame) {
			case 2:
				switch (key_event.keyboard.keycode) {
					case ALLEGRO_KEY_SPACE://atira
						btn_fire = false;
					break;
                    case ALLEGRO_KEY_UP:
						btn_up = false;
					break;
					case ALLEGRO_KEY_LEFT://vira sentido anti-horario
						btn_left = false;
                    break;
                    case ALLEGRO_KEY_RIGHT://vira sentido horario
						btn_right = false;
                    break;
				}
			break;
		}
	}

    if (key_event.type == ALLEGRO_EVENT_KEY_DOWN) {
        switch (statusGame) {
            case 1:
                if (key_event.keyboard.keycode == ALLEGRO_KEY_ENTER)
                    statusGame = 2;
            break;
            case 2://o jogo
                switch (key_event.keyboard.keycode) {
                    case ALLEGRO_KEY_ESCAPE:
                        statusGame = 0;
                    break;
                    case ALLEGRO_KEY_SPACE://atira
						btn_fire = true;
                   break;
                    case ALLEGRO_KEY_UP:
						btn_up = true;
                    break;
                    case ALLEGRO_KEY_DOWN://freia

                    break;
                    case ALLEGRO_KEY_LEFT://vira sentido anti-horario
						btn_left = true;
                    break;
                    case ALLEGRO_KEY_RIGHT://vira sentido horario
						btn_right = true;
                    break;
                }
            break;
            case 3: break;
            case 4: break;
            case 5: break;
        }
    }
}

void timer (void)
{
    switch (statusGame) {
        case 1: break;//tela de start
        case 2://o jogo
			if (btn_fire) {
				blast_shoot(&blast_origin, &ship);
				btn_fire = false;
			}

			if (ship.boost < 0.0) ship.boost = 0;
			if (ship.boost > 1.0) ship.boost = 1.0;

			if (btn_up) {
				ship_advance(&ship);
				ship.boost += 0.1;
			}
			else if (ship.boost > 0.0 && btn_up == false) {
				ship_advance(&ship);
				ship.boost -= 0.01;
			}

			if (btn_down){}

			if (btn_left) ship_spin(&ship, -1.0);
			if (btn_right) ship_spin(&ship, 1.0);

		break;
        case 3: break;//game over
        case 4: break;//tela de record score
        case 5: break;//gravar seu record
    }
}

void draw (void)
{
    al_clear_to_color(al_map_rgb(0, 0, 0));
    switch (statusGame) {
        case 1://tela de start
             al_draw_text(myFontTitle, al_map_rgb(255, 0, 0), WIDTH/2, HEIGHT/2, ALLEGRO_ALIGN_CENTRE, "Blasteroids");
             al_draw_text(myFont, al_map_rgb(0, 255, 0), WIDTH/2, HEIGHT/2+110, ALLEGRO_ALIGN_CENTRE, "- START -");
             al_draw_text(myFont, al_map_rgb(0, 255, 0), WIDTH/2, HEIGHT/2+130, ALLEGRO_ALIGN_CENTRE, "INSTRUCTIONS");
             al_draw_text(myFont, al_map_rgb(0, 255, 0), WIDTH/2, HEIGHT/2+150, ALLEGRO_ALIGN_CENTRE, "GAME CREDITS");
             al_draw_text(myFontEmail, al_map_rgb(0, 0, 255), WIDTH/2, HEIGHT-15, ALLEGRO_ALIGN_CENTRE, "italojohnnydosanjos@gmail.com");
        break;
        case 2://o jogo
            al_draw_textf(myFont, al_map_rgb(0,255, 0), 0, 0, ALLEGRO_ALIGN_LEFT, "%05d", scoreGame);
            //al_draw_textf(myFont, al_map_rgb(0,255, 0), 1, 40, ALLEGRO_ALIGN_LEFT, "an: %f", ship.heading);
            //al_draw_textf(myFont, al_map_rgb(0,255, 0), 1, 70, ALLEGRO_ALIGN_LEFT, "sx: %f", ship.sx);
            //al_draw_textf(myFont, al_map_rgb(0,255, 0), 1, 100, ALLEGRO_ALIGN_LEFT, "sy: %f", ship.sy);
            //al_draw_textf(myFont, al_map_rgb(0,255, 0), 1, 130, ALLEGRO_ALIGN_LEFT, "boost: %f", ship.boost);

            ship_draw(&ship);
            //draw_asteroid(&a);
            //draw_asteroid(&b);
            //draw_asteroid(&d);
            //draw_asteroid(&e);
            blast_draw(&blast_origin);
/*
			Q = blast_origin;

			printf("\n------------------------\n");
            while (Q != NULL) {
                printf("<-(%d) ", Q->id);
                Q = Q->next;
            }
*/
        break;
        case 3://game over
            al_draw_text(myFont, al_map_rgb(0, 255, 0), WIDTH/2, HEIGHT/2, ALLEGRO_ALIGN_CENTRE, "GAME OVER");
        break;
        case 4://tela de record score
            al_draw_text(myFont, al_map_rgb(0, 255, 0), WIDTH/2, HEIGHT/2, ALLEGRO_ALIGN_CENTRE, "RECORD SCORE");
        break;
        case 5://gravar seu record
            al_draw_text(myFont, al_map_rgb(0, 255, 0), WIDTH/2, HEIGHT/2, ALLEGRO_ALIGN_CENTRE, "INPUT NEW RECORD");
        break;
    }
    al_flip_display();
}

void inicialize (void)
{
    if (!al_init()) error("allegro");

    if (!al_init_primitives_addon()) error("add-on allegro_primitives");

    al_init_font_addon();
    if (!al_init_ttf_addon()) error("add-on allegro_ttf");

    myFont = al_load_font("pixel.ttf", 35, 0);
    myFontTitle = al_load_font("pixel.ttf", 80, 0);
    myFontEmail = al_load_font("pixel.ttf", 25, 0);
    if (!myFont || !myFontTitle || !myFontEmail) error("font");

    if (!al_install_keyboard()) error("keyboard");

    myDisplay = al_create_display(WIDTH, HEIGHT);
    if (!myDisplay) error("create display");
    al_set_window_title(myDisplay, "Blasteroids");

    myEventQueue = al_create_event_queue();
    if (!myEventQueue) error("create event queue");

    al_register_event_source(myEventQueue, al_get_display_event_source(myDisplay));
    al_register_event_source(myEventQueue, al_get_keyboard_event_source());

	btn_up = btn_down = btn_left = btn_right = btn_fire = btn_start = false;
}

void finalize (void)
{
    al_destroy_event_queue(myEventQueue);
    al_destroy_display(myDisplay);
}

void errro (char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    finalize();
    exit(1);
}
