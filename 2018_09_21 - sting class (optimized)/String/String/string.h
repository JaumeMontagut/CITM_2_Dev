#ifndef _STRING
#define _STING

#define LAST_DIGIT '\0'

#include <stdio.h>
#include <assert.h>

typedef unsigned int uint;

class string {
private:
	char* text = nullptr;
	//The number of characters in text. We don't include the last digit ('\0') in this number.
	int length = -1;

public:

	//CONSTRUCTORS--------------------

	string() {
		AllocateToThis(0);
		text[0] = LAST_DIGIT;
	}

	string(const char* otherText) {
		AllocateToThis(CalculateLength(otherText));
		AssignCharacters(otherText, text, length);
	}

	string(const string &otherString) {
		AllocateToThis(otherString.length);
		AssignCharacters(otherString.text, text, length);
	}

	~string() {
		assert(text);
		if (text == nullptr) {
			delete[] text;
			text = nullptr;
			length = -1;
		};
	}


	//OPERATORS-----------------------

	string operator= (const char* otherText) {
		uint otherLength = CalculateLength(otherText);
		if (length == otherLength) {
			AssignCharacters(otherText, text, length);
		}
		else {
			delete[] text;
			AllocateToThis(otherLength);
			AssignCharacters(otherText, text, length);
		}
		return *this;
		<<<<<< < HEAD
	}

	string operator= (const string &otherString) {
		if (length == otherString.length) {
			AssignCharacters(otherString.text, text, length);
		}
		else {
			delete[] text;
			AllocateToThis(otherString.length);
			AssignCharacters(otherString.text, text, length);
		}
		return *this;
	}

	//operator char * () {
	//	return text;
	//}

	//operator string () {
	//	return text;
	//}

	//char* operator%s() {
	//	return text;
	//}

	string operator= (const string &otherString) {
		if (length == otherString.length) {
			AssignCharacters(otherString.text, text, length);
		}
		else {
			delete[] text;
			AllocateToThis(otherString.length);
			AssignCharacters(otherString.text, text, length);
		}
		return *this;
	}

	string operator+= (const char* otherText) {
		delete[] text;
		AllocateToThis(length + CalculateLength(otherText));
		AssignCharacters(, text, length);
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

	bool operator== (const string &otherString) const {
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

	char * GetText() {
		return text;
	}

	void print() const {
		printf("%s", text);
	}

	uint GetAllocatedMemory(const string& string)const {
		return string.length + 1;
	}


private:

	//INFO: Returns -1 when entering invalid memory
	int CalculateLength(const char* text) {
		assert(text);
		if (text == nullptr) { return -1; }

		uint textLength = 0;
		while (text[textLength] != LAST_DIGIT) {
			textLength++;
		}
		return textLength;
	}

	inline void AllocateToThis(uint charactersInSentence) {
		length = charactersInSentence;
		//INFO: We need to add + 1 because we'll have a character at the end, LAST_DIGIT('\0'), which indicates the end of the string
		text = new char[length + 1];
	}

	//INFO: This function assumes you've already allocated memory for toText
	//INFO: This function assumes that the text you want to copy from (fromText) and the one you want to copy to (toText) are of the same length
	void AssignCharacters(const char * fromText, char* toText, int textLength = -1) {
		if (textLength == -1) {
			textLength = CalculateLength(fromText);
		}
		//INFO: We want to fill the array up to the penultimate position, as the last will be LAST_DIGIT('\0').
		for (int i = 0; i < textLength; ++i) {
			toText[i] = fromText[i];
		}
		toText[textLength] = LAST_DIGIT;
	}

	void Concatenate(const char* text1, int length1, const char* text2, int length2) {
		int i = 0;
		for (; i < length1; ++i) {
			text[i] = text1[i];
		}
		for (; i < length1 + length2; ++i) {
			text[i] = text2[i - length1];
		}
		text[length1 + length2] = LAST_DIGIT;
	}

};

#endif