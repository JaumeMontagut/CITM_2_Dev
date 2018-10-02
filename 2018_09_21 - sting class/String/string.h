#ifndef _STRING
#define _STING

typedef unsigned int uint;

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class string {
private:
	char* text;
	uint length;

public:
	//CONSTRUCTORS--------------------

	string() {
	}

	string(const char* text) {
		//1.Allocate memory
		//  - Calculate the length of the passed string
		length = 0;
		while (text[length] != '/0') {
			length++;
		}
		//  - Allocate memory
		this->text = new char[length];
		//2.Associate each character
		for (int i = 0; i < length; ++i) {
			this->text[i] = text[i];
		}
	}

	string(const string &otherString) {
		
		//1.Allocate memory
		text = new char[strlen(otherString.text)];
		//2.Associate each character
		for (int i = 0; i < strlen(otherString.text); ++i) {
			text[i] = otherString.text[i];
		}
	}

	//OPERATORS-----------------------

	string operator= (const string &otherString) {

	}

	string operator= (const char* otherText) {

	}

	bool operator== (const string &otherString) {
		//1- Check if the length of the strings is the same
		if (strlen(text) != strlen(otherString.text)) {
			return false;
		}
		for (int i = 0; i < strlen(text); ++i) {
			if (text[i] != otherString.text[i]) {
				return false;
			}
		}
		return true;
	}

	bool operator== (const char* otherText) {

	}

	//METHODS-------------------------
	//(section to add methods)
};

#endif