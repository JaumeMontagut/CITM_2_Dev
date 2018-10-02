#ifndef _STRING
#define _STING

typedef unsigned int uint;

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

class string {
private:
	char* text;

public:
	//CONSTRUCTORS--------------------

	string() {
	}

	string(const string &otherString) {
		text = new char[strlen(otherString.text)];
		strcpy_s(text, strlen(otherString.text), otherString.text);
	}

	string(const char* text) {
		this->text = new char[strlen(text)];
		strcpy_s(this->text, strlen(text), text);
	}

	//OPERATORS-----------------------

	string operator= (const string &otherString) {

	}

	string operator= (const char* otherText) {

	}

	bool operator== (const string &otherString) {

	}

	bool operator== (const char* otherText) {

	}

	//METHODS-------------------------
	//(section to add methods)
};

#endif