/*
 * TestReverse.cpp
 *
 *  Created on: 08.04.2019
 *      Author: eric
 */


#include "TestReverse.h"
#include "reverseRecursive.h"

void  initializeReverseTestRecursive(){
	char s1[] = "Hallo";
	char s1e[] = "ollaH";
	char s2[] = "12345";
	char s2e[] = "54321";
	char s3[] = "Hallo Welt";
	char s3e[] = "tlew ollaH";
	TestCaseReverseRecursive test[] = {
			{s1,s1e},
			{s2,s2e},
			{s3,s3e}
	};

	runTestReverseRecusive(NO_TEST_REVERSE, test);

}

void runTestReverseRecusive(int no, TestCaseReverseRecursive test[]){
	Test t = FAIL;
	for(int i=0; i<no; i++){
		cout << "Test " << i+1 << ": " << endl;
		t = testReverseRecursive(test[i].input, test[i].expected);
		if(t==OK){
			cout << "Test: OK" << endl;
		}else{
			cout << "Test: FAIL" << endl;
		}
		cout << endl;
	}
}

Test testReverseRecursive(char *input, char *expected){
	Test t=FAIL;
	int index = 0;
	char *result = reverseRec(input);
	while(result[index] != '\0' && expected[index] != '\0'){
		if(result[index] == expected[index]){
			t=OK;
		}else{
			t=FAIL;
		}
		index++;
	}
	cout << "Input: " << input << endl;
	cout << "Reverse: " << result << endl;
	cout << "Expected: " << expected << endl;

	return t;
}
