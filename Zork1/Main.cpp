#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include"World.h"


int main(){

	

	bool start = true;
	World *world = new World;
	world->CreateWorld();
	printf("Welcome to the CIMT's Zork, an adventure of a boy that has to find where is the thug boy who has stolen him an important homework\n");
	printf("%s\n%s\nWhat do you want to do?", world->player->position->name, world->player->position->description);
	while (start == true){
		
		start=world->Inpunts();
	}


	
	

	
	
	return 0;

		}