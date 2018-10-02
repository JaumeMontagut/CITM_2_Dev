#ifndef _STRING
#define _STING

typedef unsigned int uint;

class string {
private:
	char* text;
	uint length;

public:

	//CONSTRUCTORS--------------------

	string() {
		//1.Allocate memory
		length = 1;
		text = new char [length];
		//2.Associate each character
		text[0] = '\0';
	}

	string(const char* text) {
		//1.Allocate memory
		length = CalculateLength(text);
		this->text = new char[length];
		//2.Associate each character
		for (int i = 0; i < length; ++i) {
			this->text[i] = text[i];
		}
	}

	string(const string &otherString) {
		
		//1.Allocate memory
		length = otherString.length;
		text = new char[length];
		//2.Associate each character
		for (int i = 0; i < length; ++i) {
			text[i] = otherString.text[i];
		}
	}

	//OPERATORS-----------------------

	string operator= (const char* otherText) {
		//1. Check if the length is the same
		if (length == CalculateLength(otherText)) {
			//2. Simply change the characters

		}
		else {
			//2. Delete
			//3. Create new with the correct length
			//4. Change the characters
		}
	}

	string operator= (const string &otherString) {

	}

	bool operator== (const char* otherText) {
		//1.Check if the length of the strings is the same
		if (length != CalculateLength(otherText)) {
			return false;
		}
		//2.Check if each character is the same
		for (int i = 0; i < length; ++i) {
			if (text[i] != otherText[i]) {
				return false;
			}
		}
		return true;
	}

	bool operator== (const string &otherString) {
		//1.Check if the length of the strings is the same
		if (length != otherString.length) {
			return false;
		}
		//2.Check if each character is the same
		for (int i = 0; i < length; ++i) {
			if (text[i] != otherString.text[i]) {
				return false;
			}
		}
		return true;
	}

	//METHODS-------------------------

private:
	inline uint CalculateLength(const char* text) {
		uint textLength = 0;
		while (text[textLength] != '\0') {
			textLength++;
		}
		return textLength;
	}
};

#endif