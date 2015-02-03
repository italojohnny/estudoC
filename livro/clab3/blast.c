    /*
    A nave podera atirar em um asteroid com seu canhao, entao voce vai precisar
    de codigo para desenhar e mover um tiro de canhao pela tela.
*/
#include "blast.h"
void blast_destroy ()
{
    //recebe ponteiro do tiro que saiu da tela
    //percorre lista ate encontrar tiro
    //verifica se e o ultimo tiro da lista
        //libera memoria do tiro
    //se nao for o ultimo tiro da lista, nao faz nada
}

void blast_create()
{
    //recebe ponteiro do tiro de origem
    //percorre até o final da lista
    //alloca memória para novo tiro
    //define heading do tiro baseado na heading atual da nave
}
/*
void blast_anime (Blast *b)
{
    b->speed = 1.5;
    //receve ponteiro do tiro de origem
    //percorre lista
        //verifica se tiro já saiu do campo de visao
            //destroi tiro
        //desenha tiro
    b->sx += b->speed * sin(b->heading * M_PI/180);
    b->sy -= b->speed * cos(b->heading * M_PI/180);
}
*/
void blast_draw (Blast *b)
{
    //recebe o ponteiro do tiro de origem
    //percorre lista
    //blast_anime (b);
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_rotate_transform(&transform, b->heading * M_PI/180);
    al_translate_transform(&transform, b->sx, b->sy);
    al_use_transform(&transform);
    
    al_draw_line(0,-6, 0, -3, b->color, 1);
    al_draw_line(0, 1, 0, -1, b->color, 1);
    al_draw_line(0, 3, 0,  6, b->color, 1);

    al_identity_transform(&transform);
    al_use_transform(&transform);
}
