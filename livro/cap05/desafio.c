#include <stdio.h>

typedef struct {
    const char *description;
    float value;
} swag;

typedef struct {
    swag *swag;
    const char *sequence;
} combination;

typedef struct {
    combination numbers;
    const char *make;
} safe;

int main (void)
{
    swag gold = {"GOLD!", 1000000.00};
    combination numbers = {&gold, "6502"};
    safe s = {numbers, "RAMACON250"};

    printf("primeiro nivel: %s\n", s.make);
    printf("segundo nivel: %s\n", s.numbers.sequence);
    printf("terceiro nivel: %s\n", s.numbers.swag->description);
    printf("Esta aqui o dinheiro: %f\n", s.numbers.swag->value);
}
