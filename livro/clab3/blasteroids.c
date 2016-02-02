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
ALLEGRO_FONT *myFontInfo = NULL;

int statusGame;
int scoreGame;
int menuGame;

Spaceship ship;
Asteroid *asteroid_origin, *Q;
Blast *blast_origin;

typedef struct {
	int ponts;
	char name[5];
} Record;
Record records[10];

bool btn_up, btn_down, btn_left, btn_right, btn_fire, btn_start;

int main (void)
{
    srand(time(NULL));
    statusGame = 1;
	menuGame = 0;

    inicialize();
    loop();
    finalize();

    return 0;
}
void start_game (void)
{
	btn_up = btn_down = btn_left = btn_right = btn_fire = btn_start = false;
    tmp = 0;
    scoreGame = 0;
	ship_start(&ship);
	ship.gone = 0;
    asteroid_start(&asteroid_origin, 3, 150.0,-280.0, 3);
    asteroid_start(&asteroid_origin, 3, 550.0,-150.0, 2);
    asteroid_start(&asteroid_origin, 3, 50.0,-100.0, 1);
    //asteroid_start(&asteroid_origin, 3, 20.0, 20.0, 0);
    //asteroid_start(&asteroid_origin, 3, 30.0, 30.0, 0);
    //asteroid_start(&asteroid_origin, 3, 40.0, 40.0, 0);
}

