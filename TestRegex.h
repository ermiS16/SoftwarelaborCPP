/*
 * TestRefex.h
 *
 *  Created on: 27.03.2019
 *      Author: eric
 */

#ifndef TESTREGEX_H_
#define TESTREGEX_H_


#include "TestEnum.h"
#include "RE.h"
#define TEST_NO_REGEX 25

typedef struct{
	RE *r;
	RE *simpR;
	const char *w;
	bool expected;
} TestCaseRegex;


void regex(void);
void initializeTestRegex(void);
void runTestRegex(int no, TestCaseRegex test[]);
Test testRegex(RE* r, RE *simpR,const char* c, bool expected);

RE *deriv(RE *r, char l);
bool match(RE *r, string s);
bool orakel(RE *r, RE *rSimp, string l);

#endif /* TESTREGEX_H_ */
