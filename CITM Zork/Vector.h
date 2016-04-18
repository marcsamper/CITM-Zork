#ifndef VECTOR_H
#define VECTOR_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

template<class TYPE>
class Vector{
private:
	TYPE* buffer = nullptr;
	unsigned int capacity = 10;
	unsigned int num_elements = 0;


public:

	Vector(unsigned int size) :capacity(size){
		buffer = new TYPE[size];
	}
	Vector(){
		buffer = new TYPE[capacity];
	}

	Vector(const Vector<TYPE>& vector){
		num_elements = vector.num_elements;
		capacity = vector.capacity;

		if (capacity > num_elements){
			buffer = new TYPE[num_elements];
		}
		else {
			buffer = new TYPE[capacity];
		}

		for (unsigned int i = 0; i < num_elements; ++i){
			buffer[i] = vector.buffer[i];
		}

	}

	void push_back(const TYPE thing){

		if (capacity == num_elements){
			TYPE *temp = nullptr;
			capacity *= 2;
			temp = new TYPE[capacity];

			for (int i = 0; i < num_elements; i++){
				temp[i] = buffer[i];

			}
			delete[] buffer;
			buffer = temp;
		}
		buffer[num_elements++] = thing;
	}

	void push_front(const TYPE thing){
		if (capacity == num_elements){
			TYPE *temp = nullptr;
			capacity *= 2;
			temp = new TYPE[capacity];

			for (int i = num_elements - 1; i >= 0; i--){
				temp[i + 1] = buffer[i];

			}
			delete buffer;
			buffer = temp;
			buffer[0] = thing;
		}
		else{

			for (int i = num_elements - 1; i >= 0; i--){
				buffer[i + 1] = buffer[i];

			}


			buffer[0] = thing;
			num_elements++;
		}


	}


	void PrintVector(){

		for (int i = 0; i < num_elements; i++){

			printf("%i", buffer[i]);
		}
	}

	void clean(){
		num_elements == 0;
		}

	
	bool empty()const{
		return(num_elements == 0);

	}
	unsigned int capacitys()const{
		return capacity;
	}

	unsigned int size(){
		return num_elements;
	}

	void shrink_to_fit(){
		if (capacity != num_elements){
			TYPE* temp = nullptr;
			capacity = num_elements;
			temp = new TYPE[capacity];
			for (int i = 0; i < capacity; i++){
				temp[i] = buffer[i];
			}
			delete[] buffer;
			buffer = temp;
		}
	}

	bool pop_back(TYPE& value){

		if (value.num_elements > 0){
			value.num_elements--;
			return true;
		}
		return false;
	}
	
	TYPE operator[](unsigned int num)const{

		assert( num < 20);//make sure... if not jump to error
		return buffer[num];

	}

	TYPE& operator[](unsigned int num){//para poder escribir data[5]=3

		assert( num < 20);//make sure... if not jump to error
		return buffer[num];

	}

	//at




};

/*template <class TYPE>
int Vector::push_back(int number){
buffer[0] = number;

}
*/
#endif