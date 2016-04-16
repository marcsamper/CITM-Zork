#ifndef _EXIT_H
#define _EXIT_H
#include "Room.h"
#include "String.h"
#include "Entity.h"

enum dir{
	NORTH,
	SOUTH,
	EAST,
	WEST

};
class Room;


class Exit:public Entity{
public:
	
	Room *origin = nullptr;
	Room *destination = nullptr;
	Entity* point=nullptr;

	dir direction;
	bool open;

public:
	Exit(const const char* name, const const char* description, bool open, Room* origins, Room* destinations, dir direction);
	Exit();//builder
	~Exit();//destroyer

};
#endif;