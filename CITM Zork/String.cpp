#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "String.h"
#include "Entity.h"
#include "World.h"

String::String(const char* str){
	reserved_memory = strlen(str) + 1;
	buffer = new char[reserved_memory];
	strcpy_s(buffer, reserved_memory, str);//sempre que strcpy rep punters hem d'especificar el tamany máxim que pot copiar

	
}


String::String(const String& copy){


	reserved_memory = strlen(copy.buffer) + 1;
	buffer = new char[reserved_memory];
	strcpy_s(buffer, reserved_memory, copy.buffer);

}
String::String(){
	//buffer = new char[reserved_memory];
}
String::~String(){
	
	delete[] buffer;

}

unsigned int String::length()const{
	return strlen(buffer);

}

const char* String:: c_str()const{
	return buffer;

}

bool String::empty() const{
	return(strlen(buffer) == 0);

}

bool String::operator == (const String& str) const{
	return(strcmp(buffer, str.buffer) == 0);

}

bool String::operator == (const char* str) const{
	return(strcmp(buffer, str) == 0);

}

void String::operator =(const String& str){
	if (reserved_memory < str.length() + 1)
	{
		delete[] buffer;
		reserved_memory= str.length() + 1;
		buffer = new char[reserved_memory];
	}
	strcpy_s(buffer, reserved_memory, str.buffer);

}

void String::operator+=(const String& str){
	if (str.length() + length()>reserved_memory){
		reserved_memory += str.length();
		char* point = nullptr;
		point = new char[reserved_memory];
		strcpy_s(point, reserved_memory, buffer);
		delete[] buffer;
		buffer = new char[reserved_memory];
		strcat_s(point, reserved_memory, str.buffer);
		buffer = point;

	}
	else{

		strcat_s(buffer, reserved_memory, str.buffer);
	}
}

String String:: operator+(const String& str) const{
	String extra(str);
	int count = str.length() + reserved_memory;
	extra.buffer = new char[count];
	strcpy_s(extra.buffer, count, buffer);
	strcat_s(extra.buffer, count, str.buffer);
	return extra;
}

void String::cleanup(){
	strcpy_s(buffer, reserved_memory, "");
}

void String:: Token_ize(Vector<String*>& str){
	char* str2 = nullptr;
	
	str.push_back(new String(strtok_s(buffer, " ", &str2)));
	while (strcmp(str2, "") != 0){
		str.push_back(new String(strtok_s(NULL, " ", &str2)));
	}

}
String String::copier()const{
	String copy(buffer);
	return copy;

}
/*bool String::compare(const String& str, const char* str2){

	return(strcmp(str, str2) == 0);
}*/



