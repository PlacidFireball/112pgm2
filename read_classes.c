#include "fns.h"

// Constants
#define BUFFER_LEN 100
#define DEFAULT_STR " "

// Sets default values of the CSCICLASS
void init(CSCICLASS* structure) { 	// <- takes a pointer to a CSCICLASS and sets default values
	strcpy(structure->title, DEFAULT_STR);
	strcpy(structure->class_name, DEFAULT_STR);
	structure->crn = 0;
	structure->seats_total = 0;
	structure->seats_taken = 0;
	structure->seats_remaining = 0;
	strcpy(structure->professor, DEFAULT_STR);
	strcpy(structure->times, DEFAULT_STR);
}

// Reads in data from a file
void read_classes(FILE* in, CSCICLASS arr[NUM_CLASSES]) {
	char buffer[BUFFER_LEN]; 	// buffer
	const char delim[2] = ","; 	// delimiter
	char* token;
	int i = 0;
	while(fgets(buffer, BUFFER_LEN, in) != NULL) { 	// read a line from the input file, storing it in the buffer
		token = strtok(buffer, delim);
		strcpy(arr[i].title, token); 		// set title

		token = strtok(NULL, delim);
		strcpy(arr[i].class_name, token); 	// set class name

		token = strtok(NULL, delim);
		arr[i].crn = atoi(token); 		// set crn

		token = strtok(NULL, delim);
		arr[i].seats_total = atoi(token); 	// set the seats values

		token = strtok(NULL, delim);
		arr[i].seats_taken = atoi(token); 	// ...

		token = strtok(NULL, delim);
		arr[i].seats_remaining = atoi(token); 	// ...

		token = strtok(NULL, delim);
		strcpy(arr[i].professor, token); 	// get the professor's name

		token = strtok(NULL, delim);
		strcpy(arr[i].times, token); 		// get the times for the class
		i++; 	// increment i while fgets is still reading something
	}
}
