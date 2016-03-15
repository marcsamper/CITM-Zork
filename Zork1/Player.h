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
	Player();
	~Player();
	
};
#endif