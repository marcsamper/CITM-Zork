#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Entity.h"

Entity::Entity(const char* name, const char* description): name(name), description(description){
	
}
Entity::Entity(const char* name, const char* description, bool in) : name(name), description(description), in(in){

}
Entity::Entity(){

}

Entity::~Entity(){

}