#include "string.h"
#include <stdio.h>

int main(){
	string stringA;
	string stringB("testContent");
	string stringC(stringB);

	stringA = stringB;
	stringA = "text";

	char* stringD = new char[3];
	stringD[0] = 'a';
	stringD[1] = 'u';
	stringD[2] = '\0';

	printf("StringC: %s", stringD);

	if (stringC == stringB) {
		printf("Strings have the same content.\n");
	}
	else {
		printf("Strings have different content.\n");
	}

	if (stringB == "testContent") {
		printf("Strings have the same content.\n");
	}
	else {
		printf("Strings have different content.\n");
	}

	getchar();
}