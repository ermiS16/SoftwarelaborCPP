/*
 * main.cpp
 *
 *  Created on: 29.11.2018
 *      Author: Eric
 */

#include "main.h"

int main(void){

	  String s1;
	  cout << s1 << endl;
	  String s2("Hello");
	  cout << s2 << endl;
	  String s3(s2);
	  cout << s3 << endl;
	  cout << s2[ 1 ] << endl;
	  String s4("World!");
	  String s5 = s4;
	  cout << s5 << endl;
	  //	  s1 += s2; s2 = s3;

	  return 0;
}

ostream& operator<< (ostream &out, String &s) {
  for(int i=0; i<s.size; i++) {
    out << s.str[i];
  }

  return out;
}
