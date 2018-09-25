#include "string.h"
#include <iostream>

int main(){
	string stringA;
	string stringB("testContent");
	string stringC(stringB);

	stringA = stringB;
	stringA = "text";

	if (stringC == stringB) {
		std::cout << "Strings have the same content.";
	}
	else {
		std::cout << "Strings have different content.";
	}

	if (stringA == "text") {
		std::cout << "Strings have the same content.";
	}
	else {
		std::cout << "Strings have different content.";
	}

	system("pause");
}