#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"World.h"


int main(){

	bool start = true;//To make a Loop to check all the time the inputs
	World world;
	world.CreateWorld();
	printf("Welcome to the CIMT's Zork, an adventure of a boy that has to find where is the thug boy who has stolen him an important homework\n");
	printf("%s\n%s\nWhat do you want to do?\n", world.roomer[0]->name, world.roomer[0]->description);
	//Loop to chek inputs:
	while (start == true){
		start = world.Inpunts();
	}

	return 0;

}