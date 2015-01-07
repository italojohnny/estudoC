/*
 * Program to evaluate face values.
 * Released under the Vegas Public License.
 * (c)2014 The College Blackjack Team.
 */

#include <stdio.h>
#include <stdlib.h>

int main (void) 
{
	char card_name[3];
	
	puts("Enter the card_name: ");
	scanf("%2s", card_name);
	
	int val = 0;
	
	switch (card_name[0]) {
		case 'K':
		case 'Q':
		case 'J':
			val = 10;
		break;
		case 'A':
			val = 11;
		break;
		default:
			val = atoi(card_name);
	}

	//Check is the value is 3 to 6
	if (val >=3 && val <= 6)
		puts("Count has gone up");
	else if (val == 10)
		puts("Count has gone down");

	//printf("The card value is: %i\n", val);

	return 0;
}