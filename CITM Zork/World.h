#ifndef _WORLD_H
#define _WORLD_H
#include "Room.h"
#include "Exits.h"
#include"Player.h"
#include "Entity.h"
#include "String.h"
class World: public Entity
{
public:
	Entity *room = nullptr;
	Player *player = nullptr;
	Exit *exit = nullptr;
	Entity*inventory = nullptr;
	String* pointer=nullptr;
	

public:
	void CreateWorld()const;
	bool Inpunts();
	World();//builder
	~World();//destroyer



};
#endif