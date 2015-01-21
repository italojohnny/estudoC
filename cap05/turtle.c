/*
    o atual codigo tem um problema, quando é passado a struct para a funcao,
    uma copia dela e criada. Os valores alterados nessa copia nao afetam a
    original.

    Para resolver esse problema é precisso usar ponteioros.
*/
#include <stdio.h>

typedef struct {
    const char *name;
    const char *species;
    int age;
} turtle;

void happy_birthday (turtle *t)
{
    t->age = t->age + 1;
    printf("Happy birthday %s! You are now %i years old!\n", t->name, t->age);
}

int main (void)
{
    turtle myrtle = {"Myrtle", "Leatherback sea turtle", 99};
    happy_birthday(&myrtle);
    printf("Happy birthday %s! You are now %i years old!\n", myrtle.name,
    myrtle.age);
    return 0;
}
