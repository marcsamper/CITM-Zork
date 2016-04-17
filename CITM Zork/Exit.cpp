#include <stdio.h>
#include <stdlib.h>
#include "Exits.h"
#include "Entity.h"
#include "Vector.h"


Exit::Exit(const char* name, const char* description, bool open, Room* origin, Room* destination, dir direction) : Entity(name, description), open(open), origin(origin), destination(destination), direction(direction){
	
}
Exit::Exit(){
	origin = new Room;
	destination = new Room;
}
Exit::~Exit(){
	delete[] origin;
	delete[] destination;
	delete[] point;
}