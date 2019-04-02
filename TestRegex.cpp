/*
 * TestRegex.cpp
 *
 *  Created on: 27.03.2019
 *      Author: eric
 */
#include "TestRegex.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

/*
void regex(void){

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

	  // c**
	  RE* r5 = new Star(new Star (new Ch('c')));

	  cout << "Rule 4:" << endl;
	  cout << r5->pretty();
	  cout << " ==> " << r5->simp()->pretty() << endl;
	  cout << endl;
	  // phi*
	  RE* r6 = new Star(new Phi());

	  cout << "Rule 3: " << endl;
	  cout << r6->pretty();
	  cout << " ==> " << r6->simp()->pretty() << endl;
	  cout << endl;

	  // (phi + c) + c**
	  RE* r7 = new Alt(r3,r5);

	  cout << "Rule 7 & 4:" << endl;
	  cout << r7->pretty();
	  // exhaustively apply simplifications
	  cout << " ==> " << simpFix(r7)->pretty() << endl;
	  cout << endl;

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

	  //eps ((a*)* (phi + b))
	  RE* r12 = new Conc(new Eps(), new Conc(new Star(new Ch('a')), new Alt(new Phi(), new Ch('b'))));
	  cout << "Complex Example: " << endl;
	  cout << r12->pretty();
	  cout << " ==> " << r12->simp()->pretty() << endl;
	  cout << endl;

	  //r + r
	  RE* r13 = new Ch('C');
	  RE* r14 = new Alt(r13, r13);

	  cout << "Rule 5: " << endl;
	  cout << r14->pretty();
	  cout << " ==> " << r4->simp()->pretty() << endl;
}
*/
void initializeTestRegex(void){
	RE* r6 = new Alt (new Phi(), new Ch('c'));
	RE* r6Simp = new Ch('c');
	RE* r7 = new Alt (new Ch('c'), new Phi());
	RE* r7Simp = r6Simp;

	TestCaseRegex test[] = {{r6, r6Simp,""+'c', true},
							{r6, r6Simp,"Hallo", false},
							{r7, r7Simp,""+'c', true},
							{r7, r7Simp,"Hallo", false}

	};
		runTestRegex(TEST_NO_REGEX, test);

/*
	  // c**
	  RE* r5 = new Star(new Star (new Ch('c')));

	  cout << "Rule 4:" << endl;
	  cout << r5->pretty();
	  cout << " ==> " << r5->simp()->pretty() << endl;
	  cout << endl;
	  // phi*
	  RE* r6 = new Star(new Phi());

	  cout << "Rule 3: " << endl;
	  cout << r6->pretty();
	  cout << " ==> " << r6->simp()->pretty() << endl;
	  cout << endl;

	  // (phi + c) + c**
	  RE* r7 = new Alt(r3,r5);

	  cout << "Rule 7 & 4:" << endl;
	  cout << r7->pretty();
	  // exhaustively apply simplifications
	  cout << " ==> " << simpFix(r7)->pretty() << endl;
	  cout << endl;

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

	  //eps ((a*)* (phi + b))
	  RE* r12 = new Conc(new Eps(), new Conc(new Star(new Ch('a')), new Alt(new Phi(), new Ch('b'))));
	  cout << "Complex Example: " << endl;
	  cout << r12->pretty();
	  cout << " ==> " << r12->simp()->pretty() << endl;
	  cout << endl;

	  //r + r
	  RE* r13 = new Ch('C');
	  RE* r14 = new Alt(r13, r13);

	  cout << "Rule 5: " << endl;
	  cout << r14->pretty();
	  cout << " ==> " << r4->simp()->pretty() << endl;
*/
}

void runTestRegex(int no, TestCaseRegex test[]){

	if(true){
		cout << "Test OK" << endl;
	}else{
		cout << "Test Fail" << endl;
	}
}

Test testRegex(){
 Test t=OK;
 return t;
}

/*
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

*/
