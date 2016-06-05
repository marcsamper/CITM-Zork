#ifndef Item_H
#define Item_H
#include "Room.h"
#include "String.h"
#include "Entity.h"
#include "Npc.h"



class Item: public Entity{

public:
	Room* localitzation=nullptr;
	Npc* mine= nullptr;
	Vector<Entity*> transp;
public:
	Item(const char*, const char*, Room*);
	Item(const char*, const char*, Npc*);

	~Item();
};
#endif
	