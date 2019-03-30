/*
 * aufgabe4Test.h
 *
 *  Created on: 29.11.2018
 *      Author: Eric
 */

#ifndef STRINGTEST_H_
#define STRINGTEST_H_

#define TEST_NO_STRING 10

#include "TestEnum.h"

typedef struct {
	String s1;
	String s2;
	String expected;
} TestCaseString;

void initializeTestString();
void testString(void);
void runTestString(int no, TestCaseString testString[]);
ostream& operator<< (ostream &out, String &s);
#endif /* STRINGTEST_H_ */
