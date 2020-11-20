#ifndef FNS_H // file guards so there libraries and definitions
	      // are only included once
#define FNS_H

// Libraries
#include <stdio.h>  // for I/O (printf(), scanf(), fgets(), FILE)
#include <string.h> // for strtok() strcmp() and strcpy()
#include <stdlib.h> // used for malloc and exit()

// Constants
#define STR_LEN 60	// string length constant
#define NUM_CLASSES 20 	// <- only 15 required but I went overboard

// Structures
typedef struct {
	char title[STR_LEN/3];		// title string
	char class_name[STR_LEN];	// class name string
	char professor[STR_LEN];	// professor name string
	char times[STR_LEN/3];		// times string
	// integer variables for seat numbers and the crn
	int crn, seats_total, seats_taken, seats_remaining;
} CSCICLASS;

// Functions
void init(CSCICLASS* structure); // initializes a CSCICLASS to default values
void read_classes(FILE* in, CSCICLASS classes[NUM_CLASSES]); // reads in CSCICLASS(es) from an input file
void display(CSCICLASS structure); // displays relevant data from a CSCICLASS
void search(CSCICLASS classes[NUM_CLASSES], char mode); // Searches through an array of CSCICLASSES to display certain classes

#endif
