#include "Entity.h"
#include "Item.h"
#include "Room.h"

Item::Item(const char* name, const char*description, bool in) : Entity(name, description, in){

	
}

Item::Item(){
	item = new Entity;
}
Item::~Item(){
	delete[] item;
}
