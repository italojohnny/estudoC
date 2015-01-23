#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>

void* do_stuff (void* param)//uma funcao thread pode aceitar um unico ponteiro void como parametros
{
    long thread_no = (long)param;//converta-o de volta para long
    printf("Thread number %ld\n", thread_no);
    return (void*)(thread_no + 1);//use cast para o converter para um ponteiro void quando ele for retornado
}

int main (void)
{
    pthread_t threads[20];
    long t;
    for (t = 0; t < 3; t ++) {
        pthread_create(&threads[t], NULL, do_stuff, (void*)t);//Converta o valor long t para um ponteiro void
    }

    void* result;
    for (t = 0; t < 3; t++) {
        pthread_join(threads[t], &result);
        printf("Thread %ld returned %ld\n", t, (long)result);//converta o valor de retorno para um void antes de usa-lo
    }
    return 0;
}
