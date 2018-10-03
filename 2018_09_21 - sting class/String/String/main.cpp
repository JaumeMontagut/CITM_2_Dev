#include "string.h"
#include <stdio.h>

int main() {
	string stringA;
	string stringB("testContent");
	string stringC(stringB);

	stringA = stringB;
	stringA = "text";

	printf("StringB: %s \n", stringB);

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