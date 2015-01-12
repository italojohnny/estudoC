#include <stdio.h>
#include "launch.h"
#include "thruster.h"

void func1 (void) {printf("funcao 1\n");}
void func2 (void) {printf("funcao 2\n");}

int main (void)
{
    func1();
    func2();
    func3();
    func4();
    func5();

    return 0;
}
