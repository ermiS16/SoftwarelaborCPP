/*
 * aufgabe4Test.cpp
 *
 *  Created on: 29.11.2018
 *      Author: Eric
 */

#include "StringTest.h"

//void initializeTestString(){
//	TestCaseString testsString[TEST_NO_STRING] = {
//			{"","",""},
//			{"","",""},
//			{"","",""},
//			{"","",""},
//			{"","",""},
//			{"","",""},
//			{"","",""},
//			{"","",""},
//			{"","",""},
//			{"","",""}
//	};
//		runTestString(TEST_NO_STRING, testsString);
//}

//void runTestString(int no, TestCaseString test[]){
//
//}

void testString(){
	  cout << "String()" << endl;
	  String s1;
	  cout << "String s1; => s1= " << s1 << endl;
	  cout << endl;

	  cout << "String(char c)" << endl;
	  String s7('c');
	  cout << "String s7('c') => s7 = " << s7 << endl;
	  cout << endl;

	  cout << "String(const char *s)" << endl;
	  String s2("Hello");
	  cout << "String s2(\"Hello\") => s2 = " << s2 << endl;
	  cout << endl;

	  cout << "String(String& s) / Kopierkonstruktor" << endl;
	  cout << "s2 = " << s2 << endl;
	  String s3(s2);
	  cout << "String s3(s2) => s3 = " << s3 << endl;
	  cout << "s2 = " << s2 << endl;
	  cout << endl;

//	  cout << "String(String&& s) / Movekonstruktor (Rule of Five)" << endl;
//	  String s8 = String("Hello");
//	  cout << "String s8 = s3 => s8 = " << s8 << endl;
//	  cout << "s3 = " << s3 << endl;
//	  cout << endl;

	  cout << "operator=(String& s) / Zuweisung" << endl;
	  cout << "s2 = " << s2 << endl;
	  String s4 = s2;
	  cout << "String s4 = s2 => s4 = " << s4 << ", " << "s2 = " << s2 << endl;
	  cout << endl;

	  cout << "operator+=(String& s) / Konkatenation" << endl;
	  cout << "s1 = " << s1 << ", " << "s2 = " << s2 << endl;
	  s1 += s2;
	  cout << "s1 += s2 => s1 = " << s1 << ", " << "s2 = " << s2 << endl;
	  cout << endl;

	  cout << "operator[](int index) / Array" << endl;
	  cout << "s2 = " << s2 << endl;
	  cout << "s2[2] = " << s2[2] << endl;
}

ostream& operator<< (ostream &out, String &s) {
  for(int i=0; i<s.size; i++) {
    out << s.str[i];
  }

  return out;
}
