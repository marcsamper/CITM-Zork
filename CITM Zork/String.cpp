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

	printf("Soy un constructor de copia\n");
	reserved_memory = strlen(copy.buffer) + 1;
	buffer = new char[reserved_memory];
	strcpy_s(buffer, reserved_memory, copy.buffer);

}
String::String(){
	//buffer = new char[reserved_memory];
}
String::~String(){
	printf("La clase string se esta destruyendo\n");
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
	reserved_memory = strlen(buffer) + 1;
	if (str.length() + 1 > reserved_memory){
		reserved_memory = str.length() + 1;
		delete[]buffer;
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

bool String::compare(const char* str, const char* str2){

	return(strcmp(str, str2) == 0);
}



