#include <stdio.h>
#include "functions.h"

void goodJoke() {

	printf("%s", "\nHere are some wise words, you\'ve earned it:\n");
	
	char var1[8] = {'\150','\141','\143','\153','\100','\165','\143','\146'};
	
	char var2[8] = {'\173','\062','\102','\145','\145','\040','\174','\174'};

	char var3[9] = {'\040','\041','\050','\062','\102','\145','\145','\051','\175'};

	for (int i = 0; i < 8; i++) {
		printf("%c",var1[i]);
	}

	for (int i = 0; i < 8; i++) {
		printf("%c", var2[i]);
	}

	for (int i = 0; i < 9; i++) {
		printf("%c", var3[i]);
	}

	printf("%s","\n");
}