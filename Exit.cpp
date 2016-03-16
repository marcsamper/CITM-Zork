#include <stdio.h>
#include <stdlib.h>
#include "Exits.h"

Exit::Exit(){
	origin = new Room;
	destination = new Room;
}
Exit::~Exit(){
	delete[] origin;
	delete[] destination;
}