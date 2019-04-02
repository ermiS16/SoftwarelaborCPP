/*
 * TestRefex.h
 *
 *  Created on: 27.03.2019
 *      Author: eric
 */

#ifndef TESTREGEX_H_
#define TESTREGEX_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "TestEnum.h"
#include "RE.h"
using namespace std;
#define TEST_NO_STRING 10


typedef struct{
	RE *r;
	RE *simple;
	RE *w
	RE *expected;
} TestCaseRegex;

void regex(void);
void initializeTestRegex(void);
void runTestRegex(int no, TestCaseRegex test[]);

Test testRegex();
RE *deriv(RE *r, char l);
bool match(RE *r, string s);
bool orakel(RE *r, RE *rSimp, string l);
#endif /* TESTREGEX_H_ */
