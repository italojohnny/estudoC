#include <stdio.h>

typedef struct {
    unsigned int first_visit:1;
    unsigned int come_again:1;
    unsigned int fingers_lost:4;
    unsigned int shark_attack:1;
    unsigned int days_a_week:3;
} sutvey;

int main (void)
{
    sutvey test;
    test.first_visit = 1;
    test.come_again = 1;
    test.fingers_lost = 10;
    test.shark_attack = 1;
    test.days_a_week = 7;
    return 0;
}
