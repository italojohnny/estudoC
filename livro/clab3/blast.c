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

void blast_draw (Blast *b)
{
    if (b != NULL) {      
        Blast *t = b;
        while ( t != NULL) {
            blast_anime(t);
            ALLEGRO_TRANSFORM transform;
            al_identity_transform(&transform);
            al_rotate_transform(&transform, t->heading * M_PI/180);
            al_translate_transform(&transform, t->sx, t->sy);
            al_use_transform(&transform);

            al_draw_line(0, 6, 0, 3, t->color, 1.0f);
            al_draw_line(0, 1, 0,-1, t->color, 1.0f);
            al_draw_line(0,-6, 0,-3, t->color, 1.0f);

            al_identity_transform(&transform);
            al_use_transform(&transform);

            t = t->next;
        }
    }
}

void blast_shoot (Blast **b, Spaceship *s)
{   puts("entrou aqui?"); 
    Blast *t = blast_create(s);
    t->next = *b;
    *b = t;
    //printf("p=%f,%f; heading=%f; speed=%f; gone=%d;\n", b->sx, b->sy, b->heading, b->speed, b->gone);
}

Blast *blast_create (Spaceship *s)
{
    Blast *newBlast     = malloc(sizeof(Blast));
    newBlast->sx        = s->sx;
    newBlast->sy        = s->sy;
    newBlast->heading   = s->heading;
    newBlast->speed     = s->speed;
    newBlast->color     = s->color;
    newBlast->gone      = 0;
    newBlast->next      = NULL;
    return newBlast;
}
