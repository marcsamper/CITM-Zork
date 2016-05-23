#include "Entity.h"
#include "Item.h"
#include "Room.h"
#include "Npc.h"

Item::Item(const char* name, const char*description, Room* localitzation) : Entity(name, description, ITEM),localitzation(localitzation) {

	
}
Item::Item(const char* name, const char*description, Npc* localitzation) : Entity(name, description, ITEM), mine(localitzation) {


}


Item::~Item(){
	
}
	