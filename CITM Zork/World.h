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
	Vector<Npc*> npc;
	
	
	Player* player;
	String* pointer=nullptr;
	
	

public:
	void CreateWorld();
	void MovePosition(dir direction);
	void Look(dir direction);
	void LookRoom();
	void OpenDoor(dir door);
	void CloseDoor(dir door);
	void PickItem( String name);
	void DropItem(const String name);
	bool Inpunts();
	void PutItem(const String item);
	void GetItem(const String item);
	void Description(const String name)const;
	void Map();
	World();//builder
	~World();//destroyer



};
#endif