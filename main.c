/*
CSCI 112 - Program 2
Code Written by: Jared Weiss
Finished on November 2, 2020
*/

#include "fns.h"

int main(void) {
	/* Setup And Error Checking */
	FILE* in;
	CSCICLASS arr[NUM_CLASSES];
	for (int i = 0; i < NUM_CLASSES; i++) {
		init(&arr[i]); 	// for each element, initialize default values
	}
	in = fopen("classes.csv", "r"); 	// open the file
	if (in == NULL) { // error handling
		printf("ERROR | Could not open input file at specified directory! Exiting...\n");
		exit(1);
	}

	/* Read in the data */
	read_classes(in, arr);
	// long display string
	const char* choice_str = "n - print class given number\nd - print all classes for a given day combo\np - print all classes for a given professor\nq - quit\n";

	/* Main loop */
	char read = 'a';	// user input variable
	printf("| Choices:\n%s", choice_str);
	while (!(read == 'q' || read == 'Q')) {
		scanf("%c%*c", &read); 	// read in the choice and discard the newline character
		search(arr, read);	// search the array based on the user's choice
		// gracefully exit if q is entered, otherwise continue on
		(read == 'q' || read == 'Q') ? printf("| Quiting...\n") : printf("| Choices:\n%s", choice_str);
	}
	return 0;
}
