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
		text = otherString.text;
	}

	string(const char* text) {
		this->text = (char*)text;
	}

	//OPERATORS-----------------------

	string operator= (const string &otherString) {
		text = otherString.text;
		return *this;
	}

	string operator= (const char* otherText) {
		text = (char*)otherText;
		return *this;
	}

	bool operator== (const string &otherString) {
		return(text == otherString.text);
	}

	bool operator== (const char* otherText) {
		return(text == otherText);
	}

	//METHODS-------------------------
	//(section to add methods)
};

#endif