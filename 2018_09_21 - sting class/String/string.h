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
		for (int i = 0; i < strlen(otherString.text); ++i) {
			text[i] = otherString.text[i];
		}
	}

	string(const char* text) {
		this->text = new char[strlen(text)];
		for (int i = 0; i < strlen(text); ++i) {
			this->text[i] = text[i];
		}
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