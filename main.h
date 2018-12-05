/*
 * main.h
 *
 *  Created on: 29.11.2018
 *      Author: Eric
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdlib.h>
#include <stdio.h>
#include "String.h"
#include "RE.h"
using namespace std;

int main(void);
void testString(void);
void regex(void);
ostream& operator<< (ostream &out, String &s);

#endif /* MAIN_H_ */
