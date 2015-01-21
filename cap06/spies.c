/*
    valgrind --leak-check=full ./spies
    ==17206== Memcheck, a memory error detector
    ==17206== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
    ==17206== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
    ==17206== Command: ./spies
    ==17206== 
    Does suspect have a mustache? (y/n): n
    Loretta Barnsworth? (y/n): n
    Who's the suspect? Hayden Fantucci
    Give me a question that is TRUE for Hayden Fantucci
    but not for Loretta Barnsworth?: Has a facial scar
    Run again? (y/n): n
    ==17206== 
    ==17206== HEAP SUMMARY:
    ==17206==     in use at exit: 19 bytes in 1 blocks
    ==17206==   total heap usage: 11 allocs, 10 frees, 239 bytes allocated
    ==17206== 
    ==17206== 19 bytes in 1 blocks are definitely lost in loss record 1 of 1
    ==17206==    at 0x4C28BED: malloc (vg_replace_malloc.c:263)
    ==17206==    by 0x4EAF8E1: strdup (strdup.c:43)
    ==17206==    by 0x400739: create (spies.h:26)
    ==17206==    by 0x4007FA: main (spies.c:8)
    ==17206== 
    ==17206== LEAK SUMMARY:
    ==17206==    definitely lost: 19 bytes in 1 blocks
    ==17206==    indirectly lost: 0 bytes in 0 blocks
    ==17206==      possibly lost: 0 bytes in 0 blocks
    ==17206==    still reachable: 0 bytes in 0 blocks
    ==17206==         suppressed: 0 bytes in 0 blocks
    ==17206== 
    ==17206== For counts of detected and suppressed errors, rerun with: -v
    ==17206== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 4 from 4)

*/
#include "spies.h"

int main (void)
{
    char question[80];//vazamento aqui
    char suspect[20];
    node *start_node = create("Does suspect have a mustache");
    start_node->no = create("Loretta Barnsworth");
    start_node->yes = create("Vinny the Spoon");

    node *current;
    do {
        current = start_node;
        while (1) {
            if (yes_no(current->question)) {
                if (current->yes) {
                    current = current->yes;
                } else {
                    printf("SUSPECT IDENTIFIED\n");
                    break;
                }
            } else if (current->no) {
                current = current->no;        
            } else {

                /* Make the yes-node the new suspect name */
                printf("Who's the suspect? ");
                fgets(suspect, 80, stdin);
                node *yes_node = create(suspect);
                current->yes = yes_node;

                /* Make the no-node a copy of this question */
                node *no_node = create(current->question);
                current->no = no_node;

                /* Then replace this question with the new question */
                printf(" Give me a question that is TRUE for %s but not for %s?: ",
                suspect, current->question);
                fgets(question, 80, stdin);
                free(current->question);
                current->question = strdup(question);//vazamento aqui

                break;
            }
        }
    } while (yes_no("Run again"));
    release(start_node);
    
    return 0;
}
