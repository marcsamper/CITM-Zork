#include "Entity.h"
#include "Item.h"
#include "Room.h"

Item::Item(const char* name, const char*description, bool in){

	item->name = name;
	item->description = description;
	item->in = in;
}

Item::Item(){
	item = new Entity;
}
Item::~Item(){
	delete[] item;
}
