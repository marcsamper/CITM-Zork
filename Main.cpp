#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include"World.h"


int main(){

	printf("Welcome to the CIMT's Zork, an adventure of a boy that has to find where is the thug boy who has stolen him an important homework\n");
	printf("You will have to move you character by writting NORTH EAST SOUTH WEST or 'n' 'e' 's' 'w'\nTo quit the game press 'q'.\nLETS START!");
	Player player;
	Exit exit[15];
	World();
	Player();

	getchar();
	return 0;

		}