#include <stdio.h>

typedef union {
    float lemon;
    int lime_pices;
} lemon_lime;

typedef struct {
    float tequila;
    float cointreaus;
    lemon_lime citrus;
} margarita;

void receita1 (margarita m)
{
    printf("%2.1f measures of tequila\n%2.1f measures of cointreau\n%2.1f measures of juice\n", m.tequila, m.cointreaus, m.citrus.lemon);
}

void receita2 (margarita m)
{
    printf("%2.1f measures of tequila\n%2.1f measures of cointreau\n%i pieces of lime\n", m.tequila, m.cointreaus, m.citrus.lime_pices);
}

int main (void)
{
    margarita a = {2.0, 1.0, {0.5}};
    margarita b = {2.0, 1.0, .citrus.lemon=2};
    margarita c = {2.0, 1.0, 0.5};
    margarita d = {2.0, 1.0, {.lime_pices=1}};
    margarita e = {2.0, 1.0, {1}};
    margarita f = {2.0, 1.0, {2}};

    receita1(b);
    receita1(f);
    receita1(a);
    receita1(c);
    receita2(d);
    receita2(e);
    return 0;
}
