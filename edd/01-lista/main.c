#include <stdio.h>
#include <stdlib.h>

typedef struct List {
    int info;
    struct List *next;
} List;

int main (void)
{
    List *L = NULL, *P;
    int op, x;
    do {
        printf("\n1- Insert into list");
        printf("\n2- Show list");
        printf("\n0- Exit\n> ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("choose a number ");
                scanf("%d", &x);
                P = malloc(sizeof(List));
                P->info = x;
                P->next = L;
                L = P;
            break;
            case 2: 
                P = L;
                while (P != NULL) {
                    printf(" |%d| ", P->info);
                    P = P->next;
                }
            break;
        }
    } while (op != 0);
    return 0;
}

