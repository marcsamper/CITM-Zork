#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "World.h"
#include "Room.h"
#include "Exits.h"
#include "Item.h"



Player::Player(){

	position = new Room;
}

Player::~Player(){
	delete[] position;
}

//Principal function to move the player
void Player::MovePosition(const World* movement, dir direction){
	if (enter == true){
		for (int i = 0; i < 18; i++){
			if (movement->exit[i]->origin== position){//Checking if the position of the player is the same of the exit origin
				if (movement->exit[i]->direction == direction){//Checking if the direction iss the same of the exit direction
					if (movement->exit[i]->open == true){//Checking if the door to enter the room is closed
						position = movement->exit[i]->destination;//Now the player position is the destination of the exit
						printf("%s\n%s\n", movement->exit[i]->destination->name, movement->exit[i]->destination->description);
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

//Method to look all the posible exits:
void Player::Look(const World*look, dir watch){
	if (enter == true){
		for (int i = 0; i < 18; i++){
			if (look->exit[i]->origin == position){//Checking if the position of the player is the same of the exit origin
				if (look->exit[i]->direction == watch){//Checking if the direction iss the same of the exit direction
					printf("%s\n", look->exit[i]->point->description);
					enter = false;
					break;
				}
			}
		}
	}
}

//Method to look and recive the information of the room you are actually in:
void Player::LookRoom(){
	printf("%s", position->description);
}

//Method open door:
void Player::OpenDoor(const World*open, dir door){
	if (enter == true){
		for (int i = 0; i < 18; i++){
			if (open->exit[i]->origin == position){//Checking if the position of the player is the same of the exit origin
				if (open->exit[i]->direction == door){//Checking if the direction iss the same of the exit direction
					if (open->exit[i]->open == false){//Checking if the door to enter the room is closed
						printf("The door is oppened\n");
						open->exit[i]->open = true;
						enter = false;
						break;
					}
				}
			}
		}
	}
}
//method close door:
void Player::CloseDoor(const World*open, dir door){
	if (enter == true){
		for (int i = 0; i < 18; i++){
			if (open->exit[i]->origin == position){//Checking if the position of the player is the same of the exit origin
				if (open->exit[i]->direction == door){//Checking if the direction iss the same of the exit direction
					if (open->exit[i]->open == true){//Checking if the door to enter the room is opened
						printf("You closed the door\n");
						open->exit[i]->open = false;
						enter = false;
						break;
					}
				}
			}
		}
	}
}
void Player::Inventory(){
	if ()
}
void Player::TakeItem(const World* item, const char* name){
	
	for (int i = 0; i < 18; i++){
		if (item->roomer[i] == position){
			for (int j = 0; j < 4; j++){
				if (item->roomer[i]->item[j]->name == name){
					if (item->roomer[i]->item[j]->in == true){
					printf("You have taken the %s", item->roomer[i]->item[j]->name);
					item->roomer[i]->item[j]->in = false;
					item->roomer[i]->item[j]->inventory = true;
					}
				}
				printf("This object doesn't exist");
			}
			printf("This object is not in this room");
		}
	}
		
	}

void Player::DropItem(const World* item, const char* name){
	for (int i = 0; i < 4; i++){
		
			for (int j = 0; j < 4; j++){
				if (item->roomer[i]->item[j]->name == name){
					if (item->roomer[i]->item[j]->in == false){
					printf("You have droped the %s", item->roomer[i]->item[j]->name);
					item->roomer[i]->item[j]->in = true;
					item->roomer[i]->item[j]->inventory = true;
				}
			}
			printf("This object doesn't exist");
		}
		printf("This object is not in this room");
	}
}


		