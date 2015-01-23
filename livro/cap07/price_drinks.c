#include <stdio.h>
#include <stdarg.h>

enum drink {
    MUDLIDE,
    FUZZY_NAVEL,
    MONKEY_GLAND,
    ZOMBIE
};

double price (enum drink);
double total (int, ...);

int main (void)
{
    printf("Price is %2.2f\n", total(2, MONKEY_GLAND, MUDLIDE));
    printf("Price is %2.2f\n", total(3, MONKEY_GLAND, MUDLIDE, FUZZY_NAVEL));
    printf("Price is %2.2f\n", total(1, ZOMBIE));
    return 0;
}

double price (enum drink d)
{
    switch (d) {
        case MUDLIDE:       return 6.79;
        case FUZZY_NAVEL:   return 5.31;
        case MONKEY_GLAND:  return 4.82;
        case ZOMBIE:        return 5.89;
    }
    return 0;
}

double total (int args, ...)
{
    double total = 0.0;

    va_list ap;
    va_start(ap, args);
    int i;
    for (i = 0; i < args; i++) {
        enum drink d = va_arg(ap, enum drink);
        total += price(d);
    }
    va_end(ap);
    return total;
}
