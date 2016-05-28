#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "World.h"
#include "String.h"
#include "Entity.h"
#include "Vector.h"
#include "Item.h"



World::World(){	
	player = new Player;
}

World::~World(){	
	
}

void World::CreateWorld(){
	Room* entrance;
	
	//NAMES AND DESCRIPTIONS FOR EVERY ROOM 
	roomer.push_back((new Room("Entrance", "You are now in the entrance of the CITM.The's a box on the floor where you can put objects")));//room 0
	roomer.push_back((new Room("Secretary's Room", "You are now in the Secretary's Room. Seems nobody is here.There are some papers about the students on the table.Ther's a folder on the table.Go West to exit the room")));//room 1
	roomer.push_back((new Room("Photography set", "You are now in the Photography set, a big room equiped with a lot of technology.In the center of the set you can see a camera on the floor next to a red\nbackpack.Go East to exit the room")));//room 2
	roomer.push_back((new Room("Floor 1", "You are now in the Floor 1, you can see Dani next to a drinkingfountain.")));//room 3
	roomer.push_back((new Room("Toilets", "You are now in the toilets, the floor is a little wet but the smell is not that bad.There are three toilets and a big mirror.In front of the mirror there's a boy crying.Go South to exit the room")));//room 4
	roomer.push_back((new Room("Art Room", "You are now in the Art Room, you see a lot of tables and a huge amount of pencils.You also see a boy, his name is Pep, he is the bully who has stolen your homework.Go North to exit the room East")));//room 5
	roomer.push_back((new Room("Neg Floor", "You are in the floor -1. It's a little cold.")));//room 6
	roomer.push_back((new Room("Vending Machine", "You are in front of the vending machine, there are a los of snacks, but you don't have money. You are lucky, ther's a Candy on the bottom of the machine. Go East to exit the room")));//room 7
	roomer.push_back((new Room("Dining Room", "You are in the dining room. You can see 3 big tables and two microwaves.On the top of one of them there are some kleenex.There are few people on the last table having lunch.Go West to exit the room")));//room 8
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
	exit.push_back((new Exit("T-F", "You see the whole Floor 1, the sun iluminates all the floor", true, roomer[4], roomer[3], SOUTH)));//Toilet exit to the Floor 1
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
	item.push_back(new Item("box", "A box were you can put objects", roomer[0]));
	item.push_back(new Item("folder", "A folder with all the information of some students", roomer[1]));
	item.push_back(new Item("camera", "A new shinny camera with some stickers", roomer[2]));
	item.push_back(new Item("candy", "Seems somebody loves this candy", roomer[7]));
	item.push_back(new Item("kleenex", "They have a strawberry smell, probably someone needs them", roomer[8]));
	item.push_back(new Item("map", "A map of the University where you can see all the rooms", npc[0]));
	item.push_back(new Item("coin", "Coint that you can use to buy things", npc[2]));
	item.push_back(new Item("KitKat", "A delicious chocolate snack", npc[3]));
	item.push_back(new Item("M&M's", "A delicious chocolate snack", npc[3]));
	item.push_back(new Item("Crunch", "A delicious chocolate snack", npc[3]));

	roomer[0]->drive.push_back(item[0]);
	roomer[1]->drive.push_back(item[1]);
	roomer[2]->drive.push_back(item[2]);
	roomer[7]->drive.push_back(item[3]);
	roomer[8]->drive.push_back(item[4]);

	//ADD NPC:
	npc.push_back(new Npc("Dani", "Dani is your friend", roomer[3]));
	roomer[3]->drive.push_back(npc[0]);
	npc[0]->give.push_back(item[5]);
	npc.push_back(new Npc("Pepe", "Pepe moves arround the CITM all the time, if he catches you, you lost\n", roomer[1]));
	roomer[1]->drive.push_back(npc[1]); // later this Npc will be moving by hiself for the rooms
	npc.push_back(new Npc("boy", "He is a very emotional boy", roomer[4]));
	roomer[4]->drive.push_back(npc[2]);
	npc.push_back(new Npc("machine", "A spending machine where you can buy:\n\t·M&M's\n\t·KitKat\n\t·Crunch", roomer[7]));
	roomer[7]->drive.push_back(npc[3]);
	
	
	


}
//Chequing the commands the playar writes:
bool World::Inpunts(){

	int tmp = 0;
	char second[50];
	char *phrase;
	String string;
	Vector<String*> command;
	gets_s(second);

	string = second;
	if (string == "\0"){
		return true;
	}
	string.Token_ize(command);



	//Copying the first word to first

	//Comand Quit to exit the game
	if (command.buffer[0]->copier() == "Quit" || command.buffer[0]->copier() == "quit" || command.buffer[0]->copier() == "q" || command.buffer[0]->copier() == "QUIT"){
		printf("You exit the game");
		return false;//here we stop the loop and stops execution the function Inputs on main.cpp
	}
	//Command Go:

	else if (command.buffer[0]->copier() == "Go" || command.buffer[0]->copier() == "go" || command.buffer[0]->copier() == "GO" || command.buffer[0]->copier() == "g"){
		if (command.size() == 1){
			printf("\t\tWhere?\n\n");
			gets_s(second);
			command.push_back(new String(second));

		}

		//East:
		if (command.buffer[1]->copier() == "east" || command.buffer[1]->copier() == "East" || command.buffer[1]->copier() == "EAST" || command.buffer[1]->copier() == "e"){
			MovePosition(EAST);
		}

		//South
		else if (command.buffer[1]->copier() == "south" || command.buffer[1]->copier() == "South" || command.buffer[1]->copier() == "SOUTH" || command.buffer[1]->copier() == "s"){
			MovePosition(SOUTH);
		}
		//West
		else if (command.buffer[1]->copier() == "west" || command.buffer[1]->copier() == "West" || command.buffer[1]->copier() == "WEST" || command.buffer[1]->copier() == "w"){
			MovePosition(WEST);
		}
		//North
		else if (command.buffer[1]->copier() == "north" || command.buffer[1]->copier() == "North" || command.buffer[1]->copier() == "NORTH" || command.buffer[1]->copier() == "n"){
			MovePosition(NORTH);

		}
		else{
			printf("\t\tI don't understand, repeat please\n\n");
		}
	}



	//Moving without using the command go:
	else if (command.buffer[0]->copier() == "east" || command.buffer[0]->copier() == "East" || command.buffer[0]->copier() == "EAST" || command.buffer[0]->copier() == "e"){
		MovePosition(EAST);
	}

	//South
	else if (command.buffer[0]->copier() == "south" || command.buffer[0]->copier() == "South" || command.buffer[0]->copier() == "SOUTH" || command.buffer[0]->copier() == "S"){
		MovePosition(SOUTH);
	}
	//West
	else if (command.buffer[0]->copier() == "west" || command.buffer[0]->copier() == "West" || command.buffer[0]->copier() == "WEST" || command.buffer[0]->copier() == "w"){
		MovePosition(WEST);
	}
	//North
	else if (command.buffer[0]->copier() == "north" || command.buffer[0]->copier() == "North" || command.buffer[0]->copier() == "NORTH" || command.buffer[0]->copier() == "n"){
		MovePosition(NORTH);

	}
	//Command Look:
	else if (command.buffer[0]->copier() == "Look" || command.buffer[0]->copier() == "look" || command.buffer[0]->copier() == "LOOK" || command.buffer[0]->copier() == "l"){
		if (command.size() == 1){
			printf("\t\tWhere?\n\n");
			gets_s(second);
			command.push_back(new String(second));

		}

		//East:
		if (command.buffer[1]->copier() == "east" || command.buffer[1]->copier() == "East" || command.buffer[1]->copier() == "EAST" || command.buffer[1]->copier() == "e"){
			Look(EAST);
		}

		//South
		else if (command.buffer[1]->copier() == "south" || command.buffer[1]->copier() == "South" || command.buffer[1]->copier() == "SOUTH" || command.buffer[1]->copier() == "s"){
			Look(SOUTH);
		}
		//West
		else if (command.buffer[1]->copier() == "west" || command.buffer[1]->copier() == "West" || command.buffer[1]->copier() == "WEST" || command.buffer[1]->copier() == "w"){
			Look(WEST);
		}
		//North
		else if (command.buffer[1]->copier() == "north" || command.buffer[1]->copier() == "North" || command.buffer[1]->copier() == "NORTH" || command.buffer[1]->copier() == "n"){
			Look(NORTH);

		}
		else if (command.buffer[1]->copier() == "room" || command.buffer[1]->copier() == "Room" || command.buffer[1]->copier() == "ROOM" || command[1]->buffer == "r"){
			LookRoom();

		}
		else{
			printf("\t\tI don't understand, repeat please\n\n");
		}
	}


	//Command help to explain how all the commands work
	else if (command.buffer[0]->copier() == "help" || command.buffer[0]->copier() == "Help" || command.buffer[0]->copier() == "HELP" || command.buffer[0]->copier() == "h"){
		printf("TO MOVE THROUGH THE ROOMS USE THE COMAND GO, go, Go, 'g' PLUS THE DIRECTION YOU WANT (NORTH, north,North, 'n', SOUTH, south, South,'s', EAST, east, East,'e', WEST,west, West, 'w').YOU CAN ALSO MOVE BY ONLY WRITING (NORTH, north,North, 'n', SOUTH, south, South,'s', EAST, east, East,'e', WEST,west, West, 'w').TOO LOOK ALL THE POSIBLE EXITS USE THE COMMAND LOOK, look, Look, 'l' PLUS THE  DIRECTION YOU WANT.\nUSE THE COMPAND OPEN/CLOSE, open/close, Open/close, 'o'/'c' TO OPEN/CLOSE DOORS. IF YOU WANT TO EXIT WRITE QUIT, 'q'.\n\n\n");
	}

	//Commands to open/close the doors:
	//OPEN:
	else if (command.buffer[0]->copier() == "Open" || command.buffer[0]->copier() == "open" || command.buffer[0]->copier() == "OPEN" || command.buffer[0]->copier() == "o"){
		if (command.size() == 1){
			printf("\t\tWhere?\n\n");
			gets_s(second);
			command.push_back(new String(second));

		}

		//East:
		if (command.buffer[1]->copier() == "east" || command.buffer[1]->copier() == "East" || command.buffer[1]->copier() == "EAST" || command.buffer[1]->copier() == "e"){
			OpenDoor(EAST);
		}

		//South
		else if (command.buffer[1]->copier() == "south" || command.buffer[1]->copier() == "South" || command.buffer[1]->copier() == "SOUTH" || command.buffer[1]->copier() == "S"){
			OpenDoor(SOUTH);
		}
		//West
		else if (command.buffer[1]->copier() == "west" || command.buffer[1]->copier() == "West" || command.buffer[1]->copier() == "WEST" || command.buffer[1]->copier() == "w"){
			OpenDoor(WEST);
		}
		//North
		else if (command.buffer[1]->copier() == "north" || command.buffer[1]->copier() == "North" || command.buffer[1]->copier() == "NORTH" || command.buffer[1]->copier() == "n"){
			OpenDoor(NORTH);

		}
		else{
			printf("\t\tI don't understand, repeat please\n\n");
		}

	}

	//CLOSE:
	else if (command.buffer[0]->copier() == "Close" || command.buffer[0]->copier() == "close" || command.buffer[0]->copier() == "CLOSE" || command.buffer[0]->copier() == "c"){
		if (command.size() == 1){
			printf("\t\tWhere?\n\n");
			gets_s(second);
			command.push_back(new String(second));

		}

		//East:
		if (command.buffer[1]->copier() == "east" || command.buffer[1]->copier() == "East" || command.buffer[1]->copier() == "EAST" || command.buffer[1]->copier() == "e"){
			CloseDoor(EAST);
		}

		//South
		else if (command.buffer[1]->copier() == "south" || command.buffer[1]->copier() == "South" || command.buffer[1]->copier() == "SOUTH" || command.buffer[1]->copier() == "S"){
			CloseDoor(SOUTH);
		}
		//West
		else if (command.buffer[1]->copier() == "west" || command.buffer[1]->copier() == "West" || command.buffer[1]->copier() == "WEST" || command.buffer[1]->copier() == "w"){
			CloseDoor(WEST);
		}
		//North
		else if (command.buffer[1]->copier() == "north" || command.buffer[1]->copier() == "North" || command.buffer[1]->copier() == "NORTH" || command.buffer[1]->copier() == "n"){
			CloseDoor(NORTH);

		}
		else{
			printf("\t\tI don't understand, repeat please\n\n");
		}

	}

	//COMMAND PICK ITEM
	else if (command.buffer[0]->copier() == "Pick" || command.buffer[0]->copier() == "pick" || command.buffer[0]->copier() == "PICK" || command.buffer[0]->copier() == "p"){
		if (command.size() == 1){
			printf("\t\tWhat?\n\n");
			gets_s(second);
			command.push_back(new String(second));

		}

		//East:
		if (command.buffer[1]->copier() == "Folder" || command.buffer[1]->copier() == "folder" || command.buffer[1]->copier() == "FOLDER" || command.buffer[1]->copier() == "f"){

			PickItem(String("folder"));
		}

		//South
		else if (command.buffer[1]->copier() == "camera" || command.buffer[1]->copier() == "Camera" || command.buffer[1]->copier() == "CAMERA" || command.buffer[1]->copier() == "cam"){
			PickItem(command.buffer[1]->copier());
		}
		//West
		else if (command.buffer[1]->copier() == "kleenex" || command.buffer[1]->copier() == "Kleenex" || command.buffer[1]->copier() == "KLEENEX" || command.buffer[1]->copier() == "k"){
			PickItem(command.buffer[1]->copier());
		}
		//North
		else if (command.buffer[1]->copier() == "candy" || command.buffer[1]->copier() == "Candy" || command.buffer[1]->copier() == "CANDY" || command.buffer[1]->copier() == "c"){
			PickItem(command.buffer[1]->copier());

		}
		else{
			printf("This item doesn't exists\n\n");
		}

	}
	//DROP
	else if (command.buffer[0]->copier() == "Drop" || command.buffer[0]->copier() == "drop" || command.buffer[0]->copier() == "DROP" || command.buffer[0]->copier() == "d"){
		if (command.size() == 1){
			printf("\t\tWhat?\n\n");
			gets_s(second);
			command.push_back(new String(second));

		}

		//East:
		if (command.buffer[1]->copier() == "Folder" || command.buffer[1]->copier() == "folder" || command.buffer[1]->copier() == "FOLDER" || command.buffer[1]->copier() == "f"){
			DropItem(command.buffer[1]->copier());
		}

		//South
		else if (command.buffer[1]->copier() == "camera" || command.buffer[1]->copier() == "Camera" || command.buffer[1]->copier() == "CAMERA" || command.buffer[1]->copier() == "cam"){
			DropItem(command.buffer[1]->copier());
		}
		//West
		else if (command.buffer[1]->copier() == "kleenex" || command.buffer[1]->copier() == "Kleenex" || command.buffer[1]->copier() == "KLEENEX" || command.buffer[1]->copier() == "k"){
			DropItem(command.buffer[1]->copier());
		}
		//North
		else if (command.buffer[1]->copier() == "candy" || command.buffer[1]->copier() == "Candy" || command.buffer[1]->copier() == "CANDY" || command.buffer[1]->copier() == "c"){
			DropItem(command.buffer[1]->copier());

		}
		else{
			printf("\t\tThis item doesn't exists\n\n");
		}

	}
	//inventory
	else if (command.buffer[0]->copier() == "item" || command.buffer[0]->copier() == "i"){
		player->Inventory();
	}
	//put
	else if ((command.buffer[0]->copier() == "put" || command.buffer[0]->copier() == "Put" || command.buffer[0]->copier() == "PUT" || command.buffer[0]->copier() == "p") && (command.buffer[2]->copier() == "in" || command.buffer[2]->copier() == "In") && (command.buffer[3]->copier() == "box")){
		PutItem(command.buffer[1]->copier());
	}
	else if ((command.buffer[0]->copier() == "Get" || command.buffer[0]->copier() == "get") && (command.buffer[2]->copier() == "from") && (command.buffer[3]->copier() == "box")){
		GetItem(command.buffer[1]->copier());
	}
	//Stats:
	else if (command.buffer[0]->copier() == "stats"){
		printf("Attack: 100\n Life: 300\n");
	}

	//Npc descriptions:
	else if (command.buffer[0]->copier() == "description" || command.buffer[0]->copier() == "Description"){
		if (command.size() == 1){
			printf("\t\tWhich npc?\n\n");
			gets_s(second);
			command.push_back(new String(second));

		}
		if (command.buffer[1]->copier() == "Dani"){
			Description(command.buffer[1]->copier());
		}
		else if (command.buffer[1]->copier() == "boy"){
			Description(command.buffer[1]->copier());
		}
		else{
			printf("\t\tThis npc doesn't exists\n\n");
		}
		//MAP CHECKING
	}
	else if (command.buffer[0]->copier() == "m" || command.buffer[0]->copier() == "map"){
		for (int i = 0; i < player->trans.size(); i++){
			if (player->trans[i]->name == "map"){
				Map();
				break;
			}
		}
		printf("You don't have the map\n\n");
	}

	//FUNCTION TALK
	else if (command.buffer[0]->copier() == "talk" || command.buffer[0]->copier() == "Talk"){
		int tmp = 0;
		if (command.size() == 1){
			printf("\t\tWith who?\n\n");
			gets_s(second);
			command.push_back(new String(second));
		}
		if (player->trans.size() == 0){//if player hasn't any item, he would be able to talk to Dani to recieve the map
			if (command.buffer[1]->copier() == "Dani"){
				if (player->position == npc[0]->location){
					talk(command.buffer[1]->copier());
				}
				else{
					printf("This Npc is not in this Room\n");
				}
			}
			else if (command.buffer[1]->copier() == "boy"){
				if (player->position == npc[2]->location){
					talk(command.buffer[1]->copier());
				}
				else{
					printf("This Npc is not in this Room\n");
				}
			}
		}
		else if (player->trans.size() != 0){//if the player has some items in the inventory			
			for (int i = 0; i < player->trans.size(); i++){
				if (command.buffer[1]->copier() == "Dani"){//we check with who is he talking
					if (player->position == npc[0]->location){
						if (player->trans[i]->name == "map"){//we check if he has the map already
							talkidle(command.buffer[1]->copier());
							tmp = 1;
							break;
						}
					}
					else{
						printf("This Npc is not in this Room\n");
					}
				}
				else if (command.buffer[1]->copier() == "boy"){//we check with who is he talking
					if (player->position == npc[2]->location){
						if (player->trans[i]->name == "coin"){//we check if he has the map already
							talkidle(command.buffer[1]->copier());
							tmp = 1;
							break;
						}
						else if (player->trans[i]->name == "camera"){//we check if he has the map already
							talkidle2(command.buffer[1]->copier());
							tmp = 1;
							break;
						}
					}

					else{
						printf("This Npc is not in this Room\n");
					}

				}
				else{
					printf("This Npc doesn't exists\n");
					break;
				}
			}

			if (tmp == 0){
				if (command.buffer[1]->copier() == "Dani"){
					if (player->position == npc[0]->location){
						talk(command.buffer[1]->copier());
					}
				}
				else if (command.buffer[1]->copier() == "boy"){
					if (player->position == npc[2]->location){
						talk(command.buffer[1]->copier());
					}
				}
			}

		}

	}

	//Buy Npc:
	else if (command.buffer[0]->copier() == "buy" || command.buffer[0]->copier() == "buy"){
		if (command.size() == 1){
			printf("\t\tWhich npc?\n\n");
			gets_s(second);
			command.push_back(new String(second));

		}
		if (command.buffer[1]->copier() == "machine"){
			if (player->position == npc[3]->location){
				buy(command.buffer[1]->copier());
			}
			printf("This Npc is not here\n");
		}
	}




		player->enter = true;//complets the loop to continue recieving commands
		return true;
	}

	void World::MovePosition(dir direction){
		int tmp = 0;
		if (player->enter == true){
			for (int i = 0; i < 18; i++){
				if (exit[i]->origin == player->position){//Checking if the position of the player is the same of the exit origin
					if (exit[i]->direction == direction){//Checking if the direction iss the same of the exit direction
						if (exit[i]->open == true){//Checking if the door to enter the room is closed
							player->position = exit[i]->destination;//Now the player position is the destination of the exit
							printf("\t\t\t\t%s\n%s\n\n", exit[i]->destination->name.c_str(), exit[i]->destination->description.c_str());
							player->enter = false;
							tmp = 1;
							break;
						}
						else{
							printf("\t\t\tThe door is closed!\n\n");
							tmp = 1;
							break;
						}
					}

				}

			}
			if (tmp == 0){
				printf("\t\t\tThere's nothing there\n\n");
			}
		}
	}

	void World::Look(dir watch){
		int tmp = 0;
		if (player->enter == true){
			for (int i = 0; i < 18; i++){
				if (exit[i]->origin == player->position){//Checking if the position of the player is the same of the exit origin
					if (exit[i]->direction == watch){//Checking if the direction iss the same of the exit direction
						printf("%s\n\n", exit[i]->description.c_str());
						player->enter = false;
						tmp = 1;
						break;
					}

				}

			}
			if (tmp == 0){
				printf("\t\t\tThere's nothing there\n\n");
			}
		}
	}



	void World::LookRoom(){
		printf("\t\t\t\t%s\n%s\n\n", player->position->name.c_str(), player->position->description.c_str());
	}

	void World::OpenDoor(dir door){
		if (player->enter == true){
			for (int i = 0; i < 18; i++){
				if (exit[i]->origin == player->position){//Checking if the position of the player is the same of the exit origin
					if (exit[i]->direction == door){//Checking if the direction iss the same of the exit direction
						if (exit[i]->open == false){//Checking if the door to enter the room is closed
							printf("\t\t\tThe door is oppened\n\n");
							exit[i]->open = true;
							player->enter = false;
							break;
						}
					}
				}
			}
		}
	}
	void World::CloseDoor(dir door){
		if (player->enter == true){
			for (int i = 0; i < 18; i++){
				if (exit[i]->origin == player->position){//Checking if the position of the player is the same of the exit origin
					if (exit[i]->direction == door){//Checking if the direction iss the same of the exit direction
						if (exit[i]->open == true){//Checking if the door to enter the room is opened
							printf("\t\t\tYou closed the door\n\n");
							exit[i]->open = false;
							player->enter = false;
							break;
						}
					}
				}
			}
		}
	}

	void World::PickItem(String name){
		int tmp = 0;
		if (player->position->drive.size() < 5){
			for (int j = 0; j < item.size(); j++){
				if ((item[j]->localitzation) == (player->position)){
					if (name == item[j]->name.copier()){
						printf("\t\t\tYou picked the %s\n\n", item[j]->name.c_str());
						tmp = 1;
						player->trans.push_back(item[j]);
						player->position->drive.cleaner(j);
						item[j]->localitzation = nullptr;
						return;
					}
				}
			}




			printf("\t\t\tThis object is not here\n\n");
		}
	}








	void World::DropItem(const String name){
		int tmp = 0;
		for (int j = 0; j < 5; j++)	{
			if (item[j]->name == name){
				printf("\t\t\tYou Droped the %s\n\n", item[j]->name.c_str());
				item[j]->localitzation = player->position;
				player->position->drive.push_back(item[j]);
				player->trans.cleaner(j);

			}

		}
		if (tmp != 0)
			printf("\t\t\tThis object is not here\n\n");
	}
	void World::PutItem(const String items){
		if (player->position == roomer[0]){
			if (player->trans.size() > 0){
				for (unsigned int i = 0; player->trans.size() > i; i++)
				{
					if (items == player->trans[i]->name){
						item[0]->transp.push_back(player->trans[i]);
						printf("\t\tYou put the %s inside the box\n\n", player->trans[i]->name.c_str());
						player->trans.cleaner(i);
						return;
					}
				}
				printf("\t\tYou don't have that item in the box.\n\n");
			}
			else{
				printf("\t\t\tYour box is empty\n\n");
			}
		}
	}
	void World::GetItem(const String items){
		if (player->position == roomer[0]){
			if (player->trans.size() < 5){//inventory size
				for(unsigned int i = 0; item[0]->transp.size() > i; i++)
				{
					if (items == item[0]->transp[i]->name){
						player->trans.push_back(item[0]->transp[i]);
						printf("\t\tYou got the %s from the box\n\n", item[0]->transp[i]->name.c_str());
						item[0]->transp.cleaner(i);
						return;
					}
				}
				printf("\t\t\tThis object is not here\n\n");
			}
			else{
				printf("\t\tYou have too much stuff in your inventory\n\n");
			}
		}

	}
	void World::Description(const String name)const{
		int tmp = 0;
		for (int j = 0; j < 2; j++){
			if (npc[j]->name == name){
				if (player->position == npc[j]->location){
					printf("\t\t\tName:%s\n        \t\tDescription: %s\n\n", npc[j]->name.c_str(), npc[j]->description.c_str());
					tmp = 1;
					return;
				}
				printf("\t\t\tThis npc is not in this room\n\n");
				tmp = 1;
				break;
			}


		}
		if (tmp == 0){
			printf("\t\t\tThis npc doesn't exist\n\n");
		}

	}

	//SPECIAL FEATURE MAP
	void World::Map()const{

		char map[20][40]{

			{' ', '_', '_', '_', '_', '_', '_', '_', 'M', 'A', 'P', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', 'M', 'A', 'P', '_', '_', '_', '_', '_', '_', '_', '_', ' '},
			{ '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
			{ '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '_', '_', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '^', ' ', '_', '_', '_', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'C', 'I', 'T', 'M', ' ', ' ', '|' },
			{ '|', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|', 'S', 'T', 'A', 'I', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
			{ '|', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', 'W', 'C', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|', '_', 'R', 'S', '_', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
			{ '|', ' ', '_', '_', '_', '_', '_', '|', '_', '_', '_', '_', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '|', '_', '_', '_', '_', '|', '_', '_', '_', '_', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
			{ '|', '|', ' ', 'A', 'R', 'T', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '_', '|', '_', ' ', ' ', ' ', ' ', ' ', '|', 'D', 'I', 'N', 'I', 'N', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
			{ '|', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', 'F', '1', ' ', '|', ' ', ' ', ' ', ' ', '|', '_', '|', '_', '|', 'F', '-', '1', ' ', '|', 'G', 'R', 'O', 'O', 'M', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
			{ '|', '|', '-', '-', '_', '-', '-', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', '_', '|', '_', '|', ' ', ' ', ' ', ' ', '|', ' ', '_', '_', '_', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
			{ '|', '|', '_', '_', '_', '_', '_', '|', '_', '_', '_', '_', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|', '_', '_', '_', '_', '_', '_', '|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
			{ '|', ' ', ' ', ' ', ' ', ' ', ' ', '|', 'S', 'T', 'A', 'I', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', 'P', 'R', 'O', 'G', '|', '_', '_', '_', '_', '_', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
			{ '|', ' ', ' ', ' ', ' ', ' ', ' ', '|', '_', 'R', 'S', '_', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', 'R', 'A', 'M', 'M', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
			{ '|', ' ', '_', '_', '_', '_', '_', '|', '_', '_', '_', '_', '|', '_', '_', '_', '_', '_', '_', ' ', ' ', '|', 'I', 'N', 'G', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
			{ '|', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', 'S', 'E', 'C', 'R', 'E', '|', ' ', '|', '_', '_', '_', '_', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
			{ '|', '|', ' ', 'S', 'E', 'T', ' ', '|', ' ', 'F', '0', ' ', '|', ' ', 'T', 'A', 'R', 'Y', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'N', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
			{ '|', '|', '_', '_', '_', '_', '_', '|', '_', '_', '_', '_', '|', '_', '_', '_', '_', '_', '_', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
			{ '|', ' ', ' ', ' ', ' ', ' ', ' ', '|', 'S', 'T', 'A', 'I', '|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W', '-', '-', '|', '-', '-', 'E', ' ', ' ', ' ', ' ', '|' },
			{ '|', ' ', ' ', ' ', ' ', ' ', ' ', '|', '_', 'R', 'S', '_', '|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
			{ '|', ' ', ' ', ' ', ' ', ' ', ' ', '|', '_', '_', '_', '_', '|', 'V', ' ', ' ', ' ', '*', 'P', 'O', 'S', 'I', 'T', 'I', 'O', 'N', ' ', ' ', ' ', ' ', ' ', 'S', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
			{ '|', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '|' }
		};

		if (player->position == roomer[0]){//f0
			map[14][11] = '*';
		}
		else if (player->position == roomer[1]){//secretary
			map[14][18] = '*';
		}
		else if (player->position == roomer[2]){//set
			map[14][6] = '*';
		}
		else if (player->position == roomer[3]){//f1
			map[7][11] = '*';
		}
		else if (player->position == roomer[4]){//toilets
			map[4][11] = '*';
		}
		else if (player->position == roomer[5]){//art
			map[7][4] = '*';
		}
		else if (player->position == roomer[6]){//f-1
			map[7][25] = '*';
		}
		else if (player->position == roomer[7]){//VendingMachine
			map[7][20] = '*';
		}
		else if (player->position == roomer[8]){//Dining
			map[9][29] = '*';
		}
		else if (player->position == roomer[9]){//Programming
			map[12][25] = '*';
		}

		system("cls");
		for (int i = 0; i < 20; i++){
			for (int j = 0; j < 40; j++){
				printf("%c", map[i][j]);
			}
			printf("\n");

		}
		printf("\n");


	}

	
	
	void World::talk(const String names)const{
		int options = 0, option2 = 0, option3 = 0, option4 = 0;
		if (names=="Dani"){
				printf("\t\tDani:Hello Marc, how are you?\n\n");
				printf("\t\tYou: 1- Not really well, someone has stolen my homework...\n\t\t2-Good, what are you doing here Dani?\n\n");
				scanf_s("%i", &options);

				switch (options){

				case 1:						
						printf("\t\tDani: Oh, what a bad notice, i think i have something that can help you...\n\n");
						printf("\t\tYou:1-Really? and what is this thing?\n\n");
						scanf_s("%i", &option2);
						if (option2 != 1){
							printf("I don't understand start again\n");
							scanf_s("%i", &option2); 
						}
						else if (option2 == 1){
							printf("\t\tDani: It's a map of the University. With the map you will be able to see all the rooms. Take it\n\n");
							printf("\t\t\t***You recieved a map***\n\n");
							player->trans.push_back(item[5]);
							npc[0]->give.cleaner(5);							
						}					
						break;
				case 2:
					printf("\t\tDani: I had a meeting with my tutor. And what about you? clases finished 3 hours ago...\n");
					printf("\t\tYou:1-Okay I will tell you, someone has stolen my homework and i can't find him\n");
					scanf_s("%i", &option2);
					printf("\t\tDani: Oh, what a bad notice, i think i have something that can help you...\n\n");
					printf("\t\tYou:1-Really? and what is this thing?\n\n");
					scanf_s("%i", &option2);
					if (option2 != 1){
						printf("I don't understand start again\n");
						scanf_s("%i", &option2);
					}
					else if (option2 == 1){
						printf("\t\tDani: It's a map of the University. With the map you will be able to see all the rooms. Take it\n\n");
						printf("\t\t\t***You recieved a map***\n\n");
						player->trans.push_back(item[5]);
						npc[0]->give.cleaner(5);
					}
						
					break;
				default:
					printf("I don't understand, start again\n");
					break;
				}
				

			}
		else if (names == "boy"){
			printf("\t\tBoy: Oh, hello Marc...snif\n ");
			printf("\t\tYou: 1-Why are you crying?\n\n");
			scanf_s("%i", &options);
			switch (options){

			case 1:
				printf("\t\tBoy:Yesterday i bought i new camera and now i have lost it...snif\n\n");
				printf("\t\tYou:1-Don't worry boy, sure it's here in the CITM, you will find it don't cry anymore\n\n");
				scanf_s("%i", &option2);
				if (option2 != 1){
					printf("I don't understand start again\n");
					scanf_s("%i", &option2);
				}
				else if (option2 == 1){
					printf("\t\tBoy: Please Marc, can you find it for me please?\n\n");
					printf("\t\tYou: 1-I have more important problems to solve than looking for a camera.\n     2-Okey, do you remember when you use it the last time?\n");
					scanf_s("%i", &option3);
					if (option3 == 1){
						printf("\t\tBoy: Pleasee...snif, i need it, i will give you 1 coin\n\n");
						printf("You:1- Mmmm, okey I will do it, do you remember when you use it the last time?\n\n");
						scanf_s("%i", &option4);
						printf("\t\tBoy: Oh...snif, thanks Marc..snif\n\n");					
					}
					else if (option3 == 2){
						printf("\t\tBoy: Oh...snif, thanks Marc..snif\n\n");
						break;					
					}
					

				}
			}
		}
			
		
	}
	void World::talkidle(const String names)const{

		if (names == "Dani"){
			printf("Good luck on your way to find your homework\n\n");
		}
		if (names == "boy"){
			printf("\t\tThanks Marc!\n\n");
		}
	}
	void World::talkidle2(const String names)const{
		printf("\t\tBoy:Really thenks Marc, my cameraa...snif\n\n");
		printf("\t\tHere you have\n\t\t\t**You Recieved a coin**\n\n");
		player->trans.push_back(item[6]);
		npc[2]->give.cleaner(0);
		for (int i = 0; i < player->trans.size(); i++){
			if (player->trans[i]->name == "camera"){
				player->trans.cleaner(i);
			}

		}
		
		

	}
	void World::buy(const String names)const{
		int option = 0;
		if (names == "machine"){
			printf("\t\tAll products cost 1 coin\n\t\t1KitKat\n\t\t2M&M's\n\t\t3Crunch\n\t\tChoose what do you whant\n");
			scanf_s("%i", &option);
			for (int i = 0; i < player->trans.size(); i++){
				if (player->trans[i]->name == "coin"){
					switch (option){

					case 1:
						printf("\t\t\t\t**You Recieved a KitKat\n\n");
						player->trans.push_back(item[7]);
						break;
					case 2:
						printf("\t\t\t\t**You Recieved M&M's\n\n");
						player->trans.push_back(item[8]);
						break;
					case 3:
						printf("\t\t\t\t**You Recieved a Crunch\n\n");
						player->trans.push_back(item[9]);
						break;

					}

				}
			}
			printf("You don't have enough coins to buy this\n");

		}
	
	
	}


	



	