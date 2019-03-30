/*
 * main.cpp
 *
 *  Created on: 29.11.2018
 *      Author: Eric
 */

#include "main.h"
//#include "RE.h"
#include "TestRegex.h"
#include "StringTest.h"

int main(void){
	cout << "Start Test Regex" << endl;
	cout << endl;
	initializeTestRegex();
	testRegex();
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
