#ifndef _STRING
#define _STING

#define LAST_DIGIT '\0'

#include <stdio.h>

typedef unsigned int uint;

class string {
private:
	char* text;
	//The number of characters in the word or sentence. We don't include the last digit ('\0') in this number.
	uint length;

public:

	//CONSTRUCTORS--------------------

	string() {
		AllocateToThis(0);
		text[0] = LAST_DIGIT;
	}

	string(const char* otherText) {
		AllocateToThis(CalculateLength(otherText));
		AssociateCharacters(otherText, text, length);
	}

	string(const string &otherString) {
		AllocateToThis(otherString.length);
		AssociateCharacters(otherString.text, text, length);
	}


	//OPERATORS-----------------------

	string operator= (const char* otherText) {
		uint otherLength = CalculateLength(otherText);
		if (length == otherLength) {
			AssociateCharacters(otherText, text, length);
		}
		else {
			delete(text);
			AllocateToThis(otherLength);
			AssociateCharacters(otherText, text, length);
		}
		return *this;
	}

	string operator= (const string &otherString) {
		if (length == otherString.length) {
			AssociateCharacters(otherString.text, text, length);
		}
		else {
			delete(text);
			AllocateToThis(otherString.length);
			AssociateCharacters(otherString.text, text, length);
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
		while (text[textLength] != LAST_DIGIT) {
			textLength++;
		}
		return textLength;
	}

	//We allocate memory for the text of this instance
	void AllocateToThis(const uint &charactersInSentence){
		length = charactersInSentence;
		//INFO: We need to add + 1 because we'll have a character at the end, LAST_DIGIT('\0'), which indicates the end of the string
		text = new char[length + 1];
	}

	//INFO: This function assumes you've already allocated memory for toText
	//INFO: This function assumes that the text you want to copy from (fromText) and the one you want to copy to (toText) are of the same length
	void AssociateCharacters(const char * fromText, char* toText, uint textLength = 0) {
		if (textLength == 0) {
			textLength = CalculateLength(fromText);
		}
		//INFO: We want to fill the array up to the penultimate position, as the last will be LAST_DIGIT('\0').
		for (int i = 0; i < textLength; ++i) {
			toText[i] = fromText[i];
		}
		toText[textLength] = LAST_DIGIT;
	}

};

#endif