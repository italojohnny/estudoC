/*
 *	windows
 *	gcc main.c -o main −lncursesw
 *
 *	linux
 *	gcc main.c -o main −lcurses
 *
*/
#include <stdio.h>
/*#include <ncursesw/ncurses.h>*//*Windows*/
#include <ncurses.h>/*Linux*/

int main (void)
{
	initscr(); 					/* Start curses mode */
	printw("Hello World !!!"); 	/* Print Hello World */
	refresh();					/* Print it on to the real screen */
	getch(); 					/* Wait for user input */
	endwin(); 					/* End curses mode */
	return 0;
}
