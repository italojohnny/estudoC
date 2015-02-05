#include "list.h"

int main (void)
{
    List *L = NULL, *L2 = NULL;
    int op, x;
    do {
        show(L);
        printf("\n1 - Insert");
        printf("\n2 - Insert(mode2)");
        printf("\n3 - Insert last");
        printf("\n4 - Insert order");
        printf("\n5 - Remove");
        printf("\n6 - Remove (mode2)");
        printf("\n7 - Remove all");
        printf("\n8 - Concatenate");
        printf("\n9 - Show");
        printf("\n10- Show last");
        printf("\n11- Show (recursive)");
        printf("\n0- Exit\n> ");
        scanf("%d", &op);

        switch (op) {
            case 0: break;
            case 1: printf("\nchoose a number: ");
                    scanf("%d", &x);
                    insert(&L, x);                        
            break;
            case 2: printf("\nchoose a number: ");
                    scanf("%d", &x);
                    L = insert2(L, x);
            break;
            case 3: printf("\nchoose a number: ");
                    scanf("%d", &x);
                    L = insert_last(L, x);                    
            break;
            case 4: printf("\nchoose a number: ");
                    scanf("%d", &x);
                    insert_order(&L, x);
            break;
            case 5: L = _remove(L);
            break;
            case 6: printf("\n%d removed", _remove2(&L));
            break;
            case 7: printf("\nchoose a number");
                    scanf("%d", &x);
                    _remove_all(&L, x);
            break;
            case 8: concatena(&L, L2);
            break;
            case 9: show(L);
            break;
            case 10: printf("%d is the last", show_last(L));
            break;
            case 11:printf("\n");
                    show_rec(L);
            break;
            default:insert_order(&L2, 12);
                    insert_order(&L2, 23);
                    insert_order(&L2, 666);
                    insert_order(&L2, 1);
                    insert_order(&L2, 16);
                    show_rec(L2);                
        }
    } while (op != 0);
    return 0;
}

