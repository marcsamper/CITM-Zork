#ifndef _PLAYER_H
#define _PLAYER_H
#include "Room.h"
#include "Exits.h"
#include "Entity.h"
#include "Npc.h"


class Player: public Entity{
public:
	
	Room *position=nullptr;
	Vector<Npc*> npc;
	Vector<Entity*> trans;
	int life= 100;//stats
	int attack=40;//stats
	

public:

	bool enter = true;
	void Inventory();
	
	
	Player();//builder
	~Player();//destroyer

};
#endif