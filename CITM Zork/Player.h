#ifndef _PLAYER_H
#define _PLAYER_H
#include "Room.h"
#include "Exits.h"


class Player: public Entity{
public:
	
	Room *position=nullptr;
	Vector<Entity*> trans;
	int life= 100;//stats
	int attack=40;//stats
	

public:

	bool enter = true;
	void Inventory();
	/*void MovePosition(const World*movement, dir direction);
	void Look(const World*look, dir watch);
	void LookRoom();
	void OpenDoor(const World* open, dir door);
	void CloseDoor(const World* open, dir door);
	void PickItem(const World* take, String& name);
	void DropItem(const World* item, String& name);*/

	Player();//builder
	~Player();//destroyer

};
#endif