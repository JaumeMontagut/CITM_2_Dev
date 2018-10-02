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

	string(const char* otherText) {
		//1.Allocate memory
		length = CalculateLength(otherText);
		text = new char[length];
		//2.Associate each character
		text = AssociateCharacters(otherText, length);
	}

	string(const string &otherString) {
		
		//1.Allocate memory
		length = otherString.length;
		text = new char[length];
		//2.Associate each character
		text = AssociateCharacters(otherString.text, length);
	}


	//OPERATORS-----------------------

	string operator= (const char* otherText) {
		//1. Check if the length is the same
		uint otherLength = CalculateLength(otherText);
		if (length == otherLength) {
			//2. Simply change the characters
			text = AssociateCharacters(otherText);
		}
		else {
			//2. Delete
			delete(text);
			//3. Create new with the correct length
			text = new char [otherLength];
			//4. Change the characters
			text = AssociateCharacters(otherText);
		}
	}

	string operator= (const string &otherString) {
		//1. Check if the length is the same
		if (length == otherString.length) {
			//2. Simply change the characters
			text = AssociateCharacters(otherString.text, otherString.length);
		}
		else {
			//2. Delete
			delete(text);
			//3. Create new with the correct length
			text = new char[otherString.length];
			//4. Change the characters
			text = AssociateCharacters(otherString.text, otherString.length);
		}
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

	uint CalculateLength(const char* text) {
		uint textLength = 0;
		while (text[textLength] != '\0') {
			textLength++;
		}
		return textLength;
	}

	char* AssociateCharacters(const char * otherText, uint otherLength = 0) {
		//We check if other length has not been set
		if (otherLength == 0) {
			otherLength = CalculateLength(otherText);
		}
		//We associate each character to a new char*
		char* retText = new char[otherLength];
		for (int i = 0; i < otherLength; ++i) {
			retText[i] = otherText[i];
		}
		return retText;
	}

};

#endif