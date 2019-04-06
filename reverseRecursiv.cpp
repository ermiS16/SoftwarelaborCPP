/*
 * reverseRecursiv.cpp
 *
 *  Created on: 02.04.2019
 *      Author: eric
 */

#include "reverseRecursive.h"

char *reverseRec(char *s){
	char c;
	if(*s != '\0'){
		c=*s;
		s++;
		reverseRec(s);
	}
	s = putBack(s, c);
	return s;
}

char *putBack(char *s, char c){
	const int n = length(s);
	char *r = new char[n+2];
	copy(s, n, r);
	r[n] = c;
	r[n+1] = '\0';
	return r;
}

void copy(char *s, const int n, char *r){
	int slength = length(s);
	for(int i=0; i<slength;i++){
		r[i] = s[i];
	}
}

int length(char *s){
	int index = 0;
	while(s[index] != '\0'){
		index++;
	}
	return index;
}
