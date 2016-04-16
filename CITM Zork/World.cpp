#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "World.h"
#include "String.h"
#include "Entity.h"
#include "Vector.h"
#include "Item.h"



World::World()
{
	
	Room* entrance;
	player = new Player[1];
	
	
}

World::~World(){

	

	delete[] player;
	
	
}
void World::CreateWorld(){
	Room* entrance;

	//NAMES AND DESCRIPTIONS FOR EVERY ROOM 
	roomer.push_back((new Room("Entrance", "You are now in the entrance of the CITM.")));//room 0
	roomer.push_back((new Room("Secretary's Room", "You are now in the Secretary's Room. Seems nobody is here.There are some papers about the students on the table.Go West to exit the room")));//room 1
	roomer.push_back((new Room("Photography set", "You are now in the Photography set, a big room equiped with a lot of technology.In the center of the set you can see a camera on the floor next to a red\nbackpack.Go East to exit the room")));//room 2
	roomer.push_back((new Room("Floor 1", "You are now in the Floor 1, you can see some students talking next to a drinkingfountain.")));//room 3
	roomer.push_back((new Room("Toilets", "You are now in the toilets, the floor is a little wet but the smell is not that bad.There are three toilets and a big mirror.In front of the mirror there's a boy crying.Go South to exit the room")));//room 4
	roomer.push_back((new Room("Art Room", "You are now in the Art Room, you see a lot of tables and a huge amount of pencils.You also see a boy, his name is Pep, he is the bully who has stolen your homework.Go North to exit the room East")));//room 5
	roomer.push_back((new Room("Neg Floor", "You are in the floor -1. It's a little cold.")));//room 6
	roomer.push_back((new Room("Vending Machine", "You are in front of the vending machine, there are a los of snacks, but you don't have money.Go East to exit the room")));//room 7
	roomer.push_back((new Room("Dining Room", "You are in the dining room. You can see 3 big tables and two microwaves.There are few people on the last table having lunch.Go West to exit the room")));//room 8
	roomer.push_back((new Room("Programming Room", "You have entered teh Programming Room.You are alone with the teacher. He looks very angry.But if you have your homework you will not have any problem...Go North to exit the room")));//room 9
	
	//SETTING THE PLAYER NAME AND POSITION:

	player->position = roomer[0];
	
	//SETTING UP EXITS: NAME, DESCRIPTION, ORIGIN, DESTINATION, DIRECTION AND OPEN:
	
	exit.push_back((new Exit("E-S", "You see the Secretary's Room, but nobody is inside", true, roomer[0], roomer[1], EAST)));//Entrance exit to Secretary's Room
	exit.push_back((new Exit("S-E", "You see the entrance, there's a lot of silence", true, roomer[1], roomer[0], WEST)));//Secretary's Room exit to Entrance
	exit.push_back((new Exit("E-S", "You see the photograpy set, but seems the door is closed",false, roomer[0], roomer[2], WEST)));//Entrance exit to Photography set
	exit.push_back((new Exit("P-E", "You see the entrance, there's a lot of silence", true, roomer[2], roomer[0], EAST)));//Photography set exit to Entrance
	exit.push_back((new Exit("E-F", "You see the upstairs that go to the floor 1", true, roomer[0], roomer[3], NORTH)));//Entrance exit to floor 1 by upstairs
	exit.push_back((new Exit("F-E", "You see the downstairs that go to the entrance", true, roomer[3], roomer[0], SOUTH)));//Floor 1 exit to Entrance by Downstairs
	exit.push_back((new Exit("F-T", "You see the toilets, there's a tears trail", true, roomer[3], roomer[4], NORTH)));//Floor 1 exit to Toilets
	exit.push_back((new Exit("T-F", "You see the whole Floor 1, the sun iluminates all the floor", true, roomer[4], roomer[3], WEST)));//Toilet exit to the Floor 1
	exit.push_back((new Exit("F-A", "You see the Art Room, there are some pencils on the entrance", true, roomer[3], roomer[5], WEST)));//Floor 1 exit to the art Room
	exit.push_back((new Exit("A-F", "You see the whole Floor 1, the sun iluminates all the floor 1", true, roomer[5], roomer[3], EAST)));//Art Room exit to the Floor 1
	exit.push_back((new Exit("E-N", "You see the downstairs that go to the floor -1", true, roomer[0], roomer[6], SOUTH)));//Entrance exit to floor -1 by downstairs
	exit.push_back((new Exit("N-E", "You see the upstairs that go to the Entrance", true, roomer[6], roomer[0], NORTH)));//Floor -1 exit to the entrance by Upstairs
	exit.push_back((new Exit("N-V", "You see the Vending Machine, it has a lot of snacks", true, roomer[6], roomer[7], WEST)));//Floor-1 exit to the Vending Machine:
	exit.push_back((new Exit("V-N", "You can see the whole floor -1, it's a little bit cold", true, roomer[7], roomer[6], EAST)));//Vending Machine exit to the Floor -1
	exit.push_back((new Exit("N-D", "You see the entrance of the dining room, and you hear some noises inside", true, roomer[6], roomer[8], EAST)));//Floor -1 exit to the dining rooom
	exit.push_back((new Exit("D-N", "You can see the whole floor -1, it's a little bit cold", true, roomer[8], roomer[6], WEST)));	//Dining Room exit to the floor -1
	exit.push_back((new Exit("N-P", "You see the programming room.In this class you have to deliver your homework. It's a bad idea if you enter without the homework.", true, roomer[6], roomer[9], SOUTH)));//Floor -1 exit to the programming room
	exit.push_back((new Exit("P-N", "You can see the whole floor -1, it's a little bit cold", true, roomer[9], roomer[6], NORTH)));	//Programming room exit to the floor - 1
	
	//ADD EVERY ITEM IN EACH ROOM:
	roomer[1]->item.push_back((new Item("Folder", "A folder with all the information of some students", true)));
	roomer[2]->item.push_back((new Item("Camera", "A new shinny camera with some stickers", true)));
	roomer[7]->item.push_back((new Item("Candy", "Seems somebody loves this candy", true)));
	roomer[8]->item.push_back((new Item("Kleenex", "They have a strawberry smell, probably someone needs them", true)));


	


}
//Chequing the commands the playar writes:
bool World::Inpunts(){
	fflush(stdin);
	char command[20];//the complet command
	char first[15];//here will go the first command
	char second[15] = "void";//here will go the second command, initialized with 'void' cause if the player only puts one word
	char *phrase;
	gets_s(command);
	if (pointer->compare(command, "\0") == 0){
		return true;
	}

	//Copying the first word to first
	strcpy_s(first, strtok_s(command, " ", &phrase));
	if (pointer->compare(phrase, "") != 0){
		strcpy_s(second, strtok_s(NULL, " ", &phrase));
	}
	//Comand Quit to exit the game
	if (pointer->compare(first, "Quit") == 0 || pointer->compare(first, "quit") == 0 || pointer->compare(first, "q") == 0 || pointer->compare(first, "QUIT") == 0){
		printf("You exit the game");
		return false;//here we stop the loop and stops execution the function Inputs on main.cpp
	}
	//Command Go:
	else if (pointer->compare(first, "Go") == 0 || pointer->compare(first, "go") == 0 || pointer->compare(first, "GO") == 0 || pointer->compare(first, "g") == 0){
		if (pointer->compare(second, "void") == 0){//if the player only writes Go, the programm asks the direction and puts it in second
			printf("Where?\n");
			gets_s(second);
		}
		//East:
		if (pointer->compare(second, "east") == 0 || pointer->compare(second, "East") == 0 || pointer->compare(second, "EAST") == 0 || pointer->compare(second, "e") == 0){
			player->MovePosition(this, EAST);
		}

		//South
		if (pointer->compare(second, "south") == 0 || pointer->compare(second, "South") == 0 || pointer->compare(second, "SOUTH") == 0 || pointer->compare(second, "s") == 0){
			player->MovePosition(this, SOUTH);
		}
		//West
		if (pointer->compare(second, "west") == 0 || pointer->compare(second, "West") == 0 || pointer->compare(second, "WEST") == 0 || pointer->compare(second, "w") == 0){
			player->MovePosition(this, WEST);
		}
		//North
		if (pointer->compare(second, "north") == 0 || pointer->compare(second, "North") == 0 || pointer->compare(second, "NORTH") == 0 || pointer->compare(second, "n") == 0){
			player->MovePosition(this, NORTH);

		}
	}

	//Moving without using the command go:
	if (pointer->compare(first, "east") == 0 || pointer->compare(first, "East") == 0 || pointer->compare(first, "EAST") == 0 || pointer->compare(first, "e") == 0){
		player->MovePosition(this, EAST);
	}

	//South
	if (pointer->compare(first, "south") == 0 || pointer->compare(first, "South") == 0 || pointer->compare(first, "SOUTH") == 0 || pointer->compare(first, "s") == 0){
		player->MovePosition(this, SOUTH);
	}
	//West
	if (pointer->compare(first, "west") == 0 || pointer->compare(first, "West") == 0 || pointer->compare(first, "WEST") == 0 || pointer->compare(first, "w") == 0){
		player->MovePosition(this, WEST);
	}
	//North
	if (pointer->compare(first, "north") == 0 || pointer->compare(first, "North") == 0 || pointer->compare(first, "NORTH") == 0 || pointer->compare(first, "n") == 0){
		player->MovePosition(this, NORTH);

	}
	//Command Look:
	else if (pointer->compare(first, "look") == 0 || pointer->compare(first, "Look") == 0 || pointer->compare(first, "LOOK") == 0 || pointer->compare(first, "l") == 0){
		if (pointer->compare(second, "void") == 0){//if the player only writes Look, the programm asks the direction and puts it in second
			printf("Where?\n");
			gets_s(second);
		}
		//East:
		if (pointer->compare(second, "east") == 0 || pointer->compare(second, "East") == 0 || pointer->compare(second, "EAST") == 0 || pointer->compare(second, "e") == 0){
			player->Look(this, EAST);
		}

		//South
		if (pointer->compare(second, "south") == 0 || pointer->compare(second, "South") == 0 || pointer->compare(second, "SOUTH") == 0 || pointer->compare(second, "s")){
			player->Look(this, SOUTH);
		}
		//West
		if (pointer->compare(second, "west") == 0 || pointer->compare(second, "West") == 0 || pointer->compare(second, "WEST") == 0 || pointer->compare(second, "w") == 0){
			player->Look(this, WEST);
		}
		//North
		if (pointer->compare(second, "north") == 0 || pointer->compare(second, "North") == 0 || pointer->compare(second, "NORTH") == 0 || pointer->compare(second, "n") == 0){
			player->Look(this, NORTH);

		}
		if (pointer->compare(second, "room") == 0 || pointer->compare(second, "Room") == 0 || pointer->compare(second, "ROOM") == 0 || pointer->compare(second, "r") == 0){
			player->LookRoom();

		}
	}
	//Command help to explain how all the commands work
	else if (pointer->compare(first, "help") == 0 || pointer->compare(first, "Help") == 0 || pointer->compare(first, "HELP") == 0 || pointer->compare(first, "h") == 0){
		printf("TO MOVE THROUGH THE ROOMS USE THE COMAND GO, go, Go, 'g' PLUS THE DIRECTION YOU WANT (NORTH, north,North, 'n', SOUTH, south, South,'s', EAST, east, East,'e', WEST,west, West, 'w').YOU CAN ALSO MOVE BY ONLY WRITING (NORTH, north,North, 'n', SOUTH, south, South,'s', EAST, east, East,'e', WEST,west, West, 'w').TOO LOOK ALL THE POSIBLE EXITS USE THE COMMAND LOOK, look, Look, 'l' PLUS THE  DIRECTION YOU WANT.\nUSE THE COMPAND OPEN/CLOSE, open/close, Open/close, 'o'/'c' TO OPEN/CLOSE DOORS. IF YOU WANT TO EXIT WRITE QUIT, 'q'.\n ");
	}

	//Commands to open/close the doors:
	//OPEN:
	else if (pointer->compare(first, "open") == 0 || pointer->compare(first, "Open") == 0 || pointer->compare(first, "OPEN") == 0 || pointer->compare(first, "o") == 0){
		if (pointer->compare(second, "void") == 0){
			printf("Where?\n");//if the player only writes Open, the programm asks the direction and puts it in second
			gets_s(second);
		}
		//East:
		if (pointer->compare(second, "east") == 0 || pointer->compare(second, "East") == 0 || pointer->compare(second, "EAST") == 0 || pointer->compare(second, "e") == 0){
			player->OpenDoor(this, EAST);
		}

		//South
		if (pointer->compare(second, "south") == 0 || pointer->compare(second, "South") == 0 || pointer->compare(second, "SOUTH") == 0 || pointer->compare(second, "s")){
			player->OpenDoor(this, SOUTH);
		}
		//West
		if (pointer->compare(second, "west") == 0 || pointer->compare(second, "West") == 0 || pointer->compare(second, "WEST") == 0 || pointer->compare(second, "w") == 0){
			player->OpenDoor(this, WEST);
		}
		//North
		if (pointer->compare(second, "north") == 0 || pointer->compare(second, "North") == 0 || pointer->compare(second, "NORTH") == 0 || pointer->compare(second, "n") == 0){
			player->OpenDoor(this, NORTH);
		}
	}
	//CLOSE:
	else if (pointer->compare(first, "close") == 0 || pointer->compare(first, "Close") == 0 || pointer->compare(first, "CLOSE") == 0 || pointer->compare(first, "c") == 0){
		if (pointer->compare(second, "void") == 0){
			printf("Where?\n");//if the player only writes Close, the programm asks the direction and puts it in second
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
	//COMMAND TAKE ITEM
	else if (pointer->compare(first, "take") == 0 || pointer->compare(first, "Take") == 0 || pointer->compare(first, "TAKE") == 0 || pointer->compare(first, "t") == 0){
		if (pointer->compare(second, "void") == 0){
			printf("What?\n");//if the player only writes Close, the programm asks the direction and puts it in second
			gets_s(second);
		}
		if (pointer->compare(second, "Folder") == 0 || pointer->compare(second, "folder") == 0 || pointer->compare(second, "FOLDER") == 0 || pointer->compare(second, "f") == 0){
			player->TakeItem(this, "Folder");
		}
		if (pointer->compare(second, "Candy") == 0 || pointer->compare(second, "Candy") == 0 || pointer->compare(second, "CANDY") == 0 || pointer->compare(second, "c") == 0){
			player->TakeItem(this, "Candy");
		}
		if (pointer->compare(second, "Kleenex") == 0 || pointer->compare(second, "kleenex") == 0 || pointer->compare(second, "KLEENEX") == 0 || pointer->compare(second, "k") == 0){
			player->TakeItem(this, "Kleenex");
		}
		if (pointer->compare(second, "Camera") == 0 || pointer->compare(second, "camera") == 0 || pointer->compare(second, "CAMERA") == 0 || pointer->compare(second, "C") == 0){
			player->TakeItem(this, "Kleenex");
		}
		//COMMAND DROP ITEM
		/*else if (pointer->compare(first, "drop") == 0 || pointer->compare(first, "Drop") == 0 || pointer->compare(first, "DROP") == 0 || pointer->compare(first, "d") == 0){
			if (pointer->compare(second, "void") == 0){
			printf("What?\n");//if the player only writes Close, the programm asks the direction and puts it in second
			gets_s(second);
			}
			if (pointer->compare(second, "Folder") == 0 || pointer->compare(second, "folder") == 0 || pointer->compare(second, "FOLDER") == 0 || pointer->compare(second, "f") == 0){
			player->DropeItem(this, "Folder");
			}
			if (pointer->compare(second, "Candy") == 0 || pointer->compare(second, "Candy") == 0 || pointer->compare(second, "CANDY") == 0 || pointer->compare(second, "c") == 0){
			player->DropeItem(this, "Candy");
			}
			if (pointer->compare(second, "Kleenex") == 0 || pointer->compare(second, "kleenex") == 0 || pointer->compare(second, "KLEENEX") == 0 || pointer->compare(second, "k") == 0){
			player->DropeItem(this, "Kleenex");
			}
			if (pointer->compare(second, "Camera") == 0 || pointer->compare(second, "camera") == 0 || pointer->compare(second, "CAMERA") == 0 || pointer->compare(second, "C") == 0){
			player->DropeItem(this, "Kleenex");
			}*/

		player->enter = true;//complets the loop to continue recieving commands
		return true;
	}
}