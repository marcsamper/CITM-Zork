#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "World.h"
#include"Exits.h"
#include "Player.h"
#include "Room.h"


World::World()
{
	room = new Room[11];
	exit = new Exit[15];
	player = new Player[1];
}

World::~World(){

	delete[] room;
	delete[] exit;
	delete[] player;
}
void World::CreateWorld(){
	

	//NAMES AND DESCRIPTIONS FOR EVERY ROOM 

	strcpy_s(room[0].name, "Entrance");
	strcpy_s(room[0].description, "You are now in the entrance of the CITM.\nTo the NORTH you can see the stairs that go down to the floor -1.\n To the EAST we find the Secretary's office.\nTo the WEST there's the entrance to the photography room, but the door is closed.\nTo the SOUTH there are the stairs that go up to the floor 1\n");
	strcpy_s(room[1].name, "Secretary's Room");
	strcpy_s(room[1].description, "You are now in the Secretary's Room. Seems nobody is here.\nYou can see a big table, some chairs and two computers.\nOn the table there are some papers and also a newspaper\nTo the west you have the door to return to the entrance");
	strcpy_s(room[2].name, "Photography set");
	strcpy_s(room[2].description, "You are now in the Photography set, a big room equiped with a lot of technology.\nIn the center of the set you can see a camera on the floor next to a red backpack\nTo the East you can return to the Entrance");
	strcpy_s(room[3].name, "Floor 1");
	strcpy_s(room[3].description, "You are now in the Floor 1, you can see some students talking next to a drinking fountain.\n To the NORTH you can see the toilets,it seems there's a tear's trail.\n To the WEST there's the Art Room, and you hear the voice of someone.\nTo the SOUTH there are the stairs to go down to the floor 0.\n");
	strcpy_s(room[4].name, "Toilets");
	strcpy_s(room[4].description, "You are now in the toilets, the floor is a little wet but the smell is not that bad.\nThere are three toilets and a big mirror.\nIn front of the mirror there's a boy crying.\n");
	strcpy_s(room[5].name, "Art Room");
	strcpy_s(room[5].description, "You are now in the Art Room, you see a lot of tables and a huge amount of pencils.\n You also see a boy, his name is Paul, he is the bully who has stolen your homework.");
	strcpy_s(room[6].name, "Neg Floor");
	strcpy_s(room[6].description, "You are in the floor -1. It's a little cold.\nTo the NORTH there are the stairs to go up to the floor0.\nTo the EAST there's the entrance to the dining room.\nTo the WEST there's the vending machine with a lot of delicious snaks.\nTo the SOUTH there's the room where you have to deliver yout work");
	strcpy_s(room[7].name, "Vending Machine");
	strcpy_s(room[7].description, "You are in front of the vending machine, there are a los of snacks, but you don't have money.\nTo the EAST you can return to the Floor -1 ");
	strcpy_s(room[8].name, "Dining Room");
	strcpy_s(room[8].description, "You are in the dining room. You can see 3 big tables and two microwaves.\nThere are few people on the last table having lunch.\nTo the WEST you can return to the Floor -1 ");
	strcpy_s(room[9].name, "Programming Room");
	strcpy_s(room[9].description, "You have entered teh Programming Room.\nYou are alone with the teacher. He looks very angry.\nBut if you have your homework you will not have any problem.\n");
	//PLAYER FIRST POSITION:
	Player *position;
	position->position = &room[0];
	strcpy(player->name, "Jimmy");


	//SETTING UP EXITS: NAME, DESCRIPTION, ORIGIN, DESTINATION AND DIRECTION
	//Entrance exit to Secretary's Room:
	strcpy(exit[0].name, "E-S");
	strcpy(exit[0].description, "You are entring to the Secretary's Room");
	exit[0].origin = &room[0];
	exit[0].destination = &room[1];
	exit[0].direction = EAST;
	//Secretary's Room exit to Entrance:
	strcpy(exit[1].name, "S-E");
	strcpy(exit[1].description, "You are going to the entrance");
	exit[1].origin = &room[1];
	exit[1].destination = &room[0];
	exit[1].direction = WEST;
	//Entrance exit to Photogrphy set:
	strcpy(exit[2].name, "E-P");
	strcpy(exit[2].description, "You want to enter the Photograph");
	exit[2].origin = &room[0];
	exit[2].destination = &room[2];
	exit[2].open = false;
	exit[2].direction = WEST;
	//Photography set exit to Entrance:
	strcpy(exit[3].name, "P-E");
	strcpy(exit[3].description, "You are going to the entrance");
	exit[3].origin = &room[2];
	exit[3].destination = &room[0];
	exit[3].direction = EAST;
	//Entrance exit to floor 1 by upstairs:
	strcpy(exit[4].name, "E-F");
	strcpy(exit[4].description, "Going to the stairs to go to the floor 1");
	exit[4].origin = &room[0];
	exit[4].destination = &room[3];
	exit[4].direction = NORTH;
	//Floor 1 exit to Entrance by Downstairs:
	strcpy(exit[5].name, "F-E");
	strcpy(exit[5].description, "You are going to the stairs to go to the entrance");
	exit[5].origin = &room[3];
	exit[5].destination = &room[0];
	exit[5].direction = SOUTH;
	//Floor 1 exit to Toilets:
	strcpy(exit[6].name, "F-T");
	strcpy(exit[6].description, "You are going to the toilets");
	exit[6].origin = &room[3];
	exit[6].destination = &room[4];
	exit[6].direction = NORTH;
	//Toilet exit to the Floor 1:
	strcpy(exit[7].name, "T-F");
	strcpy(exit[7].description, "You are going to the floor 1");
	exit[7].origin = &room[4];
	exit[7].destination = &room[3];
	exit[7].direction = SOUTH;
	//Floor 1 exit to the art Room:
	strcpy(exit[8].name, "F-A");
	strcpy(exit[8].description, "You are going to the Art Room");
	exit[8].origin = &room[3];
	exit[8].destination = &room[5];
	exit[8].direction = WEST;
	//Art Room exit to the Floor 1:
	strcpy(exit[9].name, "A-F");
	strcpy(exit[9].description, "You are leaving Art Room to go to the Floor 1");
	exit[9].origin = &room[5];
	exit[9].destination = &room[3];
	exit[9].direction = EAST;
	//Entrance exit to floor -1 by downstairs:
	strcpy(exit[10].name, "E-N");
	strcpy(exit[10].description, "You are going to the stairs to go to the floor -1");
	exit[10].origin = &room[0];
	exit[10].destination = &room[6];
	exit[10].direction = SOUTH;
	//Floor -1 exit to the entrance by Upstairs:
	strcpy(exit[11].name, "N-E");
	strcpy(exit[11].description, "You are going to the stairs to go to the Entrance");
	exit[11].origin = &room[6];
	exit[11].destination = &room[0];
	exit[11].direction = NORTH;
	//Floor-1 exit to the Vending Machine:			
	strcpy(exit[12].name, "N-V");
	strcpy(exit[12].description, "You are going to the Vending Machine");
	exit[12].origin = &room[6];
	exit[12].destination = &room[7];
	exit[12].direction = WEST;
	//Vending Machine exit to the Floor -1:
	strcpy(exit[13].name, "V-N");
	strcpy(exit[13].description, "You are going to the floor -1");
	exit[13].origin = &room[7];
	exit[13].destination = &room[6];
	exit[13].direction = EAST;
	//Floor -1 exit to the dining rooom:
	strcpy(exit[14].name, "N-D");
	strcpy(exit[14].description, "You are going to the dining room");
	exit[14].origin = &room[6];
	exit[14].destination = &room[8];
	exit[14].direction = EAST;
	//Dining Room exit to the floor -1:
	strcpy(exit[14].name, "D-N");
	strcpy(exit[14].description, "You are going to the floor -1");
	exit[14].origin = &room[8];
	exit[14].destination = &room[6];
	exit[14].direction = WEST;
	//Floor -1 exit to the programming room:
	strcpy(exit[14].name, "N-P");
	strcpy(exit[14].description, "You are in front of the programming room.\nIn this class you have to deliver your homework\nIt's a bad idea if you enter without the homework\n");
	exit[14].origin = &room[6];
	exit[14].destination = &room[9];
	exit[14].direction = SOUTH;
	//Programming room exit to the floor -1:
	strcpy(exit[14].name, "P-N");
	strcpy(exit[14].description, "You are leaving the programming room to go to the floor -1");
	exit[14].origin = &room[9];
	exit[14].destination = &room[8];
	exit[14].direction = NORTH;

}







