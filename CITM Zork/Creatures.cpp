#include "Creatures.h"

Creature::Creature(char* name, char* description, Room*location, type types) : Entity(name, description, types), location(location){

}

Creature::~Creature(){
}