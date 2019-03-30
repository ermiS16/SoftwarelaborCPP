/*
 * aufgabe4Test.cpp
 *
 *  Created on: 29.11.2018
 *      Author: Eric
 */

#include "String.h"
#include "StringTest.h"

void initializeTestString(){
	TestCaseString testsString[TEST_NO_STRING] = {
			{"","",""},
			{"","",""},
			{"","",""},
			{"","",""},
			{"","",""},
			{"","",""},
			{"","",""},
			{"","",""},
			{"","",""},
			{"","",""}
	};
		runTestString(TEST_NO_STRING, testsString);
}

void runTestString(int no, TestCaseString test[]){

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
	  s1 += s2;
	  cout << "s1: " << s1 << endl;
	  String s5("World");
	  s2 += s5;
	  cout << "s2: " << s2 << endl;
	  s2 += s2;
	  cout << "s2: " << s2 << endl;
	  String s6(s2);
	  cout << "s6; " << s6 << endl;
}

ostream& operator<< (ostream &out, String &s) {
  for(int i=0; i<s.size; i++) {
    out << s.str[i];
  }

  return out;
}
