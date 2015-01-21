#include <stdio.h>

#include <unistd.h>
#include <errno.h>
#include <string.h>

int main (void)
{
    char *my_env[] = {"JUICE=peach and apple", NULL};
    
    if (execle("diner_info", "diner_info", "4", NULL, my_env) == -1) {
        fprintf(stderr,"Erro: %s\n", strerror(errno));
    }

    return 0;
}
