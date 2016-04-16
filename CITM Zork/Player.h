#ifndef _PLAYER_H
#define _PLAYER_H
#include "Room.h"
#include "Exits.h"
class World;

class Player: public Entity{
public:
	
	Room *position=nullptr;

public:

	bool enter = true;
	void MovePosition(const World*movement, dir direction);
	void Look(const World*look, dir watch);
	void LookRoom();
	void OpenDoor(const World* open, dir door);
	void CloseDoor(const World* open, dir door);
	void TakeItem(const World* take, const char* name);
	void DropItem(const World* item, const char* name);
	Player();//builder
	~Player();//destroyer

};
#endif