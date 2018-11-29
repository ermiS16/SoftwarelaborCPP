/*
 * aufgabe4.h
 *
 *  Created on: 29.11.2018
 *      Author: Eric
 */

#ifndef STRING_H_
#define STRING_H_

#include <iostream>
using namespace std;

class String{
private:
	int size;
	char *str;
public:
	String();
	String(char c);
	String(const char*);
	String(const String&);
	~String();

	char& operator[](int index);
	String& operator=(String&);
	String& operator+=(String&);

	friend ostream& operator<< (ostream &out, String &s);
};

#endif /* STRING_H_ */
