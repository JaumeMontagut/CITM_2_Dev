#ifndef _STRING
#define _STING

class string {
private:
	char* text;

public:
	//CONSTRUCTORS--------------------

	string() {
	}

	string(const string &otherString) {
		text = new char[sizeof(otherString.text)];
		for (int i = 0; i < sizeof(otherString.text); i++) {
			text[i] = otherString.text[i];
		}
	}

	string(const char* text) {
		this->text = new char[sizeof(text)];
		for (int i = 0; i < sizeof(text); i++) {
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