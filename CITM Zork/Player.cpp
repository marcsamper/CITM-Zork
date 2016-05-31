#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "World.h"
#include "Room.h"
#include "Exits.h"
#include "Item.h"
#include "Player.h"
#include "Entity.h"
#include "Vector.h"



Player::Player(){


}

Player::~Player(){

}

void Player::Inventory(){
	
	if (trans.size() == 0){
		printf("You don't have items");
	}
	
	for (int i = 0; i<trans.size(); i++){
		printf("--INVENTORY:----->");
		printf("-%s\n", trans[i]->name.c_str());			  
			  
				
	}
}
