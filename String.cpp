/*
 * String.cpp
 *
 *  Created on: 29.11.2018
 *      Author: Eric
 */

#include "String.h"


	String::String(){
		size = 0;
		str = new char[1];
		str[0] = '\0';

	}
	String::String(char c){
	    size = 1;
	    str = new char[2];
	    str[0] = c;
	    str[1] = '\0';
	}
	String::String(const char *s) {
		int i=0;
		while(s[i] != '\0'){
			i++;
		}
		size = i;
		str = new char[size+1];
		for(int i=0; i<size;i++){
			str[i] = s[i];
		}
		str[size+1] = '\0';
	}

	String::String(const String& s) {
		size = s.size;
		str = new char[size+1];
		str = (s.str);
		str[size+1] = '\0';
	}

	String::String(String&& s){
		this->size = s.size;
		this->str = s.str;
		s.str = nullptr;
	}

	String::~String() {
		delete[] str;
	}

	char& String::operator[](int index) {
		return this->str[index];
	}

	String& String::operator=(String& s) {
		if(this != &s){
			delete str;
			str = new char[*s.str];
		}
		return *this;
	}

	String& String::operator=(String&& s){
		if(this != &s){
			delete this->str;
			this->str = s.str;
			s.str = nullptr;
		}
		return *this;
	}

	String& String::operator+=(String& s) {
		int newSize = this->size+s.size;
		char *newString = new char(newSize);
		int index=0;
		for(int i=0; i<this->size;i++){
			newString[index] = this->str[i];
//			newString++;
			index++;
		}
		for(int i=0; i< s.size ;i++){
			newString[index] = s.str[i];
			index++;
		}
		newString[index] = '\0';

		delete str;
		str = new char[newSize];
		str = newString;
		size = newSize;

		return *this;

	}


