#ifndef _PLAYER_H
#define _PLAYER_H
#include "Room.h"
#include "World.h"

class Player{
public:
	char name[30];
	Room *position;

public:
	
	Player();
	~Player();
	
};
#endif