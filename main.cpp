/*
 * main.cpp
 *
 *  Created on: 29.11.2018
 *      Author: Eric
 */

#include "main.h"

int main(void){

	testString();
	return 0;
}

void testString(){
	  String s1;
	  cout << "s1: " << s1 << endl;
	  String s2("Hello");
	  cout << "s2: " << s2 << endl;
	  String s3(s2);
	  cout << "s3: " << s3 << endl;
	  String s4 = s2;
	  cout << "s4: " << s4 << endl;
	  cout << "s2 Adresse: " << &s2 << endl;
	  cout << "s4 Adresse: " << &s4 << endl;
	  s1 += s2;
	  cout << "s1: " << s1 << endl;
	  String s5("World");
	  s2 += s5;
	  cout << "s2: " << s2 << endl;
	  s2 += s2;
	  cout << "s2: " << s2 << endl;

}

ostream& operator<< (ostream &out, String &s) {
  for(int i=0; i<s.size; i++) {
    out << s.str[i];
  }

  return out;
}
