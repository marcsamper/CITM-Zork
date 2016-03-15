#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "World.h"
#include "Room.h"



Player::Player(){

	position = new Room;
}

Player::~Player(){
	delete[] position;
}
//Principal function to move the player
void Player::MovePosition(World* movement, dir direction){
	if (enter == true){
		for (int i = 0; i < 15; i++){
			if (movement->exit[i].origin == position){
				if (movement->exit[i].direction == direction){
					if (movement->exit[i].open = true){
						position = movement->exit[i].destination;
						printf("%s\n %s\n", movement->exit[i].destination->name, movement->exit[i].destination->description);
						enter = false;
						break;
					}
					else{
						printf("The door is closed!\n");
						break;
					}
				}

			}

		}

	}
}
