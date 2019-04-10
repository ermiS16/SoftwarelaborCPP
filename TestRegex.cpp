/*
 * TestRegex.cpp
 *
 *  Created on: 27.03.2019
 *      Author: eric
 */
//#include "TestRegex.h"

#include "TestRegex.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>



void regex(void){
	  //eps r
	  RE* r8 = new Conc(new Eps(), new Ch('C'));
	  //r eps
	  RE* r9 = new Conc(new Ch('C'), new Eps());

	  cout << "Rule: 1:" << endl;
	  cout << r8->pretty();
	  cout << " ==> " << r8->simp()->pretty() << endl;
	  cout << r9->pretty();
	  cout << " ==> " << r9->simp()->pretty() << endl;
	  cout << endl;

	  //r1 r2
	  RE* r10 = new Conc(new Ch('C'), new Phi());
	  RE* r11 = new Conc(new Phi(), new Ch('C'));

	  cout << "Rule 2: " << endl;
	  cout << r10->pretty();
	  cout << " ==> " << r10->simp()->pretty() << endl;
	  cout << r11->pretty();
	  cout << " ==> " << r11->simp()->pretty() << endl;
	  cout << endl;

	  // phi*
	  RE* r6 = new Star(new Phi());

	  cout << "Rule 3: " << endl;
	  cout << r6->pretty();
	  cout << " ==> " << r6->simp()->pretty() << endl;
	  cout << endl;

	// c**
	  RE* r5 = new Star(new Star (new Ch('c')));

	  cout << "Rule 4:" << endl;
	  cout << r5->pretty();
	  cout << " ==> " << r5->simp()->pretty() << endl;
	  cout << endl;

	  //r + r
	  RE* r13 = new Ch('c');
	  RE* r14 = new Alt(r13, r13);

	  cout << "Rule 5: " << endl;
	  cout << r14->pretty();
	  cout << " ==> " << r14->simp()->pretty() << endl;	  cout << endl;

	  // phi + c
	  RE* r3 = new Alt (new Phi(), new Ch('c'));
	  // c + phi
	  RE* r4 = new Alt (new Ch('c'), new Phi());
	  cout << "Rule 6 & 7:" << endl;
	  cout << r3->pretty();
	  cout << " ==> " << r3->simp()->pretty() << endl;
	  cout << r4->pretty();
	  cout << " ==> " << r3->simp()->pretty() << endl;
	  cout << endl;

	  // (phi + c) + c**
	  RE* r7 = new Alt(r3,r5);
	  cout << "Rule 7 & 4:" << endl;
	  cout << r7->pretty();
	  // exhaustively apply simplifications
	  cout << " ==> " << simpFix(r7)->pretty() << endl;
	  cout << endl;

	  //eps ((a*)* (phi + b))
	  RE* r12 = new Conc(new Eps(), new Conc(new Star(new Ch('a')), new Alt(new Phi(), new Ch('b'))));
	  cout << "Complex Example: " << endl;
	  cout << r12->pretty();
	  cout << " ==> " << r12->simp()->pretty() << endl;
	  cout << endl;

}

