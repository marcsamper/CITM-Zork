#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"World.h"


int main(){

	bool start = true;//To make a Loop to check all the time the inputs
	World* world=new World;
	world->CreateWorld();
	printf("Welcome to the CIMT's Zork, an adventure of a boy that has to find where is the thug boy who has stolen him an important homework\n\n");
	printf("\t\t\t\t%s\n%s\n\n", world->entity[0]->name.c_str(), world->entity[0]->description.c_str());
	

	//Loop to chek inputs:
	while (start == true){
		
		start = world->Inpunts();
		
		

	}

	return 0;

}