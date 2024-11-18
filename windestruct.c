#include <stdio.h>
#include <Windows.h>
#include "winfunctions.h"

void destruct() {

	printf("%s","\nThis message will self destruct in 10 seconds...\n");
	printf("%s","I would remember anything important here.\n");
	Sleep(10000);
}
