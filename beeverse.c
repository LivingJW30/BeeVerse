#include <stdio.h>
#include <string.h>
#include "functions.h"

#define ATTEMPTS 3
#define MAX 100000

int main(void) {

	char joke[MAX];

	printf("   888                      \n");
	printf("   888                      \n");
	printf("   888                      \n");
	printf("   88888b.  .d88b.  .d88b.  \n");
	printf("   888 \"88bd8P  Y8bd8P  Y8b \n");
	printf("   888  8888888888888888888 \n");
	printf("   888 d88PY8b.    Y8b.     \n");
	printf("   88888P\"  \"Y8888  \"Y8888  \n");

	printf("%s","\n----------------------------------\n");
	printf("%s","Tell me a joke that makes me laugh.\n");
	printf("%s","-----------------------------------\n");

	for (int i = ATTEMPTS; i>0 ; i--) {

		printf("You have %d attempts left:",i);

		if (fgets(joke, sizeof(joke), stdin) != NULL) {

			joke[strcspn(joke, "\n")] = '\0';

			if (strcmp(joke, '\150') == 0) {

				goodJoke();
				buzzin();
				exit();
			}
			else {
				printf("That wasnt funny...\n");
			}
		}
		else {
			printf("%s","ERROR READING STRING\n");
		}
	}

	printf("%s","\nYou arent allowed here. LEAVE!\n");

	return 0;
}