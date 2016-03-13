#include <stdio.h>
#include <stdlib.h>
#include "function.h"


int main(){

	printf("Welcome to the CIMT's Zork, an adventure of a boy that has to find where is the thug boy who has stolen him an important homework\n");
	printf("You will have to move you character by writting NORTH EAST SOUTH WEST or 'n' 'e' 's' 'w'\nTo quit the game press 'q'.\nLETS START!");
	bool exit = false;
	char order;

	/*while (exit = false)
	{
		printf("What do you want to do");
		scanf_s("%c", &order);
		switch (order)
			{
			case 'q':
				printf("The game will close\n");
				exit = true;
				break;

			case 'n':



		}

	}
	*/

	World();
	Player();

	getchar();
	return 0;

}