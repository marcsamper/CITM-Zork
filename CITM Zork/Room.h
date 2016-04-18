#ifndef _ROOM_H
#define _ROOM_H
#include <stdio.h>
#include "Entity.h"
#include "String.h"
#include "Vector.h"



class Room:public Entity{

public:
	Room (const char* name, const char* description);

	~Room();


};
#endif;