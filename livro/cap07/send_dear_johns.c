/*
    Array de ponteiros para funçoes
*/
#include "send.h"

void (*replies[])(response) = {dump, second_chance, marriage};

int main (void)
{
    response r[] = {
        {"Mike", DUMP},
        {"Luis", SECOND_CHANCE},
        {"Matt", SECOND_CHANCE},
        {"William", MARRIAGE}
    };
    int i;
    for (i = 0; i < 4; i++) {
        (replies[r[i].type])(r[i]);
    }
    return 0;
}

