/*
 * TestRefex.h
 *
 *  Created on: 27.03.2019
 *      Author: eric
 */

#ifndef TESTREGEX_H_
#define TESTREGEX_H_

#define TEST_NO_STRING 10
#include "TestEnum.h"

typedef struct{
	int i;
} TestCaseRegex;


void initializeTestRegex(void);
void runTestRegex(int no, TestCaseRegex test[]);
Test testRegex();

#endif /* TESTREGEX_H_ */
