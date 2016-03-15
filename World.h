

#ifndef _WORLD_H
#define _WORLD_H
#include "Room.h"
#include "Exits.h"
#include"Player.h"
class World
{
public:
	Room *room = nullptr;
	Player *player = nullptr;
	Exit *exit = nullptr;

public:
	World();
	~World();
	void CreateWorld();
	



};
#endif