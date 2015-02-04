#include <stdio.h>
#include <stdlib.h>

#define MAX_X 80
#define MAX_Y 24

void gotoxy(int, int, char);
void clear (void);

int main (void)
{   int x, y;
    clear();
    gotoxy(80, 1, 't');
    return 0;
}

void clear (void)
{
#ifndef DOS
    system("clear");
#endif
#ifdef DOS
    system("cls");
#endif
}

void gotoxy(int x, int y, char c)
{
    printf("\033[%d;%dH", y, x);
    printf("%c", c);
}
//"\033[2J"
//\_0_33[%d;%dH]
