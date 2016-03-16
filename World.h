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
	void CreateWorld()const;
	bool Inpunts();
	World();//builder
	~World();//destroyer



};
#endif