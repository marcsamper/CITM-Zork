#include "Entity.h"
#include "Creatures.h"
#ifndef NPC_H
#define NPC_H



class Npc : public Creature{
public:
	Vector<Entity*> give;
	bool enter = true;

public:

	Npc(char* name, char* description, Room* origin);
	~Npc();
	
	


};


#endif NPC_H