void loop (void)
{
    /* inicia threas para desenhar, teclado e tempo */
    while (statusGame) {
        ALLEGRO_EVENT evento;

        if (!al_is_event_queue_empty(myEventQueue)) {
            //ALLEGRO_EVENT evento;
            al_wait_for_event(myEventQueue, &evento);
            //if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE ||(evento.type == ALLEGRO_EVENT_KEY_DOWN && evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE))
                //statusGame = 0;
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
            case 1://TELA INICIAL
				switch (key_event.keyboard.keycode) {
					case ALLEGRO_KEY_ESCAPE:
						statusGame = 0;
					break;
					case ALLEGRO_KEY_UP:
						if (menuGame == 0) menuGame = 4;
						else menuGame--;
					break;
					case ALLEGRO_KEY_DOWN:
						if (menuGame == 4) menuGame = 0;
						else menuGame++;
					break;
					case ALLEGRO_KEY_ENTER:
						switch(menuGame) {
							case 0: start_game(); statusGame = 2; break;//vai para o jogo
							case 1: statusGame = 6; break;//vai para a tela de instrucoes
							case 2: statusGame = 5; break;//vai para a tela de records
							case 3: statusGame = 7; break;//vai para a tela de creditos do jogo
							case 4: exit(0);  break;//vai para a tela de creditos do jogo
						}
						break;
				}
            break;
            case 2://O JOGO
                switch (key_event.keyboard.keycode) {
                    case ALLEGRO_KEY_ESCAPE:
                        statusGame = 1;
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
            case 3: if (key_event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) statusGame = 1; break;//GAME OVER
            case 4: break;//GRAVAR SEU RECORD
            case 5: if (key_event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) statusGame = 1; break;//TELA DE RECORD SCORE
			case 6: if (key_event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) statusGame = 1; break;//TELA DE INSTRUCOES
			case 7: if (key_event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) statusGame = 1; break;//TELA DE CREDITOS DO JOGO
        }
    }
}

void timer (void)
{
	//int cs, ca;
    switch (statusGame) {
        case 1://tela de start
			//contador de tempo. Depois de x tempo decorrido nessa tela sem o jogador fazer nada - ir para tela de records
		break;
        case 2://O jogo
			//cs = ca = 0;
			//verificacao de colisao dos tiros com os asteroids
			if (blast_origin != NULL && asteroid_origin != NULL) {
				Blast *tcs = blast_origin;//teste colisao shoot tcs
				while (tcs != NULL) {
					if (!tcs->gone) {
						Asteroid *tca = asteroid_origin;//teste colisao asteroid tca
						while (tca != NULL) {
							if (tca->gone == 0) {
								if (sqrt((tca->sx - tcs->sx)*(tca->sx - tcs->sx) + (tca->sy - tcs->sy)*(tca->sy - tcs->sy)) < (tca->scale*12.5 + 0.1)) {
									tcs->gone = 1;
									tca->gone = 1;
									scoreGame++;
									if (tca->scale > 1)
										asteroid_start(&asteroid_origin, tca->scale-1, tca->sx, tca->sy, tcs->heading + 60);
										asteroid_start(&asteroid_origin, tca->scale-1, tca->sx, tca->sy, tcs->heading - 60);
								}
							}
							tca = tca->next;
						}
					}
					tcs = tcs->next;
				}
			}
			//verificacao de colisao dos asteroids com a navinha
			if (asteroid_origin !=NULL && !ship.gone) {
				Asteroid *tca = asteroid_origin;//teste colisao asteroid tca
				while (tca != NULL) {
					if (tca->gone == 0) {
						if (sqrt((tca->sx - ship.sx)*(tca->sx - ship.sx) + (tca->sy - ship.sy)*(tca->sy - ship.sy)) < (tca->scale*12.5 + 10)) {
							printf("\n----colisao com nave------\n%i\n%f\n%f\n------------\n", tca->gone, tca->sx, tca->sy);
							if (tca->gone == 0)
								if (tca->gone == 0) 
									tca->color = al_map_rgb(255,255,255);
									ship.gone = 1;
									//tca->gone = 1;
						}
					}
					tca = tca->next;
				}
			}

			if (btn_fire) {
				blast_shoot(&blast_origin, &ship);
				//btn_fire = false;
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
			//if (ship.gone >= 16 ) statusGame = 3;

		break;
        case 3: break;//GAME OVER
        case 4: break;//GRAVAR SEU RECORD
        case 5: break;//TELA DE RECORD SCORE
		case 6: break;//TELA DE INSTRUCOES
		case 7: break;//TELA DE CREDITOS DO JOGO
    }
}

void draw (void)
{
    al_clear_to_color(al_map_rgb(0, 0, 0));
    switch (statusGame) {
        case 1://TELA DE START
			al_draw_text(myFontTitle, al_map_rgb(255, 0, 0), WIDTH/2, HEIGHT/2, ALLEGRO_ALIGN_CENTRE, "Blasteroids");

			if (menuGame == 0)
				al_draw_text(myFont, al_map_rgb(0, 255, 0), WIDTH/2, HEIGHT/2+100, ALLEGRO_ALIGN_CENTRE, "- START -");
			else
				al_draw_text(myFont, al_map_rgb(0, 255, 0), WIDTH/2, HEIGHT/2+100, ALLEGRO_ALIGN_CENTRE, "START");
			if (menuGame == 1)
				al_draw_text(myFont, al_map_rgb(0, 255, 0), WIDTH/2, HEIGHT/2+120, ALLEGRO_ALIGN_CENTRE, "- INSTRUCTIONS -");
			else
				al_draw_text(myFont, al_map_rgb(0, 255, 0), WIDTH/2, HEIGHT/2+120, ALLEGRO_ALIGN_CENTRE, "INSTRUCTIONS");
			if (menuGame == 2)
				al_draw_text(myFont, al_map_rgb(0, 255, 0), WIDTH/2, HEIGHT/2+140, ALLEGRO_ALIGN_CENTRE, "- RECORDS SCORE -");
			else
				al_draw_text(myFont, al_map_rgb(0, 255, 0), WIDTH/2, HEIGHT/2+140, ALLEGRO_ALIGN_CENTRE, "RECORDS SCORE");
			if (menuGame == 3)
				al_draw_text(myFont, al_map_rgb(0, 255, 0), WIDTH/2, HEIGHT/2+160, ALLEGRO_ALIGN_CENTRE, "- GAME CREDITS -");
			else
				al_draw_text(myFont, al_map_rgb(0, 255, 0), WIDTH/2, HEIGHT/2+160, ALLEGRO_ALIGN_CENTRE, "GAME CREDITS");
			if (menuGame == 4)
				al_draw_text(myFont, al_map_rgb(0, 255, 0), WIDTH/2, HEIGHT/2+180, ALLEGRO_ALIGN_CENTRE, "- EXIT -");
			else
				al_draw_text(myFont, al_map_rgb(0, 255, 0), WIDTH/2, HEIGHT/2+180, ALLEGRO_ALIGN_CENTRE, "EXIT");
        break;
        case 2://O JOGO
            al_draw_textf(myFont, al_map_rgb(0,255, 0), 0, 0, ALLEGRO_ALIGN_LEFT, "%05d", scoreGame);
            //al_draw_textf(myFont, al_map_rgb(0,255, 0), 1, 40, ALLEGRO_ALIGN_LEFT, "an: %f", ship.heading);
            //al_draw_textf(myFont, al_map_rgb(0,255, 0), 1, 70, ALLEGRO_ALIGN_LEFT, "sx: %f", ship.sx);
            //al_draw_textf(myFont, al_map_rgb(0,255, 0), 1, 100, ALLEGRO_ALIGN_LEFT, "sy: %f", ship.sy);
            //al_draw_textf(myFont, al_map_rgb(0,255, 0), 1, 130, ALLEGRO_ALIGN_LEFT, "boost: %f", ship.boost);

            ship_draw(&ship);
            draw_asteroid(&asteroid_origin);
            blast_draw(&blast_origin);
/*
			Q = asteroid_origin;

			printf("\n------------------------\n");
            while (Q != NULL) {
                printf("<-(%d) ", Q->id);
                Q = Q->next;
            }
*/
        break;
        case 3://GAME OVER
            al_draw_text(myFont, al_map_rgb(0, 255, 0), WIDTH/2, HEIGHT/2, ALLEGRO_ALIGN_CENTRE, "GAME OVER");
        break;
        case 4://GRAVAR SEU RECORD
            al_draw_text(myFont, al_map_rgb(0, 255, 0), WIDTH/2, HEIGHT/2, ALLEGRO_ALIGN_CENTRE, "INPUT NEW RECORD");
        break;
        case 5://TELA DE RECORD SCORE
            al_draw_text(myFont, al_map_rgb(0, 255, 0), WIDTH/2, HEIGHT/2, ALLEGRO_ALIGN_CENTRE, "RECORDS SCORE");
        break;
		case 6://TELA DE INSTRUCOES
            al_draw_text(myFont, al_map_rgb(0, 255, 0), WIDTH/2, HEIGHT/2, ALLEGRO_ALIGN_CENTRE, "INSTRUCTIONS");
/*
 * Use as setas cima e baixo para selecionar um menu desejado
 * Use a tecla enter para acessar o menu selecionado.
 * Use a tecla esc para sair do menu selecionado.
 *
 * 	O objetivo do é conseguir o maximo de pontos possíveis destruindo os asteroids, sem deixar algum deles atingir sua nave.
 * 		Durante o jogo:
 * 			* Use a seta cima para acelerar
 * 			* Use a seta baixo para freiar
 * 			* use a setas esquerda ou direita para mudar a direção da nava
 * 			* use o botao espaco para atirar contra os asteroids
 * 			* use teclas esc para sair do jogo.
 *
 *
 * Use the up and down keys to select a desired menu
 * Use the enter key to access the selected menu
 * Use the escape key to exit selected menu
 *
*/
		break;
		case 7://TELA DE CREDITOS DO JOGO
            al_draw_text(myFontTitle, al_map_rgb(255, 0, 0), WIDTH/2, 5, ALLEGRO_ALIGN_CENTRE, "GAME CREDITS");
            al_draw_text(myFont, al_map_rgb(0, 255, 0), WIDTH/2, 155, ALLEGRO_ALIGN_CENTRE, "This game is a tribute to the classic arcade Spacewar.");
            al_draw_text(myFont, al_map_rgb(0, 255, 0), WIDTH/2, 175, ALLEGRO_ALIGN_CENTRE, "Developed with Allegro5 library in language C, for learningi");
            al_draw_text(myFont, al_map_rgb(0, 255, 0), WIDTH/2, 195, ALLEGRO_ALIGN_CENTRE, "purposes, therefore, does not seek any profit.");
            al_draw_text(myFont, al_map_rgb(0, 255, 0), WIDTH/2, 215, ALLEGRO_ALIGN_CENTRE, "The game code is available on github, at the address:");
            al_draw_text(myFontInfo, al_map_rgb(0, 0, 255), WIDTH/2, 235, ALLEGRO_ALIGN_CENTRE, "https://github.com/italojohnny/estudoC/tree/master/livro/clab3");
            al_draw_text(myFont, al_map_rgb(0, 255, 0), WIDTH/2, 265, ALLEGRO_ALIGN_CENTRE, "To contact the planned, write to:");
            al_draw_text(myFontInfo, al_map_rgb(0, 0, 255), WIDTH/2, 285, ALLEGRO_ALIGN_CENTRE, "italojohnnydosanjos@gmail.com");
            al_draw_text(myFontTitle, al_map_rgb(0, 255, 0), WIDTH/2, 390, ALLEGRO_ALIGN_CENTRE, "I hope you enjoy the game!");
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
    myFontInfo = al_load_font("pixel.ttf", 30, 0);
    if (!myFont || !myFontTitle || !myFontInfo) error("font");

    if (!al_install_keyboard()) error("keyboard");

    myDisplay = al_create_display(WIDTH, HEIGHT);
    if (!myDisplay) error("create display");
    al_set_window_title(myDisplay, "Blasteroids");

    myEventQueue = al_create_event_queue();
    if (!myEventQueue) error("create event queue");

    al_register_event_source(myEventQueue, al_get_display_event_source(myDisplay));
    al_register_event_source(myEventQueue, al_get_keyboard_event_source());

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
