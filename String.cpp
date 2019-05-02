/*
 * String.cpp
 *
 *  Created on: 29.11.2018
 *      Author: Eric
 */

#include "String.h"

	//Default Konstruktor -> Leerer String
	String::String(){
		size = 0;
		str = new char[1];
		str[0] = '\0';

	}
	/*
	 * Char Konstruktor. "String" bestehend aus einem Zeichen.
	 * Speicherplatz für Zeichen und Nullterminal wird reserviert.
	 */
	String::String(char c){
	    size = 1;
	    str = new char[2];
	    str[0] = c;
	    str[1] = '\0';
	}
	/*
	 * String Konstruktor -> Für beliebige Strings
	 * Länge wird bestimmt und dementsprechend Speicherplatz reserviert.
	 * String wird nach hinten hin aufgebaut.
	 */
	String::String(const char *s) {
		int i=0;
		while(s[i] != '\0'){
			i++;
		}
		size = i;
		str = new char[size+1];
		for(int i=0; i<size;i++){
			str[i] = s[i];
		}
		str[size+1] = '\0';
	}

	/*
	 * Kopierkonstruktor -> Kopiert einen String
	 * Es wird die Referenz kopiert.
	 */
	String::String(const String &s) {
		size = s.size;
		str = new char[size+1];
		str = (s.str);
		str[size+1] = '\0';
	}

	/*
	 * Move Konstruktor -> String wird an eine neue Adresse geschoben.
	 * Alte Adresse wird auf Nullptr gesetzt. (Nicht getestet!)
	 */
	String::String(String &&s){
		this->size = s.size;
		this->str = s.str;
		s.str = nullptr;
	}

	/*
	 * Dekonstruktor -> Reservierter Speicherplatz für str wird gelöscht.
	 */
	String::~String() {
		delete[] str;
	}

	/*
	 * Arrayoperator
	 * @return Referenz auf den Inhalt an str[index]
	 * Referenz ist sicherer, da kein Null moeglich ist.
	 */
	char& String::operator[](int index) {
		return this->str[index];
	}

	/*
	 * Copy-Zuweisungsoperator
	 * Wenn Diese und übergebene Referenz ungleich ist,
	 * wird diese Referenz mit der übergebenen "überschrieben"
	 * @return Referenz auf dieses (neue) Stringobjekt
	 */
	String& String::operator=(String &s) {
		int length = 0;

		while(s[length] != '\0'){
			length++;
		}

		if(this != &s){
			delete str;
			str = new char[length+1];
			int index = 0;
			while(index < length){
				str[index] = s[index];
				index++;
			}
			str[index] = '\0';
		}
		return *this;
	}

	/*
	 * Move-Zuweisungsoperator
	 * Diese Referenz ist ungleich mit übergebener Referenz,
	 * wird Diese Referenz mit der übergebenen "überschrieben".
	 * Übergebene Referenz wird "gelöscht"
	 * @return Diese (neue) Referenz auf Stringobjekt
	 */
	String& String::operator=(String &&s){
		if(this != &s){
			delete this->str;
			this->str = s.str;
			s.str = nullptr;
		}
		return *this;
	}

	/*
	 * Konkatenation
	 * Reservieren von Speicher -> Größe beider Strings
	 * Neues Stringobjekt erhält zuerst Inhalt von this-String und
	 * dann den von s-String.
	 * this-str wird neu angelegt und erhält den konkatenierten String
	 * @return neu zusammengesetzer String.
	 *
	 */
	String& String::operator+=(String &s) {
		int newSize = this->size+s.size;
		char *newString = new char[newSize+1];
		int index=0;

		for(int i=0; i<this->size;i++){
			newString[index] = this->str[i];
			index++;
		}

		for(int i=0; i< s.size ;i++){
			newString[index] = s.str[i];
			index++;
		}
		newString[index] = '\0';

		delete str;
		str = new char[newSize];
		str = newString;
		size = newSize;

		return *this;
	}


