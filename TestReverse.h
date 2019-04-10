/*
 * TestReverse.h
 *
 *  Created on: 08.04.2019
 *      Author: eric
 */

#ifndef TESTREVERSE_H_
#define TESTREVERSE_H_

#include "TestEnum.h"
#include "String.h"

typedef struct{
	char *input;
	char *expected;
} TestCaseReverseRecursive;

#define NO_TEST_REVERSE 3

void initializeReverseTestRecursive();
void runTestReverseRecusive(int no, TestCaseReverseRecursive test[]);
Test testReverseRecursive(char *input, char *expected);

#endif /* TESTREVERSE_H_ */
