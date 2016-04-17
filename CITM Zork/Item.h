#ifndef Item_H
#define Item_H
#include "Entity.h"
class Entity;

class Item: public Entity{

public:
	Entity* item=nullptr;
	bool inventory;
public:
	Item(const char* name, const char* description, bool in);
	Item();
	~Item();
};
#endif
	