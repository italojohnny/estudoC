/*
    warning: assignment from incompatible pointer type [enabled by default]
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char name[80];
    fgets(name, 80, stdin);
    island *p0 = create(name);

    fgets(name, 80, stdin);
    island *p1 = create(name);
    p0->next = p1;
    display(p0);

    return 0;
}

void display (island *start)
{
    island *i = start;
    for (; i != NULL; i = i->next) {
        printf("Name: %sOpen: %s-%s\n", i->name, i->opens, i->closes);
    }
}

island* create (char *name)
{
    island *i = malloc(sizeof(island));
    i->name = strdup(name);
    i->opens = "09:00";
    i->closes ="17:00";
    i->next = NULL;
    return i;
}
