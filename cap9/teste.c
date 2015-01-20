#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main (int argc, char *argv[])
{
/*
    char *my_env[] = {"FOOD=coffe", NULL};
    if (execle("./coffe", "./coffe", "donuts", NULL, my_env) == -1) {
        fprintf(stderr, "Can't run process 0: %s\n", strerror(errno));
        return 1;
    }

    char *my_env[] = {"FOOD=donuts", NULL};
    if (execle("./coffe", "./coffe", "cream", NULL, my_env) == -1) {
        fprintf(stderr, "Can't run processo 0: %s\n", strerror(errno));
        return 1;
    }

    if (execl("./coffe", "./coffe", NULL) == -1) {
        fprintf(stderr, "Can't run process 0: %s\n", strerror(errno));
        return 1;
    }
*/
    char *my_env[] = {"FOOD=donuts", NULL};
    if (execle("./coffe", "./coffe", NULL, my_env) == -1) {
        fprintf(stderr, "Can't run process 0: %s\n", strerror(errno));
        return 1;
    }

    return 0;
}
