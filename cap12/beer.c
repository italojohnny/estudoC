#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <unistd.h>
#include <errno.h>
#include <pthread.h>

int beers = 2000000;

pthread_mutex_t beers_lock = PTHREAD_MUTEX_INITIALIZER;
/*
Versio A
void* drink_lots(void *a)
{
    int i;
    pthread_mutex_lock(&beers_lock);
    for (i = 0; i < 1000000; i++) {
        beers = beers - 1;
    }
    pthread_mutex_unlock(&beers_lock);
    printf("beers = %i\n", beers);
    return NULL;
}
*/
//versio B
void* drink_lots(void *a)
{
    int i;
    for (i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&beers_lock);
        beers = beers - 1;
        pthread_mutex_unlock(&beers_lock);
    }
     
    printf("beers = %i\n", beers);

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
