#include "spies.h"

int main (void)
{
    char question[80];
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
                current->question = strdup(question);

                break;
            }
        }
    } while (yes_no("Run again"));
    release(start_node);
    
    return 0;
}
