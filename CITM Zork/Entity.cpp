#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Entity.h"

Entity::Entity(const char* name, const char* description, type types) : name(name), description(description),types(types){

}


Entity::Entity(){

}

Entity::~Entity(){

}