#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

int beers = 2000000;

void* drink_lots(void *a)
{
    int i;
    for (i = 0; i < 1000000; i++) {
        beers = beers - 1;
    }
    return NULL;
}

int main (void)
{
    pthread_t threads[20];
    printf("%i bottles of beer on the wall\n%i bottles of beer\n", beers, beers);
    
    int t;
    for (t = 0; t < 20; t++) {
        pthread_create(&threads[t], NULL, drink_lots, NULL);
    }

    void* result;
    for (t = 0; t < 20; t++) {
        pthread_join(threads[t], &result);
    }

    printf("Theres are now %i bottles of beer on the wall\n", beers);
    return 0;
}
