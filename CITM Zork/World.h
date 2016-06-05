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
	void MovePosition(const dir direction)const;
	void Look(const dir direction)const;
	void LookRoom();
	void OpenDoor(dir door);
	void CloseDoor(dir door);
	void PickItem( const String& name);
	void DropItem(const String& name);
	bool Inpunts();
	void PutItem(const String& item);
	void GetItem(const String& item);
	void Description(const String& name)const;
	void Map()const;
	void talk(const String& names)const;
	void talkidle(const String& names)const;
	void talkidle2(const String& names)const;
	void buy(const String& names)const;
	void Npcmove()const;
	World();//builder
	~World();//destroyer



};
#endif