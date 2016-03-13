#include <stdio.h>
#include <stdlib.h>
#include "function.h"


World::World()
{
	//MEMORY FOR THE ROOMS
	Rooms *floor0 = (Rooms*)new Rooms[6];
	Rooms *floor1 = (Rooms*)new Rooms[4];
	Rooms *negfloor = (Rooms*)new Rooms[5];	
	Player *position = (Player*)new Player("Entrance","You are now in the entrance of the CITM.\nTo the NORTH you can see the stairs that go down to the floor -1.\n To the EAST we find the Secretary's office.\nTo the WEST there's the entrance to the photography room, but the door is closed.\nTo the SOUTH there are the stairs that go up to the floor 1\n");
	//NAMES AND DESCRIPTIONS FOR EVERY ROOM IN THE FLOOR 0:
	*floor0->description = "You are now in the entrance of the CITM.\nTo the NORTH you can see the stairs that go down to the floor -1.\n To the EAST we find the Secretary's office.\nTo the WEST there's the entrance to the photography room, but the door is closed.\nTo the SOUTH there are the stairs that go up to the floor 1\n";
	*floor0->name = "Entrance";
	*(floor0 + 1)->description = "You are now in the Secretary's Room. Seems nobody is here.\nYou can see a big table, some chairs and two computers.\nOn the table there are some papers and also a newspaper\n";
	*(floor0+1)->name = "Secretary's Room";
	*(floor0 + 2)->description = "You are now in front of a door and it's closed\n";
	*(floor0 + 2)->name = "Photography set entrance";
	*(floor0 + 3)->description = "You are now in the Photography set, a big room equiped with a lot of technology.\nIn the center of the set you can see a camera on the floor next to a red backpack\n";
	*(floor0 + 4)->description = "You are now in the stairs to go down to the floor -1";
	*(floor0 + 4)->name = "Down Stairs";
	*(floor0 + 5)->description = "You are now in the stairs to go up to the floor 1";
	*(floor0 + 5)->name = "Up Stairs";

	//EXITS OF THE ROOMS ON THE FLOOR 0:
	*(floor0 + 1)->exit = *floor0->name;
	*(floor0 + 2)->exit = *floor0->name;
	*(floor0 + 3)->exit = *(floor0 + 2)->name;
	*(floor0 + 4)->exit = *(negfloor)->name;
	*(floor0 + 5)->exit = *(floor1)->name;

	//NAMES AND DESCRIPTIONS FOR EVERY ROOM IN THE FLOOR 1:
	*floor1->description = "You are now in the Floor 1, you can see some students talking next to a drinking fountain.\n To the NORTH you can see the toilets,it seems there's a tear's trail.\n To the WEST there's the Art Room, and you hear the voice of someone.\nTo the SOUTH there are the stairs to go down to the floor 0.\n";
	*floor1->name = "Floor 1";
	*(floor1 + 1)->description = "You are now in the toilets, the floor is a little wet but the smell is not that bad.\nThere are three toilets and a big mirror.\nIn front of the mirror there's a boy crying.\n";
	*(floor1 + 1)->name = "Toilets";
	*(floor1 + 2)->description = "You are now in the Art Room, you see a lot of tables and a huge amount of pencils.\n You also see a boy, his name is Paul, he is the bully who has stolen your homework.";
	*(floor1 + 2)->name = "Art Room";
	*(floor1 + 3)->description = "You are in the stairs to go down to the floor 0.";
	*(floor1 + 3)->name = "Down Stairs";

	//EXITS OF THE ROOMS ON THE FLOOR 1:
	*(floor1 + 1)->exit = *floor1->name;
	*(floor1 + 2)->exit = *floor1->name;
	*(floor1 + 3)->exit = *floor0->name;

	//NAMES AND DESCRIPTIONS FOR EVERY ROOM IN THE FLOOR -1:
	*negfloor->description = "You are in the floor -1. It's a little cold.\nTo the NORTH there are the stairs to go up to the floor0.\nTo the EAST there's the entrance to the dining room.\nTo the WEST there's the vending machine with a lot of delicious snaks.\nTo the SOUTH there's the room where you have to deliver yout work";
	*negfloor->name = "Neg Floor";
	*(negfloor + 1)->description = "You are in the stairs to go up to the Floor 0";
	*(negfloor + 1)->name = "Up Stairs";
	*(negfloor + 2)->description = "You are in front of the vending machine. There are a lot of snacks. But you don't have money to buy one.\n";
	*(negfloor + 2)->name = "Vending Machine";
	*(negfloor + 3)->description = "You are in the dining room. You can see 3 big tables and two microwaves.\nThere are few people on the last table having lunch.\n";
	*(negfloor + 3)->name = "Dining Room";
	*(negfloor + 4)->description = "You are in front of the programming room.\nIn this class you have to deliver your homework\nIt's a bad idea if you enter without the homework\n";
	*(negfloor + 4)->name = "Room Entrance";
	*(negfloor + 5)->description = "You have entered teh Programming Room.\nYou are alone with the teacher. He looks very angry.\nBut if you have your homework you will not have any problem.\n";
	*(negfloor + 5)->name = "Programming Room";

	//EXITS OF THE ROOMS ON THE FLOOR 1:
	*(negfloor + 1)->exit = *floor0->name;
	*(negfloor + 2)->exit = *negfloor->name;
	*(negfloor + 3)->exit = *negfloor->name;
	*(negfloor + 4)->exit = *negfloor->name;

	//SETTING UP THE PLAYER POSITION:

	position->firstPosition;


	

}

Rooms::Rooms()
{
	Rooms*rooms;
	

}

void Rooms::everyRoom(char*name, char*description)
{

}

Player::Player()
{
	Player *movement;


}
void Player::firstPosition(char*name, char* description)
{
	printf("%s\n", name);
	printf("%s", description);
	

}