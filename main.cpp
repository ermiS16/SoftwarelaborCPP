/*
 * main.cpp
 *
 *  Created on: 29.11.2018
 *      Author: Eric
 */

#include "main.h"



int main(void){
	cout << "Start Test Reverse Recursiv" << endl;
	testReverse();
	cout << "End Test Reverse Recursiv" << endl;

	cout << "Start Test Regex" << endl;
	cout << endl;
	regex();
//	initializeTestRegex();
//	testRegex();
	cout << "End Test Regex" << endl;
	cout << endl;
	cout << "Start Test String Operators" << endl;
	cout << endl;
	initializeTestString();
	testString();
	cout << "End Test String Operators" << endl;
	cout << endl;
	return 0;
}

void testReverse(void){
	char input[] = "Hallo";
	cout <<	"Input: " << input << ", Reverse: " << reverseRec(input) << endl;
}
