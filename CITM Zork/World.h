#ifndef _WORLD_H
#define _WORLD_H
#include "Room.h"
#include "Exits.h"
#include"Player.h"
#include "Entity.h"
#include "String.h"
#include "Vector.h"
class World: public Entity{
public:

	Vector<Room*> roomer;
	Vector<Exit*> exit;

	
	//Entity *room = nullptr;
	Player *player = nullptr;

	Entity*inventory = nullptr;
	String* pointer=nullptr;
	

public:
	void CreateWorld();
	bool Inpunts();
	World();//builder
	~World();//destroyer



};
#endif