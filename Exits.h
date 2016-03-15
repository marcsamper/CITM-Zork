

#ifndef _EXIT_H
#define _EXIT_H
#include "Room.h"

enum dir{
	NORTH,
	SOUTH,
	EAST,
	WEST
	
};
class Room;


class Exit{
public:
	char name[20];
	char description[250];
	Room *origin=nullptr;
	Room *destination=nullptr;
	bool open=true;
	dir direction;

/*public:
	Exit();
	~Exit();*/

};
#endif;