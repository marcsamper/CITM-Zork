#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "World.h"



World::World()
{
	room = new Room[11];
	exit = new Exit[18];
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
	strcpy_s(room[0].description,"You are now in the entrance of the CITM.");
	strcpy_s(room[1].name, "Secretary's Room");
	strcpy_s(room[1].description,"You are now in the Secretary's Room. Seems nobody is here.There are some papers about the students on the table.Go West to exit the room");
	strcpy_s(room[2].name, "Photography set");
	strcpy_s(room[2].description,"You are now in the Photography set, a big room equiped with a lot of technology.In the center of the set you can see a camera on the floor next to a red backpack.Go East to exit the room");
	strcpy_s(room[3].name, "Floor 1");
	strcpy_s(room[3].description,"You are now in the Floor 1, you can see some students talking next to a drinking fountain.");
	strcpy_s(room[4].name, "Toilets");
	strcpy_s(room[4].description,"You are now in the toilets, the floor is a little wet but the smell is not that bad.\nThere are three toilets and a big mirror.In front of the mirror there's a boy crying.Go South to exit the room");
	strcpy_s(room[5].name, "Art Room");
	strcpy_s(room[5].description,"You are now in the Art Room, you see a lot of tables and a huge amount of pencils.\n You also see a boy, his name is Pep, he is the bully who has stolen your homework.Go North to exit the room East");
	strcpy_s(room[6].name, "Neg Floor");
	strcpy_s(room[6].description,"You are in the floor -1. It's a little cold.");
	strcpy_s(room[7].name, "Vending Machine");
	strcpy_s(room[7].description,"You are in front of the vending machine, there are a los of snacks, but you don't have money.Go East to exit the room");
	strcpy_s(room[8].name, "Dining Room");
	strcpy_s(room[8].description,"You are in the dining room. You can see 3 big tables and two microwaves.\nThere are few people on the last table having lunch.Go West to exit the room");
	strcpy_s(room[9].name, "Programming Room");
	strcpy_s(room[9].description,"You have entered teh Programming Room.You are alone with the teacher. He looks very angry.\nBut if you have your homework you will not have any problem...Go North to exit the room");
	//PLAYER FIRST POSITION:
	
	player->position= &room[0];
	strcpy_s(player->name, "Jimmy");


	//SETTING UP EXITS: NAME, DESCRIPTION, ORIGIN, DESTINATION AND DIRECTION
	//Entrance exit to Secretary's Room:
	strcpy_s(exit[0].name, "E-S");
	strcpy_s(exit[0].description,"You see the Secretary's Room, but nobody is inside");
	exit[0].origin = &room[0];
	exit[0].destination = &room[1];
	exit[0].open = true;
	exit[0].direction = EAST;
	//Secretary's Room exit to Entrance:
	strcpy_s(exit[1].name, "S-E");
	strcpy_s(exit[1].description,"You see the entrance, there's a lot of silence");
	exit[1].origin = &room[1];
	exit[1].destination = &room[0];
	exit[1].open = true;
	exit[1].direction = WEST;
	//Entrance exit to Photography set:
	strcpy_s(exit[2].name, "E-P");
	strcpy_s(exit[2].description,"You see the photograpy set, but seems the door is closed");
	exit[2].origin = &room[0];
	exit[2].destination = &room[2];
	exit[2].open = false;
	exit[2].direction = WEST;
	//Photography set exit to Entrance:
	strcpy_s(exit[3].name, "P-E");
	strcpy_s(exit[3].description,"You see the entrance, there's a lot of silence");
	exit[3].origin = &room[2];
	exit[3].destination = &room[0];
	exit[3].open = true;
	exit[3].direction = EAST;
	//Entrance exit to floor 1 by upstairs:
	strcpy_s(exit[4].name, "E-F");
	strcpy_s(exit[4].description,"You see the upstairs that go to the floor 1");
	exit[4].origin = &room[0];
	exit[4].destination = &room[3];
	exit[4].open = true;
	exit[4].direction = NORTH;
	//Floor 1 exit to Entrance by Downstairs:
	strcpy_s(exit[5].name, "F-E");
	strcpy_s(exit[5].description,"You see the downstairs that go to the entrance");
	exit[5].origin = &room[3];
	exit[5].destination = &room[0];
	exit[5].open = true;
	exit[5].direction = SOUTH;
	//Floor 1 exit to Toilets:
	strcpy_s(exit[6].name, "F-T");
	strcpy_s(exit[6].description,"You see the toilets, there's a tears trail");
	exit[6].origin = &room[3];
	exit[6].destination = &room[4];
	exit[6].open = true;
	exit[6].direction = NORTH;
	//Toilet exit to the Floor 1:
	strcpy_s(exit[7].name, "T-F");
	strcpy_s(exit[7].description,"You see the whole Floor 1, the sun iluminates all the floor");
	exit[7].origin = &room[4];
	exit[7].destination = &room[3];
	exit[7].open = true;
	exit[7].direction = SOUTH;
	//Floor 1 exit to the art Room:
	strcpy_s(exit[8].name, "F-A");
	strcpy_s(exit[8].description,"You see the Art Room, there are some pencils on the entrance");
	exit[8].origin = &room[3];
	exit[8].destination = &room[5];
	exit[8].open = true;
	exit[8].direction = WEST;
	//Art Room exit to the Floor 1:
	strcpy_s(exit[9].name, "A-F");
	strcpy_s(exit[9].description,"You see the whole Floor 1, the sun iluminates all the floor 1");
	exit[9].origin = &room[5];
	exit[9].destination = &room[3];
	exit[9].open = true;
	exit[9].direction = EAST;
	//Entrance exit to floor -1 by downstairs:
	strcpy_s(exit[10].name, "E-N");
	strcpy_s(exit[10].description,"You see the downstairs that go to the floor -1");
	exit[10].origin = &room[0];
	exit[10].destination = &room[6];
	exit[10].open = true;
	exit[10].direction = SOUTH;
	//Floor -1 exit to the entrance by Upstairs:
	strcpy_s(exit[11].name, "N-E");
	strcpy_s(exit[11].description,"You see the upstairs that go to the Entrance");
	exit[11].origin = &room[6];
	exit[11].destination = &room[0];
	exit[11].open = true;
	exit[11].direction = NORTH;
	//Floor-1 exit to the Vending Machine:			
	strcpy_s(exit[12].name, "N-V");
	strcpy_s(exit[12].description,"You see the Vending Machine, it has a lot of snacks");
	exit[12].origin = &room[6];
	exit[12].destination = &room[7];
	exit[12].open = true;
	exit[12].direction = WEST;
	//Vending Machine exit to the Floor -1:
	strcpy_s(exit[13].name, "V-N");
	strcpy_s(exit[13].description,"You can see the whole floor -1, it's a little bit cold");
	exit[13].origin = &room[7];
	exit[13].destination = &room[6];
	exit[13].open = true;
	exit[13].direction = EAST;
	//Floor -1 exit to the dining rooom:
	strcpy_s(exit[14].name, "N-D");
	strcpy_s(exit[14].description,"You see the entrance of the dining room, and you hear some noises inside");
	exit[14].origin = &room[6];
	exit[14].destination = &room[8];
	exit[14].open = true;
	exit[14].direction = EAST;
	//Dining Room exit to the floor -1:
	strcpy_s(exit[15].name, "D-N");
	strcpy_s(exit[15].description,"You can see the whole floor -1, it's a little bit cold");
	exit[15].origin = &room[8];
	exit[15].destination = &room[6];
	exit[15].open = true;
	exit[15].direction = WEST;
	//Floor -1 exit to the programming room:
	strcpy_s(exit[16].name, "N-P");
	strcpy_s(exit[16].description,"You see the programming room.In this class you have to deliver your homework. It's a bad idea if you enter without the homework.");
	exit[16].origin = &room[6];
	exit[16].destination = &room[9];
	exit[16].open = true;
	exit[16].direction = SOUTH;
	//Programming room exit to the floor -1:
	strcpy_s(exit[17].name, "P-N");
	strcpy_s(exit[17].description,"You can see the whole floor -1, it's a little bit cold");
	exit[17].origin = &room[9];
	exit[17].destination = &room[6];
	exit[17].open = true;
	exit[17].direction = NORTH;

}
//Chequing the commands the playar writes:
bool World::Inpunts(){
	fflush(stdin);
	char command[20];
	char first[15];
	char second[15] = "void";
	char *phrase;
	gets_s(command);
	if (strcmp(command, "\0") == 0){
		return true;
	}

	strcpy_s(first, strtok_s(command, " ", &phrase));
	if (strcmp(phrase, "") != 0){
		strcpy_s(second, strtok_s(NULL, " ", &phrase));
	}
	//Comand Quit to exit the game
	if (strcmp(first, "Quit") == 0 || strcmp(first, "quit") == 0 || strcmp(first, "q") == 0 || strcmp(first, "QUIT") == 0){
		printf("You exit the game");
		return false;
	}
	//Command Go:
	else if (strcmp(first, "Go") == 0 || strcmp(first, "go") == 0 || strcmp(first, "GO") == 0 || strcmp(first, "g") == 0){
		if (strcmp(second, "void") == 0){
			printf("Where?\n");
			gets_s(second);
		}
		//East:
		if (strcmp(second, "east") == 0 || strcmp(second, "East") == 0 || strcmp(second, "EAST") == 0 || strcmp(second, "e") == 0){
			player->MovePosition(this, EAST);
		}

		//South
		if (strcmp(second, "south") == 0 || strcmp(second, "South") == 0 || strcmp(second, "SOUTH") == 0 || strcmp(second, "s") == 0){
			player->MovePosition(this, SOUTH);
		}
		//West
		if (strcmp(second, "west") == 0 || strcmp(second, "West") == 0 || strcmp(second, "WEST") == 0 || strcmp(second, "w") == 0){
			player->MovePosition(this, WEST);
		}
		//North
		if (strcmp(second, "north") == 0 || strcmp(second, "North") == 0 || strcmp(second, "NORTH") == 0 || strcmp(second, "n") == 0){
			player->MovePosition(this, NORTH);

		}
	}

	//Moving without using the command go:
	if (strcmp(first, "east") == 0 || strcmp(first, "East") == 0 || strcmp(first, "EAST") == 0 || strcmp(first, "e") == 0){
		player->MovePosition(this, EAST);
	}

	//South
	if (strcmp(first, "south") == 0 || strcmp(first, "South") == 0 || strcmp(first, "SOUTH") == 0 || strcmp(first, "s") == 0){
		player->MovePosition(this, SOUTH);
	}
	//West
	if (strcmp(first, "west") == 0 || strcmp(first, "West") == 0 || strcmp(first, "WEST") == 0 || strcmp(first, "w") == 0){
		player->MovePosition(this, WEST);
	}
	//North
	if (strcmp(first, "north") == 0 || strcmp(first, "North") == 0 || strcmp(first, "NORTH") == 0 || strcmp(first, "n") == 0){
		player->MovePosition(this, NORTH);

	}
	//Command Look:
	else if (strcmp(first, "Look") == 0 || strcmp(first, "look") == 0 || strcmp(first, "LOOK") == 0 || strcmp(first, "l") == 0){
		if (strcmp(second, "void") == 0){
			printf("Where?\n");
			gets_s(second);
		}
		//East:
		if (strcmp(second, "east") == 0 || strcmp(second, "East") == 0 || strcmp(second, "EAST") == 0 || strcmp(second, "e") == 0){
			player->Look(this, EAST);
		}

		//South
		if (strcmp(second, "south") == 0 || strcmp(second, "South") == 0 || strcmp(second, "SOUTH") == 0 || strcmp(second, "s") == 0){
			player->Look(this, SOUTH);
		}
		//West
		if (strcmp(second, "west") == 0 || strcmp(second, "West") == 0 || strcmp(second, "WEST") == 0 || strcmp(second, "w") == 0){
			player->Look(this, WEST);
		}
		//North
		if (strcmp(second, "north") == 0 || strcmp(second, "North") == 0 || strcmp(second, "NORTH") == 0 || strcmp(second, "n") == 0){
			player->Look(this, NORTH);

		}
		if (strcmp(second, "room") == 0 || strcmp(second, "Room") == 0 || strcmp(second, "ROOM") == 0 || strcmp(second, "r") == 0){
			player->LookRoom();

		}
	}
	//Command help to explain how all the commands work
	else if (strcmp(first, "help") == 0 || strcmp(first, "Help") == 0 || strcmp(first, "HELP") == 0 || strcmp(first, "h") == 0){
		printf("TO MOVE THROUGH THE ROOMS USE THE COMAND GO, go, Go, 'g' PLUS THE DIRECTION YOU WANT (NORTH, north,North, 'n', SOUTH, south, South,'s', EAST, east, East,'e', WEST,west, West, 'w').YOU CAN ALSO MOVE BY ONLY WRITING (NORTH, north,North, 'n', SOUTH, south, South,'s', EAST, east, East,'e', WEST,west, West, 'w').TOO LOOK ALL THE POSIBLE EXITS USE THE COMMAND LOOK, look, Look, 'l' PLUS THE  DIRECTION YOU WANT.\nUSE THE COMPAND OPEN/CLOSE, open/close, Open/close, 'o'/'c' TO OPEN/CLOSE DOORS. IF YOU WANT TO EXIT WRITE QUIT, 'q'.\n ");
	}

	//Commands to open/close the doors:
	//OPEN:
	else if (strcmp(first, "Open") == 0 || strcmp(first, "open") == 0 || strcmp(first, "OPEN") == 0 || strcmp(first, "o") == 0){
		if (strcmp(second, "void") == 0){
			printf("Where?\n");
			gets_s(second);
		}
		//East:
		if (strcmp(second, "east") == 0 || strcmp(second, "East") == 0 || strcmp(second, "EAST") == 0 || strcmp(second, "e") == 0){
			player->OpenDoor(this, EAST);
		}

		//South
		if (strcmp(second, "south") == 0 || strcmp(second, "South") == 0 || strcmp(second, "SOUTH") == 0 || strcmp(second, "s") == 0){
			player->OpenDoor(this, SOUTH);
		}
		//West
		if (strcmp(second, "west") == 0 || strcmp(second, "West") == 0 || strcmp(second, "WEST") == 0 || strcmp(second, "w") == 0){
			player->OpenDoor(this, WEST);
		}
		//North
		if (strcmp(second, "north") == 0 || strcmp(second, "North") == 0 || strcmp(second, "NORTH") == 0 || strcmp(second, "n") == 0){
			player->OpenDoor(this, NORTH);
		}
	}
		//CLOSE:
	else if (strcmp(first, "Close") == 0 || strcmp(first, "close") == 0 || strcmp(first, "CLOSE") == 0 || strcmp(first, "c") == 0){
		if (strcmp(second, "void") == 0){
			printf("Where?\n");
			gets_s(second);
		}
		//East:
		if (strcmp(second, "east") == 0 || strcmp(second, "East") == 0 || strcmp(second, "EAST") == 0 || strcmp(second, "e") == 0){
			player->CloseDoor(this, EAST);
		}

		//South
		if (strcmp(second, "south") == 0 || strcmp(second, "South") == 0 || strcmp(second, "SOUTH") == 0 || strcmp(second, "s") == 0){
			player->CloseDoor(this, SOUTH);
		}
		//West
		if (strcmp(second, "west") == 0 || strcmp(second, "West") == 0 || strcmp(second, "WEST") == 0 || strcmp(second, "w") == 0){
			player->CloseDoor(this, WEST);
		}
		//North
		if (strcmp(second, "north") == 0 || strcmp(second, "North") == 0 || strcmp(second, "NORTH") == 0 || strcmp(second, "n") == 0){
			player->CloseDoor(this, NORTH);

		}
	}
				
	player->enter = true;
	return true;
}







