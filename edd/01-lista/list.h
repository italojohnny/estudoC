#include <stdio.h>
#include <stdlib.h>

typedef struct List {
    int info;
    struct List *next;
} List;

void insert (List **L, int x)
{
    List *P = malloc(sizeof(List));
    P->info = x;
    P->next = *L;
    *L = P;
}

List* insert2 (List *L, int x)
{
    List *P = malloc(sizeof(List));
    P->info = x;
    P->next = L;
    return P;
}

List* insert_last (List *L, int x)
{
    List *Q, *P = malloc(sizeof(List));
    P->info = x;
    P->next = NULL;
    if (L == NULL)
        return P;
    else {
        Q = L;
        while (Q->next != NULL)
            Q = Q->next;
        Q->next = P;
        return L;
    }
}

void insert_order (List **L, int x)
{
    List *percorre = *L, *aux = NULL, *P = malloc(sizeof(List));
    P->info = x;
    while (percorre != NULL && x > percorre->info) {
        aux = percorre;
        percorre = percorre->next;
    }
    if (aux == NULL) {
        P->next = *L;
        *L = P;
    } else {
        P->next = aux->next;
        aux->next = P;
    }
}

List* _remove (List *L)
{
    if (L == NULL) return NULL;
    
    List *aux = L;
    printf("\n %d removed", aux->info);
    L = aux->next;
    free(aux);
    return L;
}

int _remove2 (List **L)
{
    if (*L == NULL) return 0;

    int x;
    List *aux = *L;
    x = aux->info;
    *L = aux->next;
    free(aux);
    return x;
}

void _remove_all (List **L, int x)
{
    List *percorre, *aux, *P;
    percorre = *L;
    aux = NULL;
    while (percorre != NULL) {
        if (percorre->info == x) {
            if (aux == NULL) {
                P = *L;
                *L = P->next;
                free(P);
                percorre = *L;
            } else {
                percorre = percorre->next;
                P = aux->next;
                aux->next = P->next;
                free(P);
            }
        } else {
            aux = percorre;
            percorre = percorre->next;
        }
    }
}

void concatena (List **L, List *L2)
{
    List *P = *L;
    while (P->next != NULL)
        P = P->next;
    P->next = L2;
}

void show (List *L)
{
    List *P = L;
    while (P != NULL) {
        printf("(%d|%p)->", P->info, &P->next);
        P = P->next;
    }    
}

int show_last (List *L)
{
    List *Q = L;
    while (Q->next != NULL)
        Q = Q->next;
    return Q->info;
}

void show_rec (List *L)
{
    if (L != NULL) {
        show_rec(L->next);
        printf(" |%d| ", L->info);
    }
}
