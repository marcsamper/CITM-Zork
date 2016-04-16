#ifndef _ROOM_H
#define _ROOM_H
#include <stdio.h>
#include "Entity.h"
#include "String.h"
#include "Vector.h"
#include "Item.h"

class Entity;

class Room:public Entity{
public:
	Entity* point=nullptr;
	Vector<Item*> item;
	

public:
	Room( const char* name, const char* description);
	Room();
	~Room();


};
#endif;