#ifndef ENTITY_H
#define ENTITY_H

#include "String.h"
#include "Vector.h"




class Entity{
public:

	String name;
	String description;
	bool open;
	bool in;
		

public:
	Entity(const char* name, const char* description);

	Entity();
	~Entity();


};

#endif