#include <stdio.h>
#include <stdlib.h>
#include "Room.h"

Room::Room(const char* name, const char* description) {
	point->name = name;
	point->description = description;
	

}
Room::Room(){
	Entity*point;
}
Room::~Room(){
	delete[] point;
}
