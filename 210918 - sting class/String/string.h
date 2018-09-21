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

	bool operator== (string otherString){
		return(text == otherString.text);
	}

	string operator= (string otherString) {
		text = otherString.text;
		return *this;
	}

	string operator= (const char* otherText) {
		this->text = (char*)otherText;
		return *this;
	}

	//Try for in every letter if this doesn't work

	//METHODS-------------------------

};

#endif