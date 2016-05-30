#ifndef ENTITY_H
#define ENTITY_H

#include "String.h"
#include "Vector.h"






enum type{EXIT, ITEM, PLAYER, ROOM, NPC};


class Entity{
public:

	Vector<Entity*> drive;
	String name;
	String description;
	bool open;
	bool in;
	type types;

	
	
		

public:
	Entity(const char* name, const char* description, type types);
	//Entity(const char* name, const char* description, type types,bool open, Room* origin, Room* destination, dir direction);

	Entity();
	~Entity();


};

#endif