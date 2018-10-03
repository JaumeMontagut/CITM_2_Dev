#include "string.h"
#include <stdio.h>

int main() {
	string stringA;
	string stringB("testContent");
	string stringC(stringB);

	stringA = stringB;
	stringA = "text";

	printf_s("StringB: %s \n", stringB);//Only on x86
	//printf_s("StringB: %s \n", stringB.GetText());//On x86 & x64

	stringB.print();
	printf("\n");

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