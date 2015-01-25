/*
    E sempre bom ter um arquivo fonte separado para lidar com o nucleo do jogo.
    O codigo aqui precisara ficar atento a teclas pressionadas, executar um
    temporizador e, tambem dizer para todas as outras naves, asteroides e tiros
    como se mover pela tela.
*/

#include <stdio.h>
#include <allegro5/allegro.h>
#include <string.h>
#include <errno.h>

#include "spaceship.h"
#include "blast.h"
#include "asteroid.h"

void error (char *msg);

int main (void)
{
    test_asteroid();
    test_blast();
    test_spaceship();

    error ("test!!!");
    return 0;
}

void errro (char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}
