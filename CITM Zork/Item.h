#ifndef Item_H
#define Item_H
#include "Room.h"
#include "String.h"
#include "Entity.h"



class Item: public Entity{

public:
	Room* localitzation;
	//Entity* item = nullptr;
public:
	Item(const char*, const char*, Room*);
	~Item();
};
#endif
	