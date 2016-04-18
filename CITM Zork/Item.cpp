#include "Entity.h"
#include "Item.h"
#include "Room.h"

Item::Item(const char* name, const char*description, Room* localitzation) : Entity(name, description),localitzation(localitzation) {

	
}


Item::~Item(){
	
}
	