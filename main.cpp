/*
 * main.cpp
 *
 *  Created on: 29.11.2018
 *      Author: Eric
 */

#include "main.h"

int main(void){

//	testString();
	testRegex();
	return 0;
}

void testRegex(void){

	  // phi + c
	  RE* r3 = new Alt (new Phi(), new Ch('c'));

	  // c + phi
	  RE* r4 = new Alt (new Ch('c'), new Phi());

	  cout << r3->pretty() << endl;

	  cout << r3->simp()->pretty() << endl;

	  // c**
	  RE* r5 = new Star(new Star (new Ch('c')));

	  cout << r5->pretty() << endl;
	  cout << r5->simp()->pretty() << endl;

	  // phi*
	  RE* r6 = new Star(new Phi());

	  cout << r6->pretty() << endl;
	  cout << r6->simp()->pretty() << endl;

	  // (phi + c) + c**
	  RE* r7 = new Alt(r3,r5);

	  cout << r7->pretty() << endl;
	  // exhaustively apply simplifications
	  cout << simpFix(r7)->pretty() << endl;
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
