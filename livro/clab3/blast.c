/*
    A nave podera atirar em um asteroid com seu canhao, entao voce vai precisar
    de codigo para desenhar e mover um tiro de canhao pela tela.
*/
#include "blast.h"

void blast_anime (Blast *b)
{
    if (!b->gone) {//verifica se tiro pode ser animado
        b->sx += b->speed * sin(b->heading * M_PI/180);
        b->sy -= b->speed * cos(b->heading * M_PI/180);
        
        if (b->sx < 0 || b->sy < 0 || b->sx > WIDTH || b->sy > HEIGHT)//verifica se tiro utrapassou limites
            b->gone = 1;//o tiro nao pode ser mais animado

    } else {//se o tiro nao pode ser mais animado, ele deve ser destruido
        //se entrou aqui, tem que ser eliminado a qualquer preco!!!
        //mas existe a problematica, se ele tiver descendentes, havera
        //vazamento de memoria 

    }
}

void blast_draw (Blast **b)
{
    if (*b != NULL) {
        Blast *t = *b;

        while ( t != NULL) {
            ALLEGRO_TRANSFORM transform;
            al_identity_transform(&transform);
            al_rotate_transform(&transform, t->heading * M_PI/180);
            al_translate_transform(&transform, t->sx, t->sy);
            al_use_transform(&transform);

            //al_draw_line(0, 6, 0, 3, t->color, 1.0f);
            al_draw_line(0, 1, 0,-1, t->color, 1.0f);
            //al_draw_line(0,-6, 0,-3, t->color, 1.0f);

            al_identity_transform(&transform);
            al_use_transform(&transform);
            
            blast_anime(t);
            if (t != NULL)
                t = t->next; 
        }
    }
}

void blast_shoot (Blast **b, Spaceship *s)
{    
    Blast *t = blast_create(s);
    t->next = *b;
    //printf("id = %d\n", t->id);
    *b = t;
}

Blast *blast_create (Spaceship *s)
{
    Blast *newBlast     = malloc(sizeof(Blast));
    newBlast->sx        = s->sx;
    newBlast->sy        = s->sy;
    newBlast->heading   = s->heading;
    newBlast->speed     = s->speed * 3;
    newBlast->color     = s->color;
    newBlast->gone      = 0;
    newBlast->next      = NULL;
    tmp++;
    newBlast->id        = tmp;
    return newBlast;
}
