#ifndef _ROOM_H
#define _ROOM_H

#include "World.h"
#include "Exits.h"
#include"Player.h"

class Room{
public:
	char name[30];
	char description[500];

public:
	Room();
	~Room();


};
#endif;