void initializeTestRegex(void){
	// phi*
	RE* r3 = new Star(new Phi());
	RE* r31 = new Star(new Ch('c'));

	// c**
	RE* r4 = new Star(new Star (new Ch('c')));
	RE* r41 = new Ch('a');
	RE* r42 = new Ch('b');

	// phi + c
	RE* r6 = new Alt (new Phi(), new Ch('c'));
	// c + phi
	RE* r7 = new Alt (new Ch('c'), new Phi());

	// (phi + c) + c**
	RE* r8 = new Alt(r6,r4);

	//eps r
	RE* r9 = new Conc(new Eps(), new Ch('c'));
	//r eps
	RE* r10 = new Conc(new Ch('c'), new Eps());

	//r1 r2
	RE* r11 = new Conc(new Ch('c'), new Phi());
	RE* r12 = new Conc(new Phi(), new Ch('c'));

	//eps ((a*)* (phi + b))
	RE* r15 = new Conc(new Eps(), new Conc(new Star(new Ch('a')), new Alt(new Phi(), new Ch('b'))));

	//r + r
	RE* r16 = new Ch('c');
	RE* r17 = new Alt(r16, r16);

	TestCaseRegex test[] = {{r3,simpFix(r3), "c", true},								// 	1
							{r3,simpFix(r31), "c", false},								// 	2
							{r4,simpFix(r4), "c", true},								// 	3
							{r4,simpFix(r4), simpFix(r4)->pretty().c_str(), true},		// 	4
							{r41,simpFix(r42),"a", false},								// 	5
							{r4,simpFix(r4), simpFix(r4)->pretty().c_str(), true},		// 	6
							{r6,simpFix(r6), "c", true},								// 	7
							{r6,simpFix(r42), "c", false},								// 	8
							{r6,simpFix(r6),  simpFix(r6)->pretty().c_str(), true},		// 	9
							{r7,simpFix(r7), "c", true},								// 10
							{r8,simpFix(r8), "c", true},								// 11
							{r8,simpFix(r42), "c", false},								// 12
							{r8,simpFix(r8), simpFix(r8)->pretty().c_str(), true},		// 13
							{r9,simpFix(r9), "c", true},								// 14
							{r10,simpFix(r10), "c", true},								// 15
							{r10,simpFix(r42), "c", false},								// 16
							{r10,simpFix(r10), simpFix(r10)->pretty().c_str(), true},	// 17
							{r11,simpFix(r11), "c", true},								// 18
							{r11,simpFix(r42), "b", false},								// 19
							{r11,simpFix(r11), simpFix(r11)->pretty().c_str(), true},	// 20
							{r12,simpFix(r12), "c", true},								// 21
							{r15,simpFix(r15), "c", true},								// 22
							{r17,simpFix(r17), "c", true},								// 23
							{r17,simpFix(r42), "c", false},								// 24
							{r17,simpFix(r17), simpFix(r17)->pretty().c_str(), true}	// 25
	};
		runTestRegex(TEST_NO_REGEX, test);

}


void runTestRegex(int no, TestCaseRegex test[]){
	Test t=FAIL;
	for(int i=0; i<no; i++){
		cout << "Test " << i+1 << ": " << endl;
		t = testRegex(test[i].r, test[i].simpR, test[i].w, test[i].expected);
		if(t){
			cout << "Test OK" << endl;
		}else{
			cout << "Test Fail" << endl;
		}
			cout << "\n" << endl;
	}
}

Test testRegex(RE* r, RE* simpR, const char* c, bool expected){
	Test t = FAIL;
	bool result = orakel(r, simpR, c);
	if(result == expected){
		t=OK;
	}
	else{
		t=FAIL;
	}
	cout << "RE: " << r->pretty() << endl;
	cout << "RE Simp: " << simpR->pretty() << endl;
	cout << "word: " << c << endl;
	cout << "Orakel: " << result << endl;
	cout << "Expected: " << expected << endl;
	return t;
}


RE* deriv(RE* r, char l) {

  switch(r->ofType()) {
  case PhiType:
    return r;
  case EpsType:
    return new Phi();
  case ChType:
    if (((Ch*)r)->getChar() == l) {
      return new Eps();
    }
    else {
      return new Phi();
    }
  case StarType: {
    RE* r1 = ((Star*) r)->getRE();
    return new Conc(deriv(r1,l),r);
  }
  case AltType: {
    RE* r1 = ((Alt*) r)->getLeft();
    RE* r2 = ((Alt*) r)->getRight();
    return new Alt(deriv(r1,l), deriv(r2,l));
  }
  case ConcType: {
    RE* r1 = ((Conc*)r)->getLeft();
    RE* r2 = ((Conc*)r)->getRight();
    if(r1->containsEps()) {
      return new Alt(new Conc(deriv(r1,l),r2), deriv(r2,l));
    }
    else {
      return new Conc(deriv(r1,l),r2);
    }
  }
  default: return r;
  }// switch

}

bool match(RE* r, string s) {
  for(int i=0; i < (signed) s.length(); i++) {
    r = deriv(r, s[i]);
  }
  return r->containsEps();
}

bool orakel(RE* r, RE* rSimp, string s) {
    return (match(r,s) == match(rSimp,s));
}
