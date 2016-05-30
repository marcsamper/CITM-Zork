#include <stdio.h>
#include <stdlib.h>
#include "Room.h"
#include "Entity.h"


Room::Room(const char* name, const char* description) :  Entity(name, description, ROOM){


}
Room::Room(){}
Room::~Room(){
	
}
