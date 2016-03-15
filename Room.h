#ifndef _ROOM_H
#define _ROOM_H

#include "World.h"
#include "Exits.h"
#include"Player.h"

class Room{
public:
	char name[20];
	char description[250];

public:
	Room();
	~Room();


};
#endif;