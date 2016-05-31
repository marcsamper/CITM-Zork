#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "World.h"
#include "String.h"
#include "Entity.h"
#include "Vector.h"
#include "Item.h"
#include "time.h"
#include "conio.h"
#include <Windows.h>

#define DELAY 7500
#define COMMANDBUFFER 50



World::World(){	
	player = new Player;
}

World::~World(){	
	
}

void World::CreateWorld(){
	
	
	//NAMES AND DESCRIPTIONS FOR EVERY ROOM 
	entity.push_back((new Room("Entrance", "You are now in the entrance of the CITM.The's a box on the floor where you can put objects")));//room 0
	entity.push_back((new Room("Secretary's Room", "You are now in the Secretary's Room. Seems nobody is here.Ther's a folder on the table.Go West to exit the room")));//room 1
	entity.push_back((new Room("Photography set", "You are now in the Photography set, a big room equiped with a lot of technology.In the center of the set you can see a camera on the floor next to a red\nbackpack.Go East to exit the room")));//room 2
	entity.push_back((new Room("Floor 1", "You are now in the Floor 1, you can see Dani sit on a bank")));//room 3
	entity.push_back((new Room("Toilets", "You are now in the toilets, the floor is a little wet but the smell is not that bad.There are three toilets and a big mirror.In front of the mirror there's a boy crying.Go South to exit the room")));//room 4
	entity.push_back((new Room("Art Room", "You are now in the Art Room, you hear the voice of Pep, the boy who stole your homework, are you sure you want to enter without nothing to give to Pepe?.Go North to exit the room East")));//room 5
	entity.push_back((new Room("Neg Floor", "You are in the floor -1. It's a little cold.")));//room 6
	entity.push_back((new Room("Vending Machine", "You are in front of the vending machine, there are a los of snacks, but you don't have money. You are lucky, ther's a Candy on the bottom of the machine. Go East to exit the room")));//room 7
	entity.push_back((new Room("Dining Room", "You are in the dining room. You can see 3 big tables and two microwaves.On the top of one of them there are some kleenex.There are few people on the last table having lunch.Go West to exit the room")));//room 8
	entity.push_back((new Room("Programming Room", "You have entered teh Programming Room.Go North to exit the room")));//room 9
	
	//SETTING THE PLAYER NAME AND POSITION:
	player->position = (Room*)entity[0];
	
	//SETTING UP EXITS: NAME, DESCRIPTION, ORIGIN, DESTINATION, DIRECTION AND OPEN:
	
	entity.push_back((new Exit("E-S", "You see the Secretary's Room, but nobody is inside", true, (Room*)entity[0], (Room*)entity[1], EAST)));//Entrance exit to Secretary's Room
	entity.push_back((new Exit("S-E", "You see the entrance, there's a lot of silence", true, (Room*)entity[1], (Room*)entity[0], WEST)));//Secretary's Room exit to Entrance
	entity.push_back((new Exit("E-S", "You see the photograpy set, but seems the door is closed", false, (Room*)entity[0], (Room*)entity[2], WEST)));//Entrance exit to Photography set
	entity.push_back((new Exit("P-E", "You see the entrance, there's a lot of silence", true, (Room*)entity[2], (Room*)entity[0], EAST)));//Photography set exit to Entrance
	entity.push_back((new Exit("E-F", "You see the upstairs that go to the floor 1", true, (Room*)entity[0], (Room*)entity[3], NORTH)));//Entrance exit to floor 1 by upstairs
	entity.push_back((new Exit("F-E", "You see the downstairs that go to the entrance", true, (Room*)entity[3], (Room*)entity[0], SOUTH)));//Floor 1 exit to Entrance by Downstairs
	entity.push_back((new Exit("F-T", "You see the toilets, there's a tears trail", true, (Room*)entity[3], (Room*)entity[4], NORTH)));//Floor 1 exit to Toilets
	entity.push_back((new Exit("T-F", "You see the whole Floor 1, the sun iluminates all the floor", true, (Room*)entity[4], (Room*)entity[3], SOUTH)));//Toilet exit to the Floor 1
	entity.push_back((new Exit("F-A", "You see the Art Room, there are some pencils on the entrance", true, (Room*)entity[3], (Room*)entity[5], WEST)));//Floor 1 exit to the art Room
	entity.push_back((new Exit("A-F", "You see the whole Floor 1, the sun iluminates all the floor 1", true, (Room*)entity[5], (Room*)entity[3], EAST)));//Art Room exit to the Floor 1
	entity.push_back((new Exit("E-N", "You see the downstairs that go to the floor -1", true, (Room*)entity[0], (Room*)entity[6], SOUTH)));//Entrance exit to floor -1 by downstairs
	entity.push_back((new Exit("N-E", "You see the upstairs that go to the Entrance", true, (Room*)entity[6], (Room*)entity[0], NORTH)));//Floor -1 exit to the entrance by Upstairs
	entity.push_back((new Exit("N-V", "You see the Vending Machine, it has a lot of snacks", true, (Room*)entity[6], (Room*)entity[7], WEST)));//Floor-1 exit to the Vending Machine:
	entity.push_back((new Exit("V-N", "You can see the whole floor -1, it's a little bit cold", true, (Room*)entity[7], (Room*)entity[6], EAST)));//Vending Machine exit to the Floor -1
	entity.push_back((new Exit("N-D", "You see the entrance of the dining room, smells well", true, (Room*)entity[6], (Room*)entity[8], EAST)));//Floor -1 exit to the dining rooom
	entity.push_back((new Exit("D-N", "You can see the whole floor -1, it's a little bit cold", true, (Room*)entity[8], (Room*)entity[6], WEST)));	//Dining Room exit to the floor -1
	entity.push_back((new Exit("N-P", "You see the programming room", true, (Room*)entity[6], (Room*)entity[9], SOUTH)));//Floor -1 exit to the programming room
	entity.push_back((new Exit("P-N", "You can see the whole floor -1, it's a little bit cold", true, (Room*)entity[9], (Room*)entity[6], NORTH)));	//Programming room exit to the floor - 1
	
	//ADD EVERY ITEM IN EACH ROOM:
	entity.push_back(new Item("box", "A box were you can put objects", (Room*)entity[0]));
	entity.push_back(new Item("folder", "A folder with all the information of some students", (Room*)entity[1]));
	entity.push_back(new Item("camera", "A new shinny camera with some stickers", (Room*)entity[2]));
	entity.push_back(new Item("candy", "A normal Candy", (Room*)entity[7]));
	entity.push_back(new Item("homework", "Your homework", (Npc*)entity[42]));
	entity.push_back(new Item("map", "A map of the University where you can see all the rooms", (Npc*)entity[38]));
	entity.push_back(new Item("coin", "Coint that you can use to buy things", (Npc*)entity[40]));
	entity.push_back(new Item("KitKat", "A delicious chocolate snack", (Npc*)entity[41]));
	entity.push_back(new Item("Chips", "A bag full of chips", (Npc*)entity[41]));
	entity.push_back(new Item("CocaCola", "The most sold drink in the world", (Npc*)entity[41]));

	entity[0]->drive.push_back(entity[28]);
	entity[1]->drive.push_back(entity[29]);
	entity[2]->drive.push_back(entity[30]);
	entity[7]->drive.push_back(entity[31]);
	//entity[8]->drive.push_back(entity[32]);

	//ADD NPC:
	entity.push_back(new Npc("Dani", "Dani is your friend and maybe he can help you find", (Room*)entity[3]));
	entity[3]->drive.push_back(entity[38]);
	//((Npc*)entity[38])->give.push_back(item[5]);
	entity.push_back(new Npc("Guardian", "Guardian moves arround the CITM all the time, if he catches you, he steals your map\n", (Room*)entity[8]));
	entity[8]->drive.push_back(entity[39]); // later this Npc will be moving by hiself for the rooms
	entity.push_back(new Npc("boy", "He is a very emotional boy, he lost his new Camera", (Room*)entity[4]));
	entity[4]->drive.push_back(entity[40]);
	entity.push_back(new Npc("machine", "A spending machine where you can buy:\n\t·KitKat\n\t·Chips\n\t·CocaCola", (Room*)entity[7]));
	entity[7]->drive.push_back(entity[41]);	
	entity.push_back(new Npc("Pep", "Pep is the boy who stole your homework, he is strong and loves chocolate", (Room*)entity[5]));
	entity[5]->drive.push_back(entity[42]);


}
//Chequing the commands the playar writes:
bool World::Inpunts(){

	int tmp = 0;
	char second[50];
	//char *phrase;
	String string;
	
	unsigned int currenttime = 0;
	unsigned int initialtime = 0;
	unsigned int charcommandnum = 0;
	//timeGetTime()
	initialtime = GetTickCount();
	printf("\t\t\tWhat do you want to do?\n");
	Vector<String*> command;
	while (1){
	
		player->enter = true;
		//Executa el codi cada x milisegons (DELAY)
		currenttime = GetTickCount();
		if (currenttime >= (initialtime + DELAY)){//movement
			Npcmove();
			initialtime = currenttime;
		}

		//kbhit test
		if (_kbhit())
		{
			if (charcommandnum < (COMMANDBUFFER - 2)){
				second[charcommandnum] = _getch();
				second[charcommandnum + 1] = '\0';
				printf("String: %s\n", second);//va imprimint l'estat de command
				charcommandnum++;
				if (second[charcommandnum - 1] == '\r'){//quant apretes enter, imprimeix el command i l'esborra

					printf("Your command is: %s\n", second);
					second[charcommandnum - 1] = '\0';
					charcommandnum = 0;
					string = second;
				}
			}
			else{
				second[COMMANDBUFFER - 1] = '\0';
			}
		}

		
		//string = second;
		if (string.c_str() != nullptr){
			if (string == "\0"){
				return true;
			}
			string.Token_ize(command);


		//Copying the first word to first

		//Comand Quit to exit the game
		if (command.buffer[0]->copier() == "Quit" || command.buffer[0]->copier() == "quit" || command.buffer[0]->copier() == "q" || command.buffer[0]->copier() == "QUIT"){
			printf("You exit the game\N");
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
				printf("I don't understand, repeat please\n");
			}
		}



		//Moving without using the command go:
		else if (command.buffer[0]->copier() == "east" || command.buffer[0]->copier() == "East" || command.buffer[0]->copier() == "EAST" || command.buffer[0]->copier() == "e"){
			MovePosition(EAST);
		}

		//South
		else if (command.buffer[0]->copier() == "south" || command.buffer[0]->copier() == "South" || command.buffer[0]->copier() == "SOUTH" || command.buffer[0]->copier() == "s"){
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
				printf("I don't understand, repeat please\N");
			}
		}


		//Command help to explain how all the commands work
		else if (command.buffer[0]->copier() == "help" || command.buffer[0]->copier() == "Help" || command.buffer[0]->copier() == "HELP" || command.buffer[0]->copier() == "h"){
			printf("TO MOVE THROUGH THE ROOMS USE THE COMMAND GO, go, Go, 'g'\nPLUS THE DIRECTION YOU WANT (NORTH, north,North, 'n', SOUTH, south, South,'s', EAST, east, East,'e', WEST,west, West, 'w')\nYOU CAN ALSO MOVE BY ONLY WRITING:\n(NORTH, north,North, 'n', SOUTH, south, South,'s', EAST, east, East,'e', WEST,west, West, 'w')\nTOO LOOK ALL THE POSIBLE EXITS USE THE COMMAND LOOK, look, Look, 'l'\nPLUS THE  DIRECTION YOU WANT.\nUSE THE COMMAND OPEN/CLOSE, open/close, Open/close, 'o'/'c'\nTO OPEN/CLOSE DOORS. IF YOU WANT TO EXIT WRITE QUIT, 'q'.\n");
			printf("YOU CAN PICK/DROP ITEMS WITH PICK/DROP + ITEM NAME\nYOU CAN ALSO PUT THIS ITEMS IN A BOX WITH PUT+ ITEM NAME + IN + BOX\nYOU CAN SEE THE DESCRIPTION OF ANY NPC WITH DESCRIPTION + NPC NAME\nYOU CAN ALSO TALK WITH THEM USING TALK + NPC NAME\nALSO YOU CAN BUY ITEMS BY USING COMMAND BUY + NPC NAME\nIF YOU WRITE WRONG ANY COMMAND YOU HAVE TO PRESS ENTER AND WRITE IT ANOTHER TIME\n");
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
			else if (command.buffer[1]->copier() == "south" || command.buffer[1]->copier() == "South" || command.buffer[1]->copier() == "SOUTH" || command.buffer[1]->copier() == "s"){
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
			else if (command.buffer[1]->copier() == "south" || command.buffer[1]->copier() == "South" || command.buffer[1]->copier() == "SOUTH" || command.buffer[1]->copier() == "s"){
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
			/*else if (command.buffer[1]->copier() == "kleenex" || command.buffer[1]->copier() == "Kleenex" || command.buffer[1]->copier() == "KLEENEX" || command.buffer[1]->copier() == "k"){
				PickItem(command.buffer[1]->copier());
			}*/
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
			/*else if (command.buffer[1]->copier() == "kleenex" || command.buffer[1]->copier() == "Kleenex" || command.buffer[1]->copier() == "KLEENEX" || command.buffer[1]->copier() == "k"){
				DropItem(command.buffer[1]->copier());
			}*/
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
					if (player->position == ((Npc*)entity[38])->location){
						talk(command.buffer[1]->copier());
					}
					else{
						printf("This Npc is not in this Room\n");
					}
				}
				else if (command.buffer[1]->copier() == "boy"){
					if (player->position == ((Npc*)entity[40])->location){
						talk(command.buffer[1]->copier());
					}
					else{
						printf("This Npc is not in this Room\n");
					}
				}
				
			}
			else if (command.buffer[1]->copier() == "Pep"){
				if (player->position == ((Npc*)entity[42])->location){
					talk(command.buffer[1]->copier());
				}
				else{
					printf("This Npc is not in this Room\n");
				}
			}
			else if (player->trans.size() != 0){//if the player has some items in the inventory			
				for (int i = 0; i < player->trans.size(); i++){
					if (command.buffer[1]->copier() == "Dani"){//we check with who is he talking
						if (player->position == ((Npc*)entity[38])->location){
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
						if (player->position == ((Npc*)entity[40])->location){
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
						if (player->position == ((Npc*)entity[38])->location){
							talk(command.buffer[1]->copier());
						}
					}
					else if (command.buffer[1]->copier() == "boy"){
						if (player->position == ((Npc*)entity[40])->location){
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
				if (player->position == ((Npc*)entity[41])->location){
					buy(command.buffer[1]->copier());
				}
				printf("This Npc is not here\n");
			}
		}




		player->enter = true;//complets the loop to continue recieving commands
		return true;
	}
}
}

	void World::MovePosition(dir direction)const{
		int tmp = 0;
		if (player->enter == true){
			for (int i = 10; i < 28; i++){
				if (((Exit*)entity[i])->origin == player->position){//Checking if the position of the player is the same of the exit origin
					if (((Exit*)entity[i])->direction == direction){//Checking if the direction iss the same of the exit direction
						if (((Exit*)entity[i])->open == true){//Checking if the door to enter the room is closed
							player->position = ((Exit*)entity[i])->destination;//Now the player position is the destination of the exit
							printf("\t\t\t\t%s\n%s\n\n", ((Exit*)entity[i])->destination->name.c_str(), ((Exit*)entity[i])->destination->description.c_str());
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

	void World::Look(dir watch)const{
		int tmp = 0;
		if (player->enter == true){
			for (int i = 10; i < 28; i++){
				if (((Exit*)entity[i])->origin == player->position){//Checking if the position of the player is the same of the exit origin
					if (((Exit*)entity[i])->direction == watch){//Checking if the direction iss the same of the exit direction
						printf("%s\n\n", entity[i]->description.c_str());
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
			for (int i = 10; i < 28; i++){
				if (((Exit*)entity[i])->origin == player->position){//Checking if the position of the player is the same of the exit origin
					if (((Exit*)entity[i])->direction == door){//Checking if the direction iss the same of the exit direction
						if (((Exit*)entity[i])->open == false){//Checking if the door to enter the room is closed
							printf("\t\t\tThe door is oppened\n\n");
							((Exit*)entity[i])->open = true;
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
			for (int i =10; i < 28; i++){
				if (((Exit*)entity[i])->origin == player->position){//Checking if the position of the player is the same of the exit origin
					if (((Exit*)entity[i])->direction == door){//Checking if the direction iss the same of the exit direction
						if (((Exit*)entity[i])->open == true){//Checking if the door to enter the room is opened
							printf("\t\t\tYou closed the door\n\n");
							((Exit*)entity[i])->open = false;
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
			for (int j = 28; j <38; j++){
				if ((((Item*)entity[j])->localitzation) == (player->position)){
					if (name == ((Item*)entity[j])->name.copier()){
						printf("\t\t\tYou picked the %s\n\n", ((Item*)entity[j])->name.c_str());
						tmp = 1;
						player->trans.push_back(entity[j]);
						player->position->drive.cleaner(j);
						((Item*)entity[j])->localitzation = nullptr;
						return;
					}
				}
			}




			printf("\t\t\tThis object is not here\n\n");
		}
	}








	void World::DropItem(const String name){
		int tmp = 0;
		for (int j = 28; j < 38; j++)	{
			if (((Item*)entity[j])->name == name){
				printf("\t\t\tYou Droped the %s\n\n", ((Item*)entity[j])->name.c_str());
				((Item*)entity[j])->localitzation = player->position;
				player->position->drive.push_back(((Item*)entity[j]));
				player->trans.cleaner(j);

			}

		}
		if (tmp != 0)
			printf("\t\t\tThis object is not here\n\n");
	}
	void World::PutItem(const String items){
		if (player->position == entity[0]){
			if (player->trans.size() > 0){
				for (unsigned int i = 0; player->trans.size() > i; i++)
				{
					if (items == player->trans[i]->name){
						((Item*)entity[28])->transp.push_back(player->trans[i]);
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
		if (player->position == entity[0]){
			if (player->trans.size() < 5){//inventory size
				for (unsigned int i = 0; ((Item*)entity[28])->transp.size() > i; i++)
				{
					if (items == ((Item*)entity[28])->transp[i]->name){
						player->trans.push_back(((Item*)entity[28])->transp[i]);
						printf("\t\tYou got the %s from the box\n\n", ((Item*)entity[28])->transp[i]->name.c_str());
						((Item*)entity[28])->transp.cleaner(i);
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
		for (int j = 38; j < 43; j++){
			if (entity[j]->name == name){
				if (player->position == ((Npc*)entity[j])->location){
					printf("\t\t\tName:%s\n        \t\tDescription: %s\n\n", entity[j]->name.c_str(), entity[j]->description.c_str());
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

		if (player->position == entity[0]){//f0
			map[14][11] = '*';
		}
		else if (player->position == entity[1]){//secretary
			map[14][18] = '*';
		}
		else if (player->position == entity[2]){//set
			map[14][6] = '*';
		}
		else if (player->position == entity[3]){//f1
			map[7][11] = '*';
		}
		else if (player->position == entity[4]){//toilets
			map[4][11] = '*';
		}
		else if (player->position == entity[5]){//art
			map[7][4] = '*';
		}
		else if (player->position == entity[6]){//f-1
			map[7][25] = '*';
		}
		else if (player->position == entity[7]){//VendingMachine
			map[7][20] = '*';
		}
		else if (player->position == entity[8]){//Dining
			map[9][29] = '*';
		}
		else if (player->position == entity[9]){//Programming
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
				printf("Dani:Hello Marc, how are you?\n");
				printf("You: 1- Not really well, someone has stolen my homework...\nYou: 2-Good, what are you doing here Dani?\n");
				scanf_s("%i", &options);

				switch (options){

				case 1:						
						printf("Dani: Oh, what a bad notice, I think I have something that can help you...\n");
						printf("You:1-Really? and what is this thing?\n");
						scanf_s("%i", &option2);
						if (option2 != 1){
							printf("I don't understand start again\n");
							scanf_s("%i", &option2); 
						}
						else if (option2 == 1){
							printf("Dani: It's a map of the University. With the map you will be able to see all the rooms. Take it\n");
							printf("\t\t\t***You recieved a map***\n\n");
							player->trans.push_back(entity[33]);
							//npc[0]->give.cleaner(0);							
						}					
						break;
				case 2:
					printf("Dani: I had a meeting with my tutor. And what about you? clases finished 3 hours ago...\n");
					printf("You:1-Okay I will tell you, someone has stolen my homework and i can't find him\n");
					scanf_s("%i", &option2);
					printf("Dani: Oh, what a bad notice, I think I have something that can help you...\n");
					printf("You:1-Really? and what is this thing?\n");
					scanf_s("%i", &option2);
					if (option2 != 1){
						printf("I don't understand start again\n");
						scanf_s("%i", &option2);
					}
					else if (option2 == 1){
						printf("Dani: It's a map of the University. With the map you will be able to see all the rooms. Take it\n");
						printf("\t\t\t***You recieved a map***\n");
						player->trans.push_back(entity[33]);
						//npc[0]->give.cleaner(5);
					}
						
					break;
				default:
					printf("I don't understand, start again\n");
					break;
				}
				

			}
		else if (names == "boy"){
			printf("Boy: Oh, hello Marc...snif\n");
			printf("You: 1-Why are you crying?\n");
			scanf_s("%i", &options);
			switch (options){

			case 1:
				printf("Boy:Yesterday I bought I new camera and now I have lost it...snif.\n");
				printf("You:1-Don't worry boy, sure it's here in the CITM, you will find it don't cry anymore.\n");
				scanf_s("%i", &option2);
				if (option2 != 1){
					printf("I don't understand start again\n");
					scanf_s("%i", &option2);
				}
				else if (option2 == 1){
					printf("Boy: Please Marc, can you find it for me please?\n");
					printf("You: 1-I have more important problems to solve than looking for a camera.\nYou: 2-Okey, do you remember when you use it the last time?\n");
					scanf_s("%i", &option3);
					if (option3 == 1){
						printf("Boy: Pleasee...snif, I need it, I will give you 1 coin\n");
						printf("You:1-Mmmm, okey I will do it, do you remember when you use it the last time?\n");
						scanf_s("%i", &option4);
						printf("Boy: Last time I had it was in the Set, thanks Marc..snif\n");					
					}
					else if (option3 == 2){
						
						printf("Boy: Last time I had it was in the Set, thanks Marc..snif\n");
						break;					
					}
					

				}
			}
		}
		if (names == "Pep"){
			printf("Pep: Hello little boy, are you loking for someting?\n");
			printf("You: 1-Stop, I know you have my homework, Give it to me\n");
			scanf_s("%i", &options);

			switch (options){
			case 1:
				printf("Pep: What? Don't you see I can kick you, T won't give you your homework\n");
				for (int i = 0; i < player->trans.size(); i++){
					if (player->trans[i]->name == "KitKat"){
						printf("You: 1-Wait, let's calm down, I can offer you someting\nYou: 2-It's my homework, I made it, its mine, GIVE IT TO ME!\n");
						scanf_s("%i", &option2);
						switch (option2){
						case 1:
							printf("Pep: Now I like more, you are learning little boy, what can you offer me?\n");
							printf("You: 1- I know you love chocolate and I have one KitKat\n");
							scanf_s("%i", &option3);

							printf("Pep: Oh, I love KitKat, take your stupid homework and give me that delicous candy\n");
							printf("You: 1-Here you have...\n");
							scanf_s("%i", &option4);
							printf("\t\t\t***You gave Pep the KitKat***\n");
							for (int i = 0; i < player->trans.size(); i++){
								if (player->trans[i]->name == "KitKat"){
									player->trans.cleaner(i);
								}
							}
							player->trans.push_back(entity[32]);
							printf("\t\t\t***Finally you have you homework***\n\n");

							printf("Thanks for playing, hope you enjoyed the game,press q or Quit to finish game\n");
							break;

						case 2:
							printf("Pep: I advised you once, you are a dead little boy\n");
							printf("You: 1-No sorry, don't hit me\n");
							scanf_s("%i", &option3);
							printf("***Pepe hit you so hard that you have to go to the hospital, you are not able to deliver you homework***\n");
							printf("t\t\t**GAME OVER**\n\n\n");
							printf("Thanks for playing, hope you enjoyed the game,press q or Quit to finish game\n");
							break;


							
						}
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
			printf("Thanks!\n\n");
		}
	}
	void World::talkidle2(const String names)const{
		printf("Boy:Really thanks, my cameraa...snif\n\n");
		printf("Boy:Here you have your coin\n\t\t\t**You Recieved a coin**\n\n");
		player->trans.push_back(entity[34]);
		//npc[2]->give.cleaner(0);
		for (int i = 0; i < player->trans.size(); i++){
			if (player->trans[i]->name == "camera"){
				player->trans.cleaner(i);
			}

		}
		
		

	}
	void World::buy(const String names)const{
		int option = 0;
		int tmp = 0;
		if (names == "machine"){
			printf("All products cost 1 coin\n\t\t1_KitKat\n\t\t2_Chips\n\t\t3_CocaCola\n\t\tChoose what do you whant\n");
			scanf_s("%i", &option);
			for (int i = 0; i < player->trans.size(); i++){
				if (player->trans[i]->name == "coin"){
					switch (option){

					case 1:
						printf("\t\t\t\t**You Recieved a KitKat**\n\n");
						player->trans.push_back(entity[35]);
						tmp = 1;
						break;
					case 2:
						printf("\t\t\t\t**You Recieved Chips**\n\n");
						player->trans.push_back(entity[36]);
						tmp = 1;
						break;
					case 3:
						printf("\t\t\t\t**You Recieved a CocaCola**\n\n");
						player->trans.push_back(entity[37]);
						tmp = 1;
						break;

					}

				}

			}
			if (tmp == 0){
				printf("You don't have enough coins to buy this\n");
			}

		}
	
	
	}

	void World::Npcmove() const{
		srand(time(NULL));
		int option;
		option = rand() % 4;
		switch (option){
		case 0://NORTH
			for (int i = 10; i < 28; i++){
				if (((Exit*)entity[i])->origin == ((Npc*)entity[39])->location){//Checking if the position of the player is the same of the exit origin
					if (((Exit*)entity[i])->direction == NORTH){//Checking if the direction iss the same of the exit direction
						if (((Exit*)entity[i])->open == true){//Checking if the door to enter the room is closed
							((Npc*)entity[39])->location = ((Exit*)entity[i])->destination;//Now the player position is the destination of the exit
							//printf("Someone moved %s\n", ((Exit*)entity[i])->destination->name.c_str());
							if (((Npc*)entity[39])->location == player->position){
								for (int i = 0; i < player->trans.size(); i++){
									if (player->trans[i]->name == "map"){
										printf("Guardian: What are you doing with that map, you can't have this, give it to me\n\n");
										printf("\t\t\t\t**The Guardian took your map**\n\n");
										player->trans.cleaner(i);
									}
								}
								printf("\t\t\tGuardian:Be carefull on what you do boy, i am always looking\n\n");


							}
							break;
						}
					}
				}
			}
			//printf("Remaining\n");
			break;
		case 1://SOUTH

			for (int i = 10; i < 28; i++){
				if (((Exit*)entity[i])->origin == ((Npc*)entity[39])->location){//Checking if the position of the player is the same of the exit origin
					if (((Exit*)entity[i])->direction == SOUTH){//Checking if the direction iss the same of the exit direction
						if (((Exit*)entity[i])->open == true){//Checking if the door to enter the room is closed
							((Npc*)entity[39])->location = ((Exit*)entity[i])->destination;//Now the player position is the destination of the exit
							//printf("Someone moved %s\n", ((Exit*)entity[i])->destination->name.c_str());
							if (((Npc*)entity[39])->location == player->position){
								for (int i = 0; i < player->trans.size(); i++){
									if (player->trans[i]->name == "map"){
										printf("Guardian: What are you doing with that map, you can't have this, give it to me\n\n");
										printf("\t\t\t\t**The Guardian took your map**\n\n");
										player->trans.cleaner(i);
									}
								}
								printf("\t\t\t\tBe carefull on what you do boy\n\n");


							}
							break;
						}
					}
				}
			}
			//printf("Remaining\n");
			break;

		case 2://EAST

			for (int i = 10; i < 28; i++){
				if (((Exit*)entity[i])->origin == ((Npc*)entity[39])->location){//Checking if the position of the player is the same of the exit origin
					if (((Exit*)entity[i])->direction == EAST){//Checking if the direction iss the same of the exit direction
						if (((Exit*)entity[i])->open == true){//Checking if the door to enter the room is closed
							((Npc*)entity[39])->location = ((Exit*)entity[i])->destination;//Now the player position is the destination of the exit
							//printf("Someone moved %s\n", ((Exit*)entity[i])->destination->name.c_str());
							if (((Npc*)entity[39])->location == player->position){
								for (int i = 0; i < player->trans.size(); i++){
									if (player->trans[i]->name == "map"){
										printf("Guardian: What are you doing with that map, you can't have this, give it to me\n\n");
										printf("\t\t\t\t**The Guardian took your map**\n\n");
										player->trans.cleaner(i);
									}
								}
								printf("\t\t\t\tBe carefull on what you do boy\n\n");


							}
							break;
						}
					}
				}
			}
			//printf("Remaining\n");
			break;

		case 3://WEST

			for (int i = 10; i < 28; i++){
				if (((Exit*)entity[i])->origin == ((Npc*)entity[39])->location){//Checking if the position of the player is the same of the exit origin
					if (((Exit*)entity[i])->direction == WEST){//Checking if the direction iss the same of the exit direction
						if (((Exit*)entity[i])->open == true){//Checking if the door to enter the room is closed
							((Npc*)entity[39])->location = ((Exit*)entity[i])->destination;//Now the player position is the destination of the exit
							//printf("Someone moved %s\n", ((Exit*)entity[i])->destination->name.c_str());
							if (((Npc*)entity[39])->location == player->position){
								for (int i = 0; i < player->trans.size(); i++){
									if (player->trans[i]->name == "map"){
										printf("Guardian: What are you doing with that map, you can't have this, give it to me\n\n");
										printf("\t\t\t\t**The Guardian took your map**\n\n");
										player->trans.cleaner(i);
									}
								}
								printf("\t\t\t\tBe carefull on what you do boy\n\n");


							}
							break;
						}
					}
				}
			}
			//	printf("Remaining\n");
			break;

		}

		

	}


	



	