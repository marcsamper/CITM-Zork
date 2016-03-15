#ifndef _PLAYER_H
#define _PLAYER_H
#include "Room.h"
class World;

class Player{
public:
	char name[30];
	Room *position;

public:
	bool enter=true;
	void MovePosition(World *movement, dir direction);
	void Look(World*look, dir watch);
	void LookRoom()const;
	void OpenDoor(World* open, dir door);
	void CloseDoor(World* open, dir door);
	Player();
	~Player();
	
};
#endif