#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct island {
    char *name;
    char *opens;
    char *closes;
    struct island *next;
} island;

void release (island *start);
island* create (char *name);
void display (island *start);

int main (void)
{
/*  ----------PRIMEIRA ETAPA----------
    island amity = {"Amity", "09:00", "17:00", NULL};
    island craggy = {"Craggy", "09:00", "17:00", NULL};
    island isla_nubla = {"Isla Nubla", "09:00", "17:00", NULL};
    island shutter = {"Shutter", "09:00", "17:00", NULL};
    
    amity.next = &craggy;
    craggy.next = &isla_nubla;
    isla_nubla.next = &shutter;

    display(&amity);
*/
/*  ----------SEGUNDA ETAPA-----------
    char name[80];
    fgets(name, 80, stdin);
    island *p0 = create(name);

    fgets(name, 80, stdin);
    island *p1 = create(name);
    p0->next = p1;

    display(p0);
*/
    island *start = NULL;
    island *i = NULL;
    island *next = NULL;

    char name[80];
    for(; fgets(name, 80, stdin) != NULL; i = next) {
        next = create(name);
        if (start == NULL)//e a primeira vez?
            start = next;
        if (i != NULL)//este e o ultimo da lista?
            i->next = next;
    }
    display(start);

    return 0;
}

island* create (char *name)
{
    island *i = malloc(sizeof(island));
    i->name = strdup(name);
    i->opens = "09:00";
    i->closes = "17:00";
    i->next = NULL;

    return i;
}

void display (island *start)
{
    island *i = start;
    for(; i != NULL; i= i->next) {
        printf("Name: %s open: %s-%s\n",i->name, i->opens, i->closes);
    }
}
