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
		//printf("%d", b->id);
        //se entrou aqui, tem que ser eliminado.
        //mas existe a problematica, se ele tiver descendentes, havera
        //vazamento de memoria
        //Acredito que a resposta para o problema seja a criação de filas ao
        //inves de listas
        }
}


void blast_draw (Blast **b)
{
    if (*b != NULL) {
        Blast *t = *b;

        while (t != NULL) {
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
            //if (t != NULL)
                t = t->next; 
        }

		Blast *u = *b;
		Blast *aux_prev = NULL,  *aux_next = NULL;

		while ( u != NULL) {
			aux_next = NULL;
			if (u->gone == 1) {//encontrou um No para excluir

				if (u ->next != NULL) {//ele tem proximo? Se sim, entrar No if
					aux_next = u->next;//entao, amarzena o endereco do proximo.

					if (aux_prev != NULL){ //esse No tem algum No anterior?
						aux_prev->next = aux_next;//entao, liga o anterio com o proximo. Agora o No esta pronto para exclusao
						free(u);
						break;

					} else {//esse No nao tem nenhum anterior a ele! 
						*b = aux_next;
						free(u);
						break;
					}
				
				} else {//ele não tem proximo!
					if (aux_prev == NULL) {//se ele nao tiver anterior
						free(u);//libera memoria
						*b = NULL;//limpa origem
						break;
					}

				}
			}
			aux_prev = u;
			u = u->next;
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
    newBlast->id        = ++tmp;
    return newBlast;
}
