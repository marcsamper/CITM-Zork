#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Entity.h"

Entity::Entity(const char* name, const char* description){
	this->name = name;
	this->description = description;

}
Entity::Entity(){

}

Entity::~Entity(){

}