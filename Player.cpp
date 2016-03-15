#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "World.h"
#include "Room.h"



Player::Player(){

	position = new Room;
}

Player::Player(){
	delete[] position;
}
//Principal function to move the player
