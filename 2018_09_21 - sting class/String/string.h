#ifndef _STRING
#define _STING

#include <stdio.h>

typedef unsigned int uint;

class string {
private:
	char* text;
	uint length;

public:

	//CONSTRUCTORS--------------------

	string() {
		length = 1;
		text = new char [length];
		//text[0] = '\0';
	}

	string(const char* otherText) {
		length = CalculateLength(otherText);
		text = new char[length];
		text = AssociateCharacters(otherText, length);
	}

	string(const string &otherString) {
		length = otherString.length;
		text = new char[length];
		text = AssociateCharacters(otherString.text, length);
	}


	//OPERATORS-----------------------

	string operator= (const char* otherText) {
		uint otherLength = CalculateLength(otherText);
		if (length == otherLength) {
			text = AssociateCharacters(otherText);
		}
		else {
			delete(text);
			length = otherLength;
			text = new char [otherLength];
			text = AssociateCharacters(otherText, length);
		}
		return *this;
	}

	string operator= (const string &otherString) {
		if (length == otherString.length) {
			text = AssociateCharacters(otherString.text, otherString.length);
		}
		else {
			delete(text);
			length = otherString.length;
			text = new char[length];
			text = AssociateCharacters(otherString.text, length);
		}
		return *this;
	}

	bool operator== (const char* otherText) {
		if (length != CalculateLength(otherText)) {
			return false;
		}
		for (int i = 0; i < length; ++i) {
			if (text[i] != otherText[i]) {
				return false;
			}
		}
		return true;
	}

	bool operator== (const string &otherString) {
		if (length != otherString.length) {
			return false;
		}
		for (int i = 0; i < length; ++i) {
			if (text[i] != otherString.text[i]) {
				return false;
			}
		}
		return true;
	}


	//METHODS-------------------------

	void print() {
		for (int i = 0; i < length; ++i) {
			printf_s("%c", text[i]);
		}
	}


private:

	uint CalculateLength(const char* text) {
		uint textLength = 0;
		while (text[textLength] != '\0') {
			textLength++;
		}
		return textLength;
	}

	char* AssociateCharacters(const char * otherText, uint otherLength = 0) {
		//- We check if otherLength has not been set
		if (otherLength == 0) {
			otherLength = CalculateLength(otherText);
		}
		//- We associate each character
		char* retText = new char[otherLength];
		for (int i = 0; i < otherLength; ++i) {
			retText[i] = otherText[i];
		}
		return retText;
	}

};

#endif