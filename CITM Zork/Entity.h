#ifndef ENTITY_H
#define ENTITY_H

#include "String.h"
#include "Vector.h"


enum type{EXIT, ITEM, PLAYER, ROOM, NPC};

class Entity{
public:

	Vector<Entity*> vector;
	String name;
	String description;
	bool open;
	bool in;
	type types;
		

public:
	Entity(const char* name, const char* description, type types);

	Entity();
	~Entity();


};

#endif