#include "Entity.h"
#include "Room.h"
#ifndef CREATURES_H
#define CREATURES_H





class Creature: public Entity{

public:
	Room* location = nullptr;

public:

	Creature(char* name, char* description, Room* location, type types);
	~Creature();



};

#endif