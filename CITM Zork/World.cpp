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
	item.push_back(new Item("folder", "A folder with all the information of some students", roomer[1]));
	item.push_back(new Item("camera", "A new shinny camera with some stickers", roomer[2]));
	item.push_back(new Item("candy", "Seems somebody loves this candy", roomer[7]));
	item.push_back(new Item("kleenex", "They have a strawberry smell, probably someone needs them", roomer[8]));

	roomer[1]->drive.push_back(item[0]);
	roomer[2]->drive.push_back(item[1]);
	roomer[7]->drive.push_back(item[2]);
	roomer[8]->drive.push_back(item[3]);
	


}
//Chequing the commands the playar writes:
bool World::Inpunts(String& command){
	
		
	char second[30];
	char *phrase;
	String command2;
	
	if (command=="\0"){
		return true;
	}

	//Copying the first word to first
	
	//Comand Quit to exit the game
	if (command=="Quit" ||command=="quit"|| command== "q"||command =="QUIT"){
		printf("You exit the game");
		return false;//here we stop the loop and stops execution the function Inputs on main.cpp
	}
	//Command Go:
	else if (command == "go east" || command == "go e"){
		MovePosition(EAST);
	}
	else if (command == "go south" || command == "go s"){
		MovePosition(SOUTH);
	}
	else if (command == "go west" || command == "go w"){
		MovePosition(WEST);
	}
	else if (command == "go north" || command == "go n"){
		MovePosition(NORTH);
	}
	else if (command == "Go" || command == "go" || command == "GO" || command == "g"){
			printf("Where?\n");
			gets_s(second);
			command2 = second;
			//East:
			if (command2 == "east" || command2 == "East" || command2 == "EAST" || command2 == "e"){
				MovePosition( EAST);
			}

			//South
			else if (command2 == "south" || command2 == "South" || command2 == "SOUTH" || command2 == "S"){
				MovePosition( SOUTH);
			}
			//West
			else if (command2 == "west" || command2 == "West" || command2 == "WEST" || command2 == "w"){
				MovePosition( WEST);
			}
			//North
			else if (command2 == "north" || command2 == "North" || command2 == "NORTH" || command2 == "n"){
				MovePosition( NORTH);

			}
		}
	
	

	//Moving without using the command go:
	else if (command == "east" || command == "East" || command == "EAST" || command == "e"){
		MovePosition(EAST);
	}

	//South
	else if (command == "south" || command == "South" || command == "SOUTH" || command == "S"){
		MovePosition(SOUTH);
	}
	//West
	else if (command == "west" || command == "West" || command == "WEST" || command == "w"){
		MovePosition(WEST);
	}
	//North
	else if (command == "north" || command == "North" || command == "NORTH" || command == "n"){
		MovePosition(NORTH);

	}
	//Command Look:
	else if (command == "look east" || command == "look e"){
		Look (EAST);
	}
	else if (command == "look south" || command == "look s"){
		Look(SOUTH);
	}
	else if (command == "look west" || command == "look w"){
		Look(WEST);
	}
	else if (command == "look north" || command == "look n"){
		Look(NORTH);
	}
	else if (command == "look" || command == "Look" || command == "LOOK" || command == "l"){
			printf("Where?\n");
			gets_s(second);
			command2 = second;
			//East:
			if (command2 == "east" || command2 == "East" || command2 == "EAST" || command2 == "e"){
				Look(EAST);
			}

			//South
			else if (command2 == "south" || command2 == "South" || command2 == "SOUTH" || command2 == "S"){
				Look(SOUTH);
			}
			//West
			else if (command2 == "west" || command2 == "West" || command2 == "WEST" || command2 == "w"){
				Look(WEST);
			}
			//North
			else if (command2 == "north" || command2 == "North" || command2 == "NORTH" || command2 == "n"){
				Look(NORTH);

			}
	}
			
	else if (command == "room" || command == "Room" || command == "ROOM" || command == "r"){
				LookRoom();

			}
		
		
	
	//Command help to explain how all the commands work
	else if (command == "help" || command == "Help" || command == "HELP" || command == "h"){
		printf("TO MOVE THROUGH THE ROOMS USE THE COMAND GO, go, Go, 'g' PLUS THE DIRECTION YOU WANT (NORTH, north,North, 'n', SOUTH, south, South,'s', EAST, east, East,'e', WEST,west, West, 'w').YOU CAN ALSO MOVE BY ONLY WRITING (NORTH, north,North, 'n', SOUTH, south, South,'s', EAST, east, East,'e', WEST,west, West, 'w').TOO LOOK ALL THE POSIBLE EXITS USE THE COMMAND LOOK, look, Look, 'l' PLUS THE  DIRECTION YOU WANT.\nUSE THE COMPAND OPEN/CLOSE, open/close, Open/close, 'o'/'c' TO OPEN/CLOSE DOORS. IF YOU WANT TO EXIT WRITE QUIT, 'q'.\n ");
	}

	//Commands to open/close the doors:
	//OPEN:
	else if (command == "open east" || command == "open e"){
		OpenDoor(EAST);
	}
	else if (command == "open south" || command == "open s"){
		OpenDoor(SOUTH);
	}
	else if (command == "open west" || command == "open w"){
		OpenDoor(WEST);
	}
	else if (command == "open north" || command == "open n"){
		OpenDoor(NORTH);
	}
	else if (command == "open" || command == "Open" || command == "OPEN" || command == "o"){
		
			printf("Where?\n");//if the player only writes Open, the programm asks the direction and puts it in second
			gets_s(second);
			command2 = second;
			//East:
			if (command2 == "east" || command2 == "East" || command2 == "EAST" || command2 == "e"){
				OpenDoor( EAST);
			}

			//South
			else if (command2 == "south" || command2 == "South" || command2 == "SOUTH" || command2 == "S"){
				OpenDoor( SOUTH);
			}
			//West
			else if (command2 == "west" || command2 == "West" || command2 == "WEST" || command2 == "w"){
				OpenDoor(WEST);
			}
			//North
			else if (command2 == "north" || command2 == "North" || command2 == "NORTH" || command2 == "n"){
				OpenDoor(NORTH);

			}
		}
		
	
	//CLOSE:
	else if (command == "close east" || command == "close e"){
		CloseDoor(EAST);
	}
	else if (command == "open south" || command == "open s"){
		CloseDoor(SOUTH);
	}
	else if (command == "open west" || command == "open w"){
		CloseDoor(WEST);
	}
	else if (command == "open north" || command == "open n"){
		CloseDoor(NORTH);
	}
	else if (command == "close" || command == "Close" || command == "CLOSE" || command == "c"){

		printf("Where?\n");//if the player only writes Open, the programm asks the direction and puts it in second
		gets_s(second);
		command2 = second;
		//East:
		if (command2 == "east" || command2 == "East" || command2 == "EAST" || command2 == "e"){
			CloseDoor(EAST);
		}

		//South
		else if (command2 == "south" || command2 == "South" || command2 == "SOUTH" || command2 == "S"){
			CloseDoor(SOUTH);
		}
		//West
		else if (command2 == "west" || command2 == "West" || command2 == "WEST" || command2 == "w"){
			CloseDoor( WEST);
		}
		//North
		else if (command2 == "north" || command2 == "North" || command2 == "NORTH" || command2 == "n"){
			CloseDoor( NORTH);

		}
	}
	
	//COMMAND PICK ITEM
	else if (command == "pick folder" || command == "pick f"){
		PickItem(command);
	}
	else if (command == "pick candy" || command == "pick c"){
		PickItem(command);
	}
	else if (command == "pick kleenex" || command == "pick k"){
		PickItem( command);
	}
	else if (command == "pick camera" || command == "pick cam"){
		PickItem( command);
	}
	else if (command == "pick" || command == "Pick" || command == "PICK" || command == "p"){
		printf("What?\n");//if the player only writes Close, the programm asks the direction and puts it in second
		gets_s(second);
		command2 = second;

		if (command2 == "folder" || command2 == "Folder" || command2 == "FOLDER" || command2 == "f"){
			PickItem( command2);
		}
		else if (command2 == "candy" || command2 == "Candy" || command2 == "CANDY" || command2 == "c"){
			PickItem(command2);
		}
		else if (command2 == "kleenex" || command2 == "Kleenex" || command2 == "KLEENEX" || command2 == "k"){
			PickItem(command2);
		}
		else if (command2 == "camera" || command2 == "Camera" || command2 == "CAMERA" || command2 == "cam"){
			PickItem( command2);
		}
	}
	//DROP
	else if (command == "drop folder" || command == "drop f"){
		DropItem( command);
	}
	else if (command == "drop candy" || command == "drop c"){
		DropItem( command);
	}
	else if (command == "drop kleenex" || command == "drop k"){
		DropItem(command);
	}
	else if (command == "drop camera" || command == "drop cam"){
		DropItem( command);
	}

	else if (command == "drop" || command == "Drop" || command == "DROP" || command == "d"){
		printf("What?\n");//if the player only writes Close, the programm asks the direction and puts it in second
		gets_s(second);
		command2 = second;

		if (command2 == "folder" || command2 == "Folder" || command2 == "FOLDER" || command2 == "f"){
			DropItem( command2);
		}
		else if (command2 == "candy" || command2 == "Candy" || command2 == "CANDY" || command2 == "c"){
			DropItem(command2);
		}
		else if (command2 == "kleenex" || command2 == "Kleenex" || command2 == "KLEENEX" || command2 == "k"){
			DropItem(command2);
		}
		else if (command2 == "camera" || command2 == "Camera" || command2 == "CAMERA" || command2 == "cam"){
			DropItem(command2);
		}
	}
	else if (command == "item" || command == "i"){
		player->Inventory();
	}

	

		player->enter = true;//complets the loop to continue recieving commands
		return true;
	}
	void World::MovePosition(dir direction){
		if (player->enter == true){
			for (int i = 0; i < 18; i++){
				if (exit[i]->origin == player->position){//Checking if the position of the player is the same of the exit origin
					if (exit[i]->direction == direction){//Checking if the direction iss the same of the exit direction
						if (exit[i]->open == true){//Checking if the door to enter the room is closed
							player->position = exit[i]->destination;//Now the player position is the destination of the exit
							printf("%s\n%s\n", exit[i]->destination->name.c_str(),exit[i]->destination->description.c_str());
							player->enter = false;
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

	void World::Look(dir watch){
		if (player->enter == true){
			for (int i = 0; i < 18; i++){
				if (exit[i]->origin == player->position){//Checking if the position of the player is the same of the exit origin
					if (exit[i]->direction == watch){//Checking if the direction iss the same of the exit direction
						printf("%s\n",exit[i]->description.c_str());
						player->enter = false;
						break;
					}
				}
			}
		}
	}
	
	

	void World::LookRoom(){
		printf("%s", player->position->name.c_str());
	}

	void World::OpenDoor(dir door){
		if (player->enter == true){
			for (int i = 0; i < 18; i++){
				if (exit[i]->origin == player->position){//Checking if the position of the player is the same of the exit origin
					if (exit[i]->direction == door){//Checking if the direction iss the same of the exit direction
						if (exit[i]->open == false){//Checking if the door to enter the room is closed
							printf("The door is oppened\n");
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
							printf("You closed the door\n");
							exit[i]->open = false;
							player->enter = false;
							break;
						}
					}
				}
			}
		}
	}

	void World::PickItem(String& name)const{
		int tmp=0;
		for (int j = 0; j < 3; j++){
			if ((player->position == item[j]->localitzation) && (item[j]->name == name)){
				printf("You picked the %s", item[j]->name.c_str());
				tmp = 1;
				player->trans.push_back(item[j]);
				player->position->drive.cleaner(j);

			}
		}
		if (tmp!=0)
			printf("This object is not here");
		}
	
	
	void World::DropItem(String& name)const{
			int tmp = 0;
			for (int j = 0; j < 4; j++){
				if (item[j]->name == name){
					printf("You Droped the %s", item[j]->name.c_str());
					item[j]->localitzation =player->position;
					player->position->drive.push_back(item[j]);
					player->trans.cleaner(j);
					
				}

			}
			if (tmp != 0)
				printf("This object is not here");
		}


	