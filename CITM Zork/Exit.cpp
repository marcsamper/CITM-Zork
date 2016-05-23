#include <stdio.h>
#include <stdlib.h>
#include "Exits.h"
#include "Entity.h"
#include "Vector.h"


Exit::Exit(const char* name, const char* description, bool open, Room* origin, Room* destination, dir direction) : Entity(name, description, EXIT), open(open), origin(origin), destination(destination), direction(direction){
	
}
Exit::Exit(){
	
}
Exit::~Exit(){
	
}