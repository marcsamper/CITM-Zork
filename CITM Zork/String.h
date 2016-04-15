#ifndef STRING_H
#define STRING_H


class String: public Entity{
	private:
		char* buffer = nullptr;
		char* buffer2 = nullptr;
		unsigned int reserved_memory;
		unsigned int reserved_memory2;
	
		
	public://constructors and destructors
		String();
		String(const char* str, const char* str2, unsigned int i);
		String(const String& copy);
		~String();
	public://methods
		bool compare(const char*str, const char*str2);
		World* asign=nullptr;
		unsigned int length()const;
		const char* c_str() const;
		bool empty() const;
		bool operator ==(const String& str)const;
		bool operator ==(const char* str)const;
		void operator=(const String& str);
		void operator +=(const String& str);
		String operator+(const String&str)const;
		void cleanup();

};

#endif