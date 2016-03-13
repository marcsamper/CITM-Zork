#include <stdio.h>
#include <stdlib.h>
//WORLD
class World
{
public:
	World();
	//~World();

};
//ROOMS
class Rooms{
public:
	char *name[20];
	char *description[250];
	char *exit[20];
public:
	Rooms();
	//~Rooms();
	void everyRoom(char*name, char*description);

};
//EXITS
class Exit{
public:
	char exitName[20];
	char exitDescription[250];
public:
	Exit();
	~Exit();

};
//PLAYER
class Player{
public:
	Player();
	~Player();
	char position[20];
	char destiny[20];
	void firstPosition(char* name[25], char* description[250]);

};