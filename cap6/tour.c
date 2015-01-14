/*
    warning: assignment from incompatible pointer type [enabled by default]
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    const char *name;
    const char *opens;
    const char *closes;
    struct island *next;
} island;

void display (island*);
island* create (char*);

int main (void)
{
    island amity = {"Amity", "09:00", "17:00", NULL};
    island craggy = {"Craggy", "09:00", "17:00", NULL};
    island isla_nublar = {"Isla Nubla", "09:00", "17:00", NULL};
    island shutter = {"Shutter", "09:00", "17:00", NULL};
    
    amity.next = &craggy;
    craggy.next = &isla_nublar;
    isla_nublar.next = &shutter;

    island skull = {"Skull", "09:00", "17:00", NULL};

    isla_nublar.next = &skull;
    skull.next = & shutter;

    display(&amity);
    return 0;
}

void display (island *start)
{
    island *i = start;
    for (; i != NULL; i = i->next) {
        printf("Name: %s\nOpen: %s-%s\n", i->name, i->opens, i->closes);
    }
}

island* create (char *name)
{
    island *i = malloc(sizeof(island));
    i->name = name;
    i->opens = "09:00";
    i->closes ="17:00";
    i->next = NULL;
    return i;
}
