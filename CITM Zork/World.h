#ifndef _WORLD_H
#define _WORLD_H
#include "Room.h"
#include "Exits.h"
#include "Player.h"
#include "Entity.h"
#include "String.h"
#include "Vector.h"
#include "Item.h"
class World: public Entity{
public:

	Vector<Room*> roomer;
	Vector<Exit*> exit;
	Vector<Item*> item;
	Player* player;
	String* pointer=nullptr;
	
	

public:
	void CreateWorld();
	void MovePosition(dir direction);
	void Look(dir direction);
	void LookRoom();
	void OpenDoor(dir door);
	void CloseDoor(dir door);
	void PickItem(String& name)const;
	void DropItem(String& name)const;
	bool Inpunts(String& command);
	World();//builder
	~World();//destroyer



};
#endif