#include "String.h"
#include "Vector.h"
#include <stdio.h>
#include "Entity.h"


#ifndef _ROOM_H
#define _ROOM_H



class Room :public Entity{
public:


	Room (const char* name, const char* description);
	Room();
	~Room();


};

#endif;