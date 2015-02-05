/*
    A nave podera atirar em um asteroid com seu canhao, entao voce vai precisar
    de codigo para desenhar e mover um tiro de canhao pela tela.
*/
#include "blast.h"

void blast_anime (Blast *b)
{   
    b->sx += b->speed * sin(b->heading * M_PI/180);
    b->sy -= b->speed * cos(b->heading * M_PI/180);
}

void blast_draw (Blast **b)
{
    if (*b != NULL) {
        Blast *t = *b;
        while ( t != NULL) {
            blast_anime(t);
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
            if (t->sx < 0 || t->sy < 0 || t->sx > WIDTH || t->sy > HEIGHT) {
                
                Blast *aux = t;
                //*t = *aux->next;
                printf("contador = %f\n", aux->speed);
                //free(aux);
            } 
 
            t = t->next;
        }
    }
}

void blast_shoot (Blast **b, Spaceship *s)
{    
    Blast *t = blast_create(s);
    t->next = *b;
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
    return newBlast;
}
