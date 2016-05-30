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

	
	Vector<Entity*> entity;
	
	
	Player* player=nullptr;
	String* pointer=nullptr;
	Npc* npcs=nullptr;
	World* go = nullptr;
	
	

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
	void Map()const;
	void talk(const String names)const;
	void talkidle(const String names)const;
	void talkidle2(const String names)const;
	void buy(const String names)const;
	World();//builder
	~World();//destroyer



};
#endif