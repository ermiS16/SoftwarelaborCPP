/*
 * RE.cpp
 *
 *  Created on: 06.04.2019
 *      Author: eric
 */

#include "RE.h"

// Structural comparison among regular expressions
bool equals(RE* r1, RE* r2) {
  bool b;

  if(r1->ofType() != r2->ofType())
     return false;

  switch(r1->ofType()) {
    case PhiType: b = true;
                  break;
    case EpsType: b = true;
                  break;
    case ChType: {
                  Ch* c1 = (Ch*)r1;
                  Ch* c2 = (Ch*) r2;
                  b = c1->getChar() == c2->getChar();
                  break;
    }
   case StarType: {
                   Star* r3 = (Star*) r1;
                   Star* r4 = (Star*) r2;
                   b = equals(r3->getRE(),r4->getRE());
                   break;
   }
  case AltType: {
                 Alt* r3 = (Alt*) r1;
                 Alt* r4 = (Alt*) r2;
                 b = equals(r3->getLeft(),r4->getLeft()) &&
             equals(r3->getRight(), r4->getRight());
                 break;
  }
  case ConcType: {
                 Conc* r3 = (Conc*) r1;
                 Conc* r4 = (Conc*) r2;
                 b = equals(r3->getLeft(),r4->getLeft()) &&
             equals(r3->getRight(), r4->getRight());
                 break;
  }
  }// switch
  return b;
} // equals

// Repeated application of simp until we reach a fixpoint
RE* simpFix(RE* r1) {
  RE* r2 = r1->simp();

  if(equals(r1,r2))
       return r1;

  return simpFix(r2);
}